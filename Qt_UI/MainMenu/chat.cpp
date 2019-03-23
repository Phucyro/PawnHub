#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_inputLineEdit_returnPressed()
{
    ui->chatPlainTextEdit->appendPlainText(ui->inputLineEdit->text());
    ui->inputLineEdit->clear();
}

void Chat::on_sendPushButton_pressed()
{
    ui->chatPlainTextEdit->appendPlainText(ui->inputLineEdit->text());
    ui->inputLineEdit->clear();
}

void Chat::on_quitPushButton_pressed()
{
    exit(0);
}

void Chat::on_changeChanPushButton_pressed()
{
    //change channel
}
