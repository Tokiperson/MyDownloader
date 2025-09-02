/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QFrame *frame_2;
    QLabel *welcomelb;
    QLineEdit *lineEdit;
    QLineEdit *downloadPathEdit;
    QPushButton *browseButton;
    QPushButton *resetPathButton;
    QProgressBar *progressBar;
    QLabel *ratelb;
    QLabel *timelb;
    QFrame *frame_3;
    QPushButton *closebtn;
    QPushButton *minbtn;
    QLabel *headlb;
    QPushButton *pushButton;
    QLabel *greetlb;
    QPushButton *stopbtn;
    QPushButton *continuebtn;
    QPushButton *cancelbtn;
    QPushButton *helpbtn;
    QPushButton *historybtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(802, 616);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(11, 11, 780, 570));
        frame->setMinimumSize(QSize(780, 570));
        frame->setStyleSheet(QString::fromUtf8("*{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
"QFrame#frame{\n"
"	\n"
"	border-image: url(:/mainbgp.jpg);\n"
"	border-radius:20px\n"
"}\n"
"#frame_2{\n"
"	background-color: rgba(102, 102, 102, 100);\n"
"	border-radius:20px\n"
"}\n"
"#frame_3{\n"
"	background-color: rgba(93, 93, 93, 150);\n"
"	border-radius:20px\n"
"}\n"
"QLabel#welcomelb{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"#ratelb{\n"
"	background:transparent;\n"
"}\n"
"#timelb{\n"
"	background:transparent;\n"
"}\n"
"#headlb{\n"
"	background:transparent;\n"
"}\n"
"#greetlb{\n"
"	background:transparent;	\n"
"}\n"
"QLineEdit#lineEdit{\n"
"	\n"
"	background:transparent;\n"
"	border:none;\n"
"	border-bottom:1px solid rgb(255, 255, 255);\n"
"}\n"
"#downloadPathEdit{\n"
"	\n"
"	background:transparent;\n"
"	border:none;\n"
"	border-bottom:1px solid rgb(255, 255, 255);\n"
"}\n"
"QPushButton#closebtn{\n"
"	background: transparent;\n"
"}\n"
"#minbtn{\n"
"	background: transparent;\n"
"}\n"
"#browseButton{\n"
"		background: rgba(0, 136, 199,"
                        " 150)\n"
"}\n"
"#resetPathButton{\n"
"		background: rgba(0, 136, 199, 150)\n"
"}\n"
"#pushButton{\n"
"		background: rgba(0, 136, 199, 150)\n"
"}\n"
"#stopbtn{\n"
"	background: rgba(0, 136, 199, 150)\n"
"}#continuebtn{\n"
"	background:rgba(0, 136, 199, 150)\n"
"}#cancelbtn{\n"
"	background:rgba(0, 136, 199, 150)\n"
"}\n"
"#helpbtn{\n"
"	background:transparent;\n"
"	font: italic 8pt \"Arial\";\n"
"	text-decoration: underline;\n"
"}\n"
"#historybtn{\n"
"	background:transparent;\n"
"	font: italic 8pt \"Arial\";\n"
"	text-decoration: underline;\n"
"}\n"
"QChartView#graphicsView{\n"
"	background:transparent;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 780, 570));
        frame_2->setMinimumSize(QSize(780, 570));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        welcomelb = new QLabel(frame_2);
        welcomelb->setObjectName("welcomelb");
        welcomelb->setGeometry(QRect(20, 60, 191, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setItalic(true);
        welcomelb->setFont(font);
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(50, 190, 670, 30));
        downloadPathEdit = new QLineEdit(frame_2);
        downloadPathEdit->setObjectName("downloadPathEdit");
        downloadPathEdit->setGeometry(QRect(50, 240, 500, 30));
        browseButton = new QPushButton(frame_2);
        browseButton->setObjectName("browseButton");
        browseButton->setGeometry(QRect(570, 240, 80, 30));
        resetPathButton = new QPushButton(frame_2);
        resetPathButton->setObjectName("resetPathButton");
        resetPathButton->setGeometry(QRect(670, 240, 50, 30));
        progressBar = new QProgressBar(frame_2);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(50, 400, 670, 30));
        progressBar->setValue(24);
        ratelb = new QLabel(frame_2);
        ratelb->setObjectName("ratelb");
        ratelb->setGeometry(QRect(50, 440, 69, 19));
        timelb = new QLabel(frame_2);
        timelb->setObjectName("timelb");
        timelb->setGeometry(QRect(140, 440, 69, 19));
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(0, 0, 780, 40));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        closebtn = new QPushButton(frame_3);
        closebtn->setObjectName("closebtn");
        closebtn->setGeometry(QRect(730, 5, 30, 30));
        closebtn->setMinimumSize(QSize(30, 30));
        closebtn->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/closepic.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        closebtn->setIcon(icon);
        closebtn->setIconSize(QSize(33, 33));
        minbtn = new QPushButton(frame_3);
        minbtn->setObjectName("minbtn");
        minbtn->setGeometry(QRect(690, 5, 30, 30));
        minbtn->setMinimumSize(QSize(30, 30));
        minbtn->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/minpic.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        minbtn->setIcon(icon1);
        minbtn->setIconSize(QSize(33, 33));
        headlb = new QLabel(frame_3);
        headlb->setObjectName("headlb");
        headlb->setGeometry(QRect(30, 5, 220, 30));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(50, 290, 670, 30));
        greetlb = new QLabel(frame_2);
        greetlb->setObjectName("greetlb");
        greetlb->setGeometry(QRect(20, 110, 191, 21));
        stopbtn = new QPushButton(frame_2);
        stopbtn->setObjectName("stopbtn");
        stopbtn->setGeometry(QRect(51, 341, 211, 28));
        continuebtn = new QPushButton(frame_2);
        continuebtn->setObjectName("continuebtn");
        continuebtn->setGeometry(QRect(266, 341, 231, 28));
        cancelbtn = new QPushButton(frame_2);
        cancelbtn->setObjectName("cancelbtn");
        cancelbtn->setGeometry(QRect(500, 340, 221, 28));
        helpbtn = new QPushButton(frame_2);
        helpbtn->setObjectName("helpbtn");
        helpbtn->setGeometry(QRect(580, 480, 141, 28));
        historybtn = new QPushButton(frame_2);
        historybtn->setObjectName("historybtn");
        historybtn->setGeometry(QRect(50, 480, 141, 28));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        welcomelb->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700; color:#ffffff;\">Welcome</span></p></body></html>", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Please input the url of the files you wanna download", nullptr));
        downloadPathEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Download path (leave empty for default)", nullptr));
        browseButton->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        resetPathButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        ratelb->setText(QString());
        timelb->setText(QString());
        closebtn->setText(QString());
        minbtn->setText(QString());
        headlb->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-style:italic;\">MyDownloader</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        greetlb->setText(QString());
        stopbtn->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        continuebtn->setText(QCoreApplication::translate("MainWindow", "Continue", nullptr));
        cancelbtn->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        helpbtn->setText(QCoreApplication::translate("MainWindow", "Any Question?", nullptr));
        historybtn->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
