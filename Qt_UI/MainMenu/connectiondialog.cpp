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
    this->exec();
    return hostname;
}

void ConnectionDialog::on_donePush_clicked()
{
    hostname = ui->hostnameInput->text();
    close();
}

void ConnectionDialog::on_cancelPush_clicked()
{
    exit(0);
}
