#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class Signup;
}

class Signup : public QWidget
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

private slots:
    void on_rtbtn_clicked();

    void on_esbtn_clicked();

private:
    Ui::Signup *ui;
};

#endif // SIGNUP_H
