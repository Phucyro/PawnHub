#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

#include "passwordrepeat.h"
#include "../../Communication/CheckFormat.hpp"
#include "../Modified_Files/ClientFunctions.hpp"
#include "message.h"

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
    void on_loginButton_clicked();
    void on_signupButton_clicked();
    void on_cancelButton_clicked();

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
