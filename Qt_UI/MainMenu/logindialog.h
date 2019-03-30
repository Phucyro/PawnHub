#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

#include "passwordrepeat.h"

class Socket;

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    void get_login_deets(Socket*, QString&, QString&);

private slots:
    void on_loginButton_pressed();
    void on_signupButton_pressed();
    void on_cancelButton_pressed();

    void on_LoginDialog_rejected();
    void closeEvent();

private:
    Ui::LoginDialog *ui;
    PasswordRepeat *pwd_repeat;
    Socket* socket;
    QString *username, *password;

    bool acceptable_format(QString);
};

#endif // LOGINDIALOG_H
