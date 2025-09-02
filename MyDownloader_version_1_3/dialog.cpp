#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icon.png"));
    setWindowTitle("MyDownloader-LogIn");
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(on_cfmbtn_clicked()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_cfmbtn_clicked()
{
    confirm = ui->lineEdit->text();
    if(confirm.isEmpty())
    {
        QMessageBox::warning(this,"Warning","Please input the verification code!");
    }
    else if(confirm != "257")
    {
        QMessageBox::warning(this,"Warning","The result was wrong,please try again!");
    }
    else
    {
        this->accept();
    }
}


void Dialog::on_clearbtn_clicked()
{
    ui->lineEdit->clear();
    confirm = "";
}


void Dialog::on_ccbtn_clicked()
{
    this->close();
}

