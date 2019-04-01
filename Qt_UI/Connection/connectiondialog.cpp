#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog),
    display(new Display),
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
    this->show();
    return hostname;
}

void ConnectionDialog::on_done_push_clicked()
{
    hostname = ui->hostname_input->text();
    display->setText(hostname);
    display->show();
    this->close();
}
