/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QFrame *frame;
    QFrame *frame_2;
    QLabel *label;
    QFrame *frame_3;
    QLineEdit *acle;
    QLineEdit *pswle;
    QPushButton *loginbtn;
    QPushButton *signbtn;
    QPushButton *shutbtn;
    QPushButton *minbtn;
    QLabel *infolb;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(873, 535);
        frame = new QFrame(login);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 30, 810, 470));
        frame->setStyleSheet(QString::fromUtf8("*{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QFrame#frame{\n"
"	border-image: url(:/login.jpg);\n"
"	border-radius:20px;\n"
"}\n"
"#frame_2{\n"
"	\n"
"	background-color: rgba(136, 136, 136, 150);\n"
"	border-radius:20px;\n"
"}\n"
"#frame_3{\n"
"	background-color: rgba(38, 38, 38, 150);\n"
"	border-radius:20px;\n"
"}\n"
"QLabel#label{\n"
"	background:transparent;\n"
"}\n"
"#infolb{\n"
"	background:transparent;\n"
"}\n"
"QLineEdit#acle{\n"
"	background:transparent;\n"
"	border:none;\n"
"	border-bottom:1px solid rgb(144, 144, 144)\n"
"}\n"
"#pswle{\n"
"	background:transparent;\n"
"	border:none;\n"
"	border-bottom:1px solid rgb(144, 144, 144)\n"
"}\n"
"QPushButton#loginbtn{\n"
"	border-radius:10px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.89, y1:0.062, x2:0.095, y2:0.943005, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(81, 124, 159, 255));\n"
"}\n"
"#shutbtn{\n"
"	background-color: rgba(177, 177, 177, 100);\n"
"}\n"
"#minbtn{\n"
"	background-color: rgba(177, 177, 177, 100);\n"
"}\n"
"#sig"
                        "nbtn{\n"
"border-radius:10px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.89, y1:0.062, x2:0.095, y2:0.943005, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(81, 124, 159, 255));\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 810, 470));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 30, 171, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(10, 120, 791, 341));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        acle = new QLineEdit(frame_3);
        acle->setObjectName("acle");
        acle->setGeometry(QRect(80, 60, 641, 41));
        pswle = new QLineEdit(frame_3);
        pswle->setObjectName("pswle");
        pswle->setGeometry(QRect(80, 150, 641, 41));
        pswle->setEchoMode(QLineEdit::EchoMode::Password);
        loginbtn = new QPushButton(frame_3);
        loginbtn->setObjectName("loginbtn");
        loginbtn->setGeometry(QRect(80, 220, 301, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(10);
        font1.setBold(true);
        loginbtn->setFont(font1);
        signbtn = new QPushButton(frame_3);
        signbtn->setObjectName("signbtn");
        signbtn->setGeometry(QRect(420, 220, 301, 41));
        signbtn->setFont(font1);
        shutbtn = new QPushButton(frame_2);
        shutbtn->setObjectName("shutbtn");
        shutbtn->setGeometry(QRect(768, 10, 30, 30));
        minbtn = new QPushButton(frame_2);
        minbtn->setObjectName("minbtn");
        minbtn->setGeometry(QRect(730, 10, 30, 30));
        infolb = new QLabel(frame_2);
        infolb->setObjectName("infolb");
        infolb->setGeometry(QRect(10, 10, 220, 30));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Form", nullptr));
        label->setText(QCoreApplication::translate("login", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">LOG IN</span></p></body></html>", nullptr));
        acle->setPlaceholderText(QCoreApplication::translate("login", "Please input your account here", nullptr));
        pswle->setPlaceholderText(QCoreApplication::translate("login", "Please input your password here", nullptr));
        loginbtn->setText(QCoreApplication::translate("login", "Log In", nullptr));
        signbtn->setText(QCoreApplication::translate("login", "Sign Up", nullptr));
        shutbtn->setText(QCoreApplication::translate("login", "X", nullptr));
        minbtn->setText(QCoreApplication::translate("login", "_", nullptr));
        infolb->setText(QCoreApplication::translate("login", "<html><head/><body><p><span style=\" font-style:italic; color:#b1b1b1;\">MyDownloader-Log In</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
