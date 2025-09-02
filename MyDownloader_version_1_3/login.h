#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase> //数据驱动
#include <QSqlQuery> //数据库执行语句
#include <QDebug>
void sqlite_Init();

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:

    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_loginbtn_clicked();

    void on_shutbtn_clicked();

    void on_minbtn_clicked();

    void on_signbtn_clicked();

private:
    Ui::login *ui;
    QString ac;
    QString psw;
};

#endif // LOGIN_H
