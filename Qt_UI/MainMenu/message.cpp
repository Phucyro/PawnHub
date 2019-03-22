#include "message.h"
#include "ui_message.h"

Message::Message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Message)
{
    ui->setupUi(this);
}

Message::~Message()
{
    delete ui;
}

void Message::set_text(QString message)
{
    ui->messageLabel->setText(message);
}

void Message::set_title(QString title)
{
    setWindowTitle(title);
}

void Message::popup()
{
    this->exec();
}

void Message::on_button_clicked()
{
    close();
}
