#include "mainwindow.h"
#include "qnetworkaccessmanager.h"
#include "ui_mainwindow.h"
#include <QSslSocket>
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QTime>
#include <QString>
#include <QStandardPaths>
#include <QFileInfo>
#include <QDesktopServices>
#include <QMessageBox>
#include <QTemporaryFile>
#include <QProcess>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , manager(nullptr)
    , reply(nullptr)
    , file(nullptr)
    , url()
    , isPaused(false)
    , isDownloading(false)
    , bytesAlreadyWritten(0)
    , expectedTotalBytes(0)
    , isCancelling(false)
    , trayIcon(nullptr)
    , m_isDragging(false)
    , historyurl()
{
    ui->setupUi(this);
    
    //构建一个QNetworkAccessManager对象，通过这个对象实现各种请求
    manager = new QNetworkAccessManager(this);
    
    //未下载时先隐藏进度条
    ui->progressBar->hide();
    
    setWindowTitle("MyDownloader");
    setWindowIcon(QIcon(":/icon.png"));
    // 确保窗口显示在任务栏
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    
    // 设置问候语
    QTime time = QTime::currentTime();
    QString greet = time.toString("AP");
    if(greet == "AM"){
        ui->greetlb->setText("Good Morning :-)");
    }
    else if(greet == "PM"){
        ui->greetlb->setText("Good Afternoon :-)");
    }

    // stats timer setup
    connect(&statsTimer, &QTimer::timeout, this, &MainWindow::statsTick);
    statsTimer.setInterval(1000);

    // tray icon for notifications
    if (QSystemTrayIcon::isSystemTrayAvailable()) {
        trayIcon = new QSystemTrayIcon(this);
        trayIcon->setIcon(QIcon(":/icon.png"));
        
        // 创建上下文菜单
        QMenu *trayMenu = new QMenu(this);
        QAction *exitAction = new QAction(tr("退出"), this);
        connect(exitAction, &QAction::triggered, this, &QApplication::quit);
        trayMenu->addAction(exitAction);
        
        // 设置上下文菜单
        trayIcon->setContextMenu(trayMenu);
        
        // 添加双击事件处理，显示/隐藏主窗口
        connect(trayIcon, &QSystemTrayIcon::activated, this, [this](QSystemTrayIcon::ActivationReason reason) {
            if (reason == QSystemTrayIcon::DoubleClick) {
                if (this->isHidden()) {
                    this->show();
                } else {
                    this->hide();
                }
            }
        });
        
        trayIcon->show();
    }
    
    // 初始化按钮状态，不使用条件检查
    ui->stopbtn->setEnabled(false);
    ui->continuebtn->setEnabled(false);
    ui->cancelbtn->setEnabled(false);
}

MainWindow::~MainWindow()
{
    // 确保所有网络请求都被中止
    if (reply) {
        reply->abort();
        reply->deleteLater();
        reply = nullptr;
    }
    
    // 确保文件被正确关闭和释放
    if (file) {
        file->close();
        delete file;
        file = nullptr;
    }
    
    // 停止统计计时器
    if (statsTimer.isActive()) {
        statsTimer.stop();
    }
    
    // 删除系统托盘图标
    if (trayIcon) {
        trayIcon->hide();
        delete trayIcon;
        trayIcon = nullptr;
    }
    
    delete ui;
}

void MainWindow::startRequst(QUrl url)
{
    QNetworkRequest request(url);
    if (bytesAlreadyWritten > 0) {
        QByteArray rangeHeader = QByteArray("bytes=") + QByteArray::number(bytesAlreadyWritten) + "-";
        request.setRawHeader("Range", rangeHeader);
    }
    //get请求，返回QNetworkReply类型，当有新数据到达时会触发readyRead信号
    reply = manager->get(request);
    //触发readyRead信号时，处理新到的数据
    connect(reply,&QNetworkReply::readyRead,this,&MainWindow::httpReadyRead);

    //触发finished信号时，表示文件接收完成
    connect(reply,&QNetworkReply::finished,this,&MainWindow::httpFinished);
    //信号原型QNetworkReply::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)

    //bytesReceived表示发送的字节数，bytesTotal表示总字节数。
    connect(reply,&QNetworkReply::downloadProgress,this,&MainWindow::updateDataReadProgress);
}
//接收响应数据
void MainWindow::httpReadyRead()
{
    //将接收的数据写入文件
    if(file) { file->write(reply->readAll()); }
}
void MainWindow::httpFinished()
{
    //文件接收完成或被中止后的清理
    if (file) {
        file->flush();
        file->close();
        delete file;
        file = 0;
    }

    QNetworkReply::NetworkError err = reply ? reply->error() : QNetworkReply::NoError;

    //销毁QNetworkReply对象
    if (reply) {
        reply->deleteLater();
        reply = 0;
    }

    if (isCancelling) {
        // 用户取消：删除工作目录
        QDir workDir(downloadWorkDir);
        workDir.removeRecursively();
        // 重置状态
        isDownloading = false;
        isPaused = false;
        isCancelling = false;
        bytesAlreadyWritten = 0;
        expectedTotalBytes = 0;
        ui->progressBar->hide();
        stopStats(true);
        return;
    }

    if (isPaused) {
        // 暂停：保留已有文件，不做进一步动作
        isDownloading = false;
        stopStats(false);
        return;
    }

    // 正常完成或出错
    isDownloading = false;
    if (err == QNetworkReply::NoError) {
        // 下载完成：将文件从工作目录移动到目标目录根
        QString finalPath = QDir(downloadBaseDir).filePath(QFileInfo(targetFilePath).fileName());
        if (QFile::exists(finalPath)) {
            QFile::remove(finalPath);
        }
        QFile::rename(targetFilePath, finalPath);
        // 清理工作目录
        QDir(downloadWorkDir).removeRecursively();
        ui->progressBar->hide();
        stopStats(true);
        // 通知气泡，停留三秒
        if (trayIcon) {
            trayIcon->showMessage("MyDownloader", "Download  Mission Completed!", QSystemTrayIcon::Information, 3000);
        }
    } else {
        // 出错：保持工作目录以便后续重试/继续
        // 可根据需要在界面上提示错误
        stopStats(false);
    }
}
//更新进度条
void MainWindow::updateDataReadProgress(qint64 byteRead,qint64 totalBytes)
{
    // 累加已写入的字节以支持断点续传
    if (totalBytes > 0) {
        ui->progressBar->setMaximum(bytesAlreadyWritten + totalBytes);
    }
    ui->progressBar->setValue(bytesAlreadyWritten + byteRead);
}
void MainWindow::on_pushButton_clicked()
{
    //获取URL
    QString urlText = ui->lineEdit->text().trimmed();
    // 获取当前本地时间的 QDateTime 对象
    QDateTime currentDateTime = QDateTime::currentDateTime();

    // 转换为字符串（默认格式）
    QString dateTimeStr = currentDateTime.toString();
    exists = historyurl.contains(ui->lineEdit->text());
    if(!exists)
    {
        historyurl += ("\n" + ui->lineEdit->text() + "\n" + dateTimeStr + "\n");
        if (urlText.isEmpty()) {
            QMessageBox::warning(this, "Warning", "Please input a valid URL!");
            return;
        }

        url = QUrl(urlText);
        if (!url.isValid()) {
            QMessageBox::warning(this, "Warning", "Invalid URL!");
            return;
        }

        QFileInfo info(url.path());
        //解析URL文件名，以该文件名作为接收文件名
        QString filename(info.fileName());
        if(filename.isEmpty()) {
            //为空创建空文件
            filename = "index.html";
        }

        // 选择下载根目录
        downloadBaseDir = ui->downloadPathEdit->text().trimmed();
        if (downloadBaseDir.isEmpty()) {
            QString dl = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
            downloadBaseDir = dl.isEmpty() ? QDir::homePath() : dl;
        }

        // 确保下载根目录存在
        QDir baseDir(downloadBaseDir);
        if (!baseDir.exists() && !baseDir.mkpath(downloadBaseDir)) {
            QMessageBox::critical(this, "Error", "Cannot create download directory: " + downloadBaseDir);
            return;
        }

        // 创建每次下载的工作目录
        downloadWorkDir = QDir(downloadBaseDir).filePath(filename + ".download");
        if (!QDir().mkpath(downloadWorkDir)) {
            QMessageBox::critical(this, "Error", "Cannot create temporary download directory: " + downloadWorkDir);
            return;
        }

        targetFilePath = QDir(downloadWorkDir).filePath(filename);

        // 若是重新开始，清零状态
        if (!isPaused) {
            bytesAlreadyWritten = 0;
            expectedTotalBytes = 0;
        } else {
            // 从已有文件恢复大小
            bytesAlreadyWritten = QFileInfo(targetFilePath).exists() ? QFileInfo(targetFilePath).size() : 0;
        }

        //创建QFile对象并以追加/写入方式打开
        file = new QFile(targetFilePath);
        QIODevice::OpenMode mode = (bytesAlreadyWritten > 0) ? (QIODevice::WriteOnly | QIODevice::Append) : QIODevice::WriteOnly;
        if(!file->open(mode))
        {
            QMessageBox::critical(this, "Error", "Cannot open file for writing: " + targetFilePath);
            delete file;
            file = nullptr;
            return;
        }

        isPaused = false;
        isCancelling = false;
        isDownloading = true;

        //发送请求（支持 Range）
        startRequst(url);

        //进度条清0
        ui->progressBar->setValue(0);
        ui->progressBar->show();
        ui->stopbtn->setEnabled(true);
        ui->cancelbtn->setEnabled(true);
        ui->continuebtn->setEnabled(false);
        startStats();
    }
    else
    {
        QMessageBox::warning(this,"Warning","You have already downloaded this file!");
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // 只有在窗口正常状态下才允许拖动
    if (event->button() == Qt::LeftButton && !isMaximized()) {
        m_isDragging = true;
        // 使用相对位置而不是全局位置
        m_lastMousePos = event->pos();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDragging && (event->buttons() & Qt::LeftButton)) {
        // 使用相对移动量计算新位置
        QPoint delta = event->pos() - m_lastMousePos;
        move(pos() + delta);
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDragging = false;
        event->accept();
    }
}

void MainWindow::on_closebtn_clicked()
{
    // 隐藏主窗口而不是关闭它，这样系统托盘图标仍然可用
    this->hide();
    
    // 如果系统托盘可用，显示通知
    if (trayIcon && trayIcon->isVisible()) {
        trayIcon->showMessage("MyDownloader", "MyDownloader has been minimized to the system tray", QSystemTrayIcon::Information, 2000);
    }
}


void MainWindow::on_minbtn_clicked()
{
    this->showMinimized();
}

void MainWindow::on_browseButton_clicked()
{
    // 打开文件夹选择对话框
    QString dir = QFileDialog::getExistingDirectory(this, 
        tr("选择下载路径"), 
        QDir::homePath(),
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    
    if (!dir.isEmpty()) {
        // 将选择的路径设置到下载路径输入框
        ui->downloadPathEdit->setText(dir);
    }
}

void MainWindow::on_resetPathButton_clicked()
{
    // 重置下载路径为空，使用默认路径
    ui->downloadPathEdit->clear();
}

void MainWindow::on_stopbtn_clicked()
{
    if (isDownloading && reply) {
        // 记录已写入大小
        if (!targetFilePath.isEmpty()) {
            bytesAlreadyWritten = QFileInfo(targetFilePath).size();
        }
        isPaused = true;
        isDownloading = false;
        reply->abort();
    }
    ui->stopbtn->setEnabled(false);
    ui->continuebtn->setEnabled(true);
}

void MainWindow::on_continuebtn_clicked()
{
    if (!isDownloading && !url.isEmpty()) {
        // 继续下载：重新打开文件(追加)，并发起带 Range 的请求
        if (targetFilePath.isEmpty()) {
            // 如果没有设置，按上次规则恢复路径
            QFileInfo info(url.path());
            QString filename = info.fileName().isEmpty() ? QString("index.html") : info.fileName();
            if (downloadBaseDir.isEmpty()) {
                QString dl = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
                downloadBaseDir = dl.isEmpty() ? QDir::homePath() : dl;
            }
            downloadWorkDir = QDir(downloadBaseDir).filePath(filename + ".download");
            targetFilePath = QDir(downloadWorkDir).filePath(filename);
        }
        bytesAlreadyWritten = QFileInfo(targetFilePath).exists() ? QFileInfo(targetFilePath).size() : 0;
        file = new QFile(targetFilePath);
        if (!file->open(QIODevice::WriteOnly | QIODevice::Append)) {
            delete file;
            file = 0;
            return;
        }
        isPaused = false;
        isCancelling = false;
        isDownloading = true;
        startRequst(url);
        ui->progressBar->show();
        startStats();
    }
    ui->continuebtn->setEnabled(false);
    ui->stopbtn->setEnabled(true);
}

void MainWindow::on_cancelbtn_clicked()
{
    if (isDownloading && reply) {
        isCancelling = true;
        reply->abort();
    } else {
        // 未在下载中，也执行清理
        QDir(downloadWorkDir).removeRecursively();
        ui->progressBar->hide();
        // 重置状态
        isDownloading = false;
        isPaused = false;
        isCancelling = false;
        bytesAlreadyWritten = 0;
        expectedTotalBytes = 0;
        stopStats(true);
    }
}

void MainWindow::on_helpbtn_clicked()
{
    // 1. 从资源读取内容
    QFile resourceFile(":/Instructions.txt");
    if (!resourceFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Failed to read resource file!");
        return;
    }
    QString content = resourceFile.readAll();
    resourceFile.close();

    // 2. 创建一个临时文件，并确保它在程序结束前不会被自动删除
    QTemporaryFile *tempFile = new QTemporaryFile(this);
    tempFile->setAutoRemove(false);
    
    if (!tempFile->open()) {
        QMessageBox::critical(this, "Error", "Failed to create temp file!");
        delete tempFile;
        return;
    }
    
    tempFile->write(content.toUtf8());
    tempFile->close(); // 必须关闭，否则 notepad 可能无法读取
    
    QString tempFilePath = tempFile->fileName();
    
    // 3. 用 notepad 打开临时文件
    if (!QProcess::startDetached("notepad.exe", QStringList() << tempFilePath)) {
        QMessageBox::information(this, "Tips", "Failed to open notepad. Please open the file manually: " + tempFilePath);
    }
    
    // 在程序关闭时删除临时文件
    connect(this, &QObject::destroyed, [tempFilePath]() {
        QFile::remove(tempFilePath);
    });
    MainWindowAI * ai = new MainWindowAI;
    ai->show();
}

void MainWindow::startStats()
{
    lastTickBytes = QFileInfo(targetFilePath).exists() ? QFileInfo(targetFilePath).size() : bytesAlreadyWritten;
    elapsedSinceTick.restart();
    if (!statsTimer.isActive()) statsTimer.start();
}

void MainWindow::stopStats(bool clearLabels)
{
    if (statsTimer.isActive()) statsTimer.stop();
    if (clearLabels) {
        ui->ratelb->setText("");
        ui->timelb->setText("");
    }
}

QString MainWindow::formatBytes(qint64 bytes)
{
    const char* units[] = {"B","KB","MB","GB","TB"};
    double value = static_cast<double>(bytes);
    int i = 0;
    while (value >= 1024.0 && i < 4) { value /= 1024.0; ++i; }
    return QString::number(value, 'f', (i==0?0:1)) + " " + units[i];
}

QString MainWindow::formatRate(double bytesPerSecond)
{
    if (bytesPerSecond < 0) bytesPerSecond = 0;
    // reuse formatBytes with per-second suffix
    qint64 rounded = static_cast<qint64>(bytesPerSecond);
    QString base = formatBytes(rounded);
    return base + "/s";
}

QString MainWindow::formatEta(qint64 seconds)
{
    if (seconds < 0) seconds = 0;
    qint64 h = seconds / 3600;
    qint64 m = (seconds % 3600) / 60;
    qint64 s = seconds % 60;
    if (h > 0) return QString::asprintf("%lld:%02lld:%02lld", h, m, s);
    return QString::asprintf("%02lld:%02lld", m, s);
}

void MainWindow::statsTick()
{
    // if no active download and no file, nothing to show
    qint64 nowBytes = QFileInfo(targetFilePath).exists() ? QFileInfo(targetFilePath).size() : bytesAlreadyWritten;
    double ms = static_cast<double>(elapsedSinceTick.elapsed());
    if (ms < 200.0) return; // avoid noise if timer jittered
    double deltaBytes = static_cast<double>(nowBytes - lastTickBytes);
    double rateBps = (deltaBytes * 1000.0) / ms;
    lastTickBytes = nowBytes;
    elapsedSinceTick.restart();

    ui->ratelb->setText(formatRate(rateBps));

    // ETA estimation: need expectedTotalBytes
    qint64 total = ui->progressBar->maximum();
    if (total <= 0) {
        ui->timelb->setText("");
        return;
    }
    qint64 remaining = total - nowBytes;
    if (rateBps <= 1e-3) {
        ui->timelb->setText("--:--");
        return;
    }
    qint64 etaSec = static_cast<qint64>(remaining / rateBps);
    ui->timelb->setText(formatEta(etaSec));
}



void MainWindow::on_historybtn_clicked()
{
    QMessageBox::information(nullptr,"History",historyurl);
}

