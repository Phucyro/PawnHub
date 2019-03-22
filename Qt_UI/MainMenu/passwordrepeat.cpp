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
//    if (password1 != password2)
//     {
//         Message* m = new Message();
//         m->set_text("The passwords were not identical,\nplease try again.");
//         m->set_title("Oh No: Mismatched Passwords");
//         m->popup();
//     }
//    else
//    {
//        matched = true;
//    }
}

void PasswordRepeat::on_cancelButton_clicked()
{
    hide();
}
