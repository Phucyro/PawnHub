#include "passwordrepeat.h"
#include "ui_passwordrepeat.h"

#include "message.h"

PasswordRepeat::PasswordRepeat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordRepeat),
    pwdConfirmation()
{
    ui->setupUi(this);
}

PasswordRepeat::~PasswordRepeat()
{
    delete ui;
}

QString PasswordRepeat::get_confirmation()
{
    exec();
    return pwdConfirmation;
}

void PasswordRepeat::on_doneButton_clicked()
{
    pwdConfirmation = ui->passwordInput->text();
    close();
}

void PasswordRepeat::on_cancelButton_clicked()
{
    hide();
}
