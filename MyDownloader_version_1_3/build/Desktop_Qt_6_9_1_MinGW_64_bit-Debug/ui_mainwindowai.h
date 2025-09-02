/********************************************************************************
** Form generated from reading UI file 'mainwindowai.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWAI_H
#define UI_MAINWINDOWAI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowAI
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowAI)
    {
        if (MainWindowAI->objectName().isEmpty())
            MainWindowAI->setObjectName("MainWindowAI");
        MainWindowAI->resize(800, 600);
        centralwidget = new QWidget(MainWindowAI);
        centralwidget->setObjectName("centralwidget");
        MainWindowAI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowAI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindowAI->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowAI);
        statusbar->setObjectName("statusbar");
        MainWindowAI->setStatusBar(statusbar);

        retranslateUi(MainWindowAI);

        QMetaObject::connectSlotsByName(MainWindowAI);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowAI)
    {
        MainWindowAI->setWindowTitle(QCoreApplication::translate("MainWindowAI", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowAI: public Ui_MainWindowAI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWAI_H
