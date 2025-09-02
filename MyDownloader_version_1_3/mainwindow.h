#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QMouseEvent>
#include <QPoint>
#include <QTimer>
#include <QElapsedTimer>
#include <QSystemTrayIcon>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "mainwindowai.h"

class QFile;
class QNetworkReply;
class QNetworkAccessManager;

QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void startRequst(QUrl url);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile *file;
    QUrl url;
    bool isPaused = false;
    bool isDownloading = false;
    qint64 bytesAlreadyWritten = 0; // accumulated bytes on disk for resume
    qint64 expectedTotalBytes = 0;  // total size if known
    QString downloadBaseDir;        // user-selected or default base path
    QString downloadWorkDir;        // per-download directory we create
    QString targetFilePath;         // full path to the downloading file
    bool isCancelling = false;
    QTimer statsTimer;              // periodic stats update timer
    QElapsedTimer elapsedSinceTick; // for precise per-second calculations
    qint64 lastTickBytes = 0;       // bytes on disk at last tick

    // helpers
    void startStats();
    void stopStats(bool clearLabels);
    void statsTick();
    static QString formatBytes(qint64 bytes);
    static QString formatRate(double bytesPerSecond);
    static QString formatEta(qint64 seconds);

    QSystemTrayIcon *trayIcon = nullptr; // system tray for notifications
    bool m_isDragging = false;  // 是否正在拖动
    bool exists;
    QPoint m_lastMousePos;     // 上次鼠标位置
    QString historyurl;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void httpFinished(); //文件接收完成
    void httpReadyRead();//接收数据中
    void updateDataReadProgress(qint64,qint64);//进度条更新
    void on_pushButton_clicked();   //发送请求
    void on_closebtn_clicked();
    void on_minbtn_clicked();
    void on_browseButton_clicked(); //选择下载路径
    void on_resetPathButton_clicked(); //重置下载路径
    void on_stopbtn_clicked();      // 暂停
    void on_continuebtn_clicked();  // 继续
    void on_cancelbtn_clicked();    // 取消并清理
    void on_helpbtn_clicked();      // 打开Instructions.txt
    void on_historybtn_clicked();
};
#endif // MAINWINDOW_H
