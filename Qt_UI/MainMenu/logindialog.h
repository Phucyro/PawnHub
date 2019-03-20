#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

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
    void on_login_push_clicked();

    void on_signup_push_clicked();

private:
    Ui::LoginDialog *ui;
    QString *username, *password;
};

#endif // LOGINDIALOG_H
