#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_cfmbtn_clicked();

    void on_clearbtn_clicked();

    void on_ccbtn_clicked();

private:
    Ui::Dialog *ui;
    QString confirm;
};

#endif // DIALOG_H
