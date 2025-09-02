/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *picfr;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearbtn;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cfmbtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ccbtn;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Dialog);
        horizontalLayout->setObjectName("horizontalLayout");
        frame = new QFrame(Dialog);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setMinimumSize(QSize(220, 20));
        label->setMaximumSize(QSize(220, 20));

        verticalLayout->addWidget(label);

        picfr = new QFrame(frame);
        picfr->setObjectName("picfr");
        picfr->setMinimumSize(QSize(350, 120));
        picfr->setMaximumSize(QSize(350, 120));
        picfr->setStyleSheet(QString::fromUtf8("border-image: url(:/calculate.png);"));
        picfr->setFrameShape(QFrame::Shape::StyledPanel);
        picfr->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout->addWidget(picfr);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(260, 30));
        lineEdit->setMaximumSize(QSize(260, 30));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(17, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        clearbtn = new QPushButton(frame);
        clearbtn->setObjectName("clearbtn");
        clearbtn->setMinimumSize(QSize(60, 30));
        clearbtn->setMaximumSize(QSize(60, 30));

        horizontalLayout_2->addWidget(clearbtn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        cfmbtn = new QPushButton(frame);
        cfmbtn->setObjectName("cfmbtn");
        cfmbtn->setMinimumSize(QSize(100, 30));
        cfmbtn->setMaximumSize(QSize(100, 30));

        horizontalLayout_3->addWidget(cfmbtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        ccbtn = new QPushButton(frame);
        ccbtn->setObjectName("ccbtn");
        ccbtn->setMinimumSize(QSize(100, 30));
        ccbtn->setMaximumSize(QSize(100, 30));

        horizontalLayout_3->addWidget(ccbtn);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addWidget(frame);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Please figure out the fomula :", nullptr));
        clearbtn->setText(QCoreApplication::translate("Dialog", "Clear", nullptr));
        cfmbtn->setText(QCoreApplication::translate("Dialog", "Confirm", nullptr));
        ccbtn->setText(QCoreApplication::translate("Dialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
