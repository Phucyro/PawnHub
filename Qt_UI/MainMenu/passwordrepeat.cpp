#include "passwordrepeat.h"
#include "ui_passwordrepeat.h"

#include <iostream>

PasswordRepeat::PasswordRepeat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordRepeat),
    password2()
{
    ui->setupUi(this);
}

PasswordRepeat::~PasswordRepeat()
{
    delete ui;
}

bool PasswordRepeat::check_password(QString password1)
{
    this->exec();
    return password2 == password1;
}

void PasswordRepeat::on_doneButton_clicked()
{
    password2 = ui->passwordInput->text();
    close();
}

void PasswordRepeat::on_cancelButton_clicked()
{
    exit(0);
}
