#include "signup.h"
#include "ui_signup.h"
#include "login.h"

Signup::Signup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Signup)
{
    ui->setupUi(this);
    setWindowTitle("MyDownloader-SignUp");
    setWindowIcon(QIcon(":/icon.png"));
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    connect(ui->acle, SIGNAL(returnPressed()), this, SLOT(on_esbtn_clicked()));
    connect(ui->pswle, SIGNAL(returnPressed()), this, SLOT(on_esbtn_clicked()));
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_rtbtn_clicked()
{
    login *l = new login;
    l->show();
    this->close();
}


void Signup::on_esbtn_clicked()
{
    sqlite_Init();
    QString username = ui->acle->text();
    QString password = ui->pswle->text();
    QString surepass = ui->esle->text();
    //判断密码是否一致
    if(password == surepass)
    {
        QString sql=QString("insert into user(username,password) values('%1','%2');")
        .arg(username).arg(password);
        //创建执行语句对象
        QSqlQuery query;
        //判断执行结果
        if(!query.exec(sql))
        {
            qDebug()<<"insert into error";
            QMessageBox::information(this,"Sign Up Confirmation","Sign up failed!");
        }
        else
        {
            qDebug()<<"insert into success";
            QMessageBox::information(this,"Sign Up Confirmation","Sign up succeeded!");
            login *l = new login;
            l->show();
            this->close();
        }

    }else{
        QMessageBox::information(this,"Sign Up Confirmation","The passwords you entered were different!");
    }
}

