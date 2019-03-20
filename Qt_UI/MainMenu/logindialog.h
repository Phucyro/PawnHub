#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

#include "passwordrepeat.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    void getLoginDeets(QString&, QString&);

private slots:
    void on_login_button_clicked();
    void on_signup_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::LoginDialog *ui;
    PasswordRepeat *pwd_repeat;
    QString *username, *password;
};

#endif // LOGINDIALOG_H
