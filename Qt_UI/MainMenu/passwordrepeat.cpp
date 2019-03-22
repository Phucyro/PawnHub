#include "passwordrepeat.h"
#include "ui_passwordrepeat.h"

#include "message.h"

PasswordRepeat::PasswordRepeat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordRepeat),
    password2(),
    matched(false)
{
    ui->setupUi(this);
}

PasswordRepeat::~PasswordRepeat()
{
    delete ui;
}

bool PasswordRepeat::check_password(QString _password1)
{
    exec();
    password1 = _password1;
    return matched;
}

void PasswordRepeat::on_doneButton_clicked()
{
    password2 = ui->passwordInput->text();
    close();
    if (password1 != password2)
     {
         Message* m = new Message();
         m->set_text("The passwords were not identical,\nplease try again.");
         m->set_title("Oh No: Mismatched Passwords");
         m->popup();
     }
    else
    {
        matched = true;
    }
}

void PasswordRepeat::on_cancelButton_clicked()
{
    hide();
}
