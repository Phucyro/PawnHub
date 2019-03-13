#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_login_push_clicked()
{
    QString username = ui->username_edit->text();
    QString password = ui->password_edit->text();
}

void LoginDialog::on_signup_push_clicked()
{
    QString username = ui->username_edit->text();
    QString password = ui->password_edit->text();
}
