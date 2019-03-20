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

QString ConnectionDialog::askHostname()
{
    this->exec();
    return hostname;
}

void ConnectionDialog::on_done_push_clicked()
{
    hostname = ui->hostname_input->text();
    this->close();
}
