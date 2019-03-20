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
    delete pwd_repeat;
    delete username;
    delete password;
}

void LoginDialog::get_login_deets(QString& username_holder, QString& password_holder)
{
    username = &username_holder;
    password = &password_holder;
    this->exec();
}

void LoginDialog::on_loginButton_clicked()
{
    *username = ui->usernameInput->text();
    *password = ui->passwordInput->text();
}

void LoginDialog::on_signupButton_clicked()
{
    if (!pwd_repeat->check_password(ui->passwordInput->text()))
     {
         Message* m = new Message();
         m->set_text("The passwords were not identical,\nplease try again.");
         m->set_title("Oh No: Mismatched Passwords");
         m->popup();
     }
}

void LoginDialog::on_cancelButton_clicked()
{
    exit(0);
}
