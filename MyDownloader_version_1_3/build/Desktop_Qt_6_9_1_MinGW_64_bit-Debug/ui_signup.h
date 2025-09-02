/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Signup
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QFrame *frame_2;
    QLabel *tiplabel;
    QLineEdit *acle;
    QLineEdit *pswle;
    QLineEdit *esle;
    QPushButton *esbtn;
    QPushButton *rtbtn;
    QLabel *infolabel;

    void setupUi(QWidget *Signup)
    {
        if (Signup->objectName().isEmpty())
            Signup->setObjectName("Signup");
        Signup->resize(763, 440);
        horizontalLayout = new QHBoxLayout(Signup);
        horizontalLayout->setObjectName("horizontalLayout");
        frame = new QFrame(Signup);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8("*{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QFrame#frame{\n"
"border-image: url(:/signuppic.jpg);\n"
"border-radius:20px;\n"
"}\n"
"#frame_2{\n"
"background-color: rgba(152, 152, 152, 230);\n"
"border-radius:20px;\n"
"}\n"
"QLabel#infolabel{\n"
"background:transparent;\n"
"}\n"
"#tiplabel{\n"
"background:transparent;\n"
"}\n"
"QLineEdit#acle{\n"
"background:transparent;\n"
"	border:none;\n"
"	border-bottom:1px solid  rgb(13, 13, 13)\n"
"}\n"
"#pswle{\n"
"background:transparent;\n"
"	border:none;\n"
"	border-bottom:1px solid rgbrgb(13, 13, 13)\n"
"}\n"
"#esle{\n"
"background:transparent;\n"
"	border:none;\n"
"	border-bottom:1px solid rgbrgb(13, 13, 13)\n"
"}\n"
"QPushButton#esbtn{\n"
"border-radius:10px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.89, y1:0.062, x2:0.095, y2:0.943005, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(81, 124, 159, 255));\n"
"}\n"
"#rtbtn{\n"
"border-radius:10px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.89, y1:0.062, x2:0.095, y2:0.943005, stop:0"
                        " rgba(255, 255, 255, 255), stop:1 rgba(81, 124, 159, 255));\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(5, 82, 731, 331));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        tiplabel = new QLabel(frame_2);
        tiplabel->setObjectName("tiplabel");
        tiplabel->setGeometry(QRect(20, 10, 211, 21));
        acle = new QLineEdit(frame_2);
        acle->setObjectName("acle");
        acle->setGeometry(QRect(30, 60, 651, 41));
        pswle = new QLineEdit(frame_2);
        pswle->setObjectName("pswle");
        pswle->setGeometry(QRect(30, 120, 651, 41));
        pswle->setEchoMode(QLineEdit::EchoMode::Password);
        esle = new QLineEdit(frame_2);
        esle->setObjectName("esle");
        esle->setGeometry(QRect(30, 180, 651, 41));
        esle->setEchoMode(QLineEdit::EchoMode::Password);
        esbtn = new QPushButton(frame_2);
        esbtn->setObjectName("esbtn");
        esbtn->setGeometry(QRect(30, 250, 261, 41));
        rtbtn = new QPushButton(frame_2);
        rtbtn->setObjectName("rtbtn");
        rtbtn->setGeometry(QRect(420, 250, 261, 41));
        infolabel = new QLabel(frame);
        infolabel->setObjectName("infolabel");
        infolabel->setGeometry(QRect(300, 10, 141, 61));

        horizontalLayout->addWidget(frame);


        retranslateUi(Signup);

        QMetaObject::connectSlotsByName(Signup);
    } // setupUi

    void retranslateUi(QWidget *Signup)
    {
        Signup->setWindowTitle(QCoreApplication::translate("Signup", "Form", nullptr));
        tiplabel->setText(QCoreApplication::translate("Signup", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-style:italic;\">Let's get a new account!</span></p></body></html>", nullptr));
        acle->setPlaceholderText(QCoreApplication::translate("Signup", "Please create your account(characters and numbers only)", nullptr));
        pswle->setPlaceholderText(QCoreApplication::translate("Signup", "Please create your password(characters and numbers only)", nullptr));
        esle->setPlaceholderText(QCoreApplication::translate("Signup", "Please confirm your password", nullptr));
        esbtn->setText(QCoreApplication::translate("Signup", "Sign Up", nullptr));
        rtbtn->setText(QCoreApplication::translate("Signup", "Return to Log In", nullptr));
        infolabel->setText(QCoreApplication::translate("Signup", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700;\">Sign Up</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Signup: public Ui_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
