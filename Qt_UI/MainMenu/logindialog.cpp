#include "logindialog.h"
#include "ui_logindialog.h"
#include "message.h"

#include "../../Communication/Socket.hpp"
#include "../Modified_Files/CheckFormat.hpp"
#include "../Modified_Files/ClientFunctions.hpp"

#include "message.h"

//#include <stdio.h>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    pwd_repeat(new PasswordRepeat),
    socket(nullptr),
    username(nullptr),
    password(nullptr)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
    delete pwd_repeat;
    socket = nullptr;
    username = nullptr;
    password = nullptr;
}

void LoginDialog::get_login_deets(Socket* socket_, QString& username_holder, QString& password_holder)
{
    socket = socket_;
    username = &username_holder;
    password = &password_holder;
    exec();
}

bool LoginDialog::acceptable_format(QString pwdConfirmation)
{
    bool acceptable = false;

    int format = checkFormat(username->toStdString(), password->toStdString(), pwdConfirmation.toStdString());
    if (format != 5)
    {
        Message* m = new Message();
        switch (format)
        {
            case 0 :
                m->set_text("You may not use 'Guest' or 'all' as usernames.\nPlease try again.");
                break;
            case 1 :
                m->set_text("Mismatched passwords.\nPlease try again.");
                break;
            case 2 :
                m->set_text("Size range is 1 to 10 characters.\nPlease try again.");
                break;
            case 3 :
                m->set_text("Username characters are limited to numbers and letters.\nPlease try again.");
                break;
            case 4 :
                m->set_text("You may not use '|' and '~'.\nPlease try again.");
                break;
        }
        m->set_title("Oh No: Wrong Input");
        m->popup();
    }
    else acceptable = true;

    return acceptable;
}

void LoginDialog::on_loginButton_clicked()
{
    *username = ui->usernameInput->text();
    *password = ui->passwordInput->text();
    if (acceptable_format(*password))
    {
        signIn(socket, username->toStdString(), password->toStdString());
        hide();
    }
}

void LoginDialog::on_signupButton_clicked()
{
    QString pwdConfirmation = pwd_repeat->get_confirmation();
    if (acceptable_format(pwdConfirmation))
    {
        signUp(socket, username->toStdString(), password->toStdString());
        hide();
    }
}

void LoginDialog::on_cancelButton_clicked()
{
    closeEvent();
}

void LoginDialog::on_LoginDialog_rejected()
{
    closeEvent();
}

void LoginDialog::closeEvent()
{
    exit(0);
}
