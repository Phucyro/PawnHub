#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog),
    hostname("hi")
{
    ui->setupUi(this);
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

QString ConnectionDialog::ask_hostname()
{
    exec();
    return hostname;
}

void ConnectionDialog::on_donePush_clicked()
{
    hostname = ui->hostnameInput->text();
    hide();
}

void ConnectionDialog::on_cancelPush_clicked()
{
    closeEvent();
}

void ConnectionDialog::on_ConnectionDialog_rejected()
{
    closeEvent();
}

void ConnectionDialog::closeEvent()
{
    exit(0);
}
