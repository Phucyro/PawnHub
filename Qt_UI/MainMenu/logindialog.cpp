#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    username(nullptr),
    password(nullptr)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::getLoginDeets(QString& username_holder, QString& password_holder) {
    username = &username_holder;
    password = &password_holder;
    this->exec();
}

void LoginDialog::on_login_push_clicked()
{
    *username = ui->username_edit->text();
    *password = ui->password_edit->text();
}

void LoginDialog::on_signup_push_clicked()
{
    *username = ui->username_edit->text();
    *password = ui->password_edit->text();
}
