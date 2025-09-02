#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "dialog.h"
#include "signup.h"

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icon.png"));
    setWindowTitle("MyDownloader-LogIn");
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    connect(ui->acle, SIGNAL(returnPressed()), this, SLOT(on_loginbtn_clicked()));
    connect(ui->pswle, SIGNAL(returnPressed()), this, SLOT(on_loginbtn_clicked()));
}

void sqlite_Init()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("user.db");
    if(!db.open())
    {
        qDebug()<<"open error";
    }
    //create excle
    QString createsql=QString("create table if not exists user(id integer primary key autoincrement,"
                                "username ntext unique not NULL,"
                                "password ntext not NULL)");
    QSqlQuery query;
    if(!query.exec(createsql)){
        qDebug()<<"table create error";
    }
    else{
        qDebug()<<"table create success";
    }
}


login::~login()
{
    delete ui;
}

void login::on_loginbtn_clicked()
{
    if(ui->acle->text().isEmpty()){QMessageBox::warning(this,"Warning","Please input your account!");}
    else if(ui->pswle->text().isEmpty()){QMessageBox::warning(this,"Warning","Please input your password!");}
    else
    {
        Dialog dlg(this);
        if(dlg.exec() == QDialog::Accepted)
        {
            sqlite_Init();
            QString username = ui->acle->text();
            QString password = ui->pswle->text();
            QString sql=QString("select * from user where username='%1' and password='%2'")
                              .arg(username).arg(password);
            //创建执行语句对象
            QSqlQuery query(sql);
            //判断执行结果
            if(!query.next())
            {
                qDebug()<<"Login error";
                QMessageBox::information(this,"Log In Confirmation","Log in failed, the account or password was wrong!");
            }
            else
            {
                qDebug()<<"Login success";
                QMessageBox::information(this,"Log In Confirmation","Log in succeeded!");
                //登录成功后可以跳转到其他页面
                MainWindow *w = new MainWindow;
                w->show();
                // 隐藏而不是关闭登录窗口，确保程序不会因为主窗口关闭而退出
                this->hide();

            }

        }
        else
        {
            QMessageBox::information(this,"Tips","You have canceled the verification!");
        }
    }

}


void login::on_shutbtn_clicked()
{
    this->close();
}


void login::on_minbtn_clicked()
{
    this->showMinimized();
}


void login::on_signbtn_clicked()
{
    this->close();
    Signup *s = new Signup;
    s->show();
}

