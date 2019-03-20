#include "logindialog.h"
#include "ui_logindialog.h"

#include "message.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    pwd_repeat(new PasswordRepeat),
    username(nullptr),
    password(nullptr)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::getLoginDeets(QString& username_holder, QString& password_holder)
{
    username = &username_holder;
    password = &password_holder;
    this->exec();
}

void LoginDialog::on_login_button_clicked()
{
    *username = ui->username_edit->text();
    *password = ui->password_edit->text();
}

void LoginDialog::on_signup_button_clicked()
{
    if (!pwd_repeat->checkPassword(ui->password_edit->text()))
     {
         Message* m = new Message();
         m->setText("The passwords were not identical,\nplease try again.");
         m->setTitle("Oh No: Mismatched Passwords");
         m->popup();
     }
}

void LoginDialog::on_cancel_button_clicked()
{
    exit(0);
}
