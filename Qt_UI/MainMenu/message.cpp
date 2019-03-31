#include "message.h"
#include "ui_message.h"
#include <iostream>

Message::Message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Message),
    is_promotion(false)
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

void Message::promotion_choice()
{
    set_title("Promotion");
    set_text("Please choose your desired promotion.");
    ui->pushButton_1->setText("Queen");
    ui->pushButton_1->setEnabled(true);
    ui->pushButton_1->setFlat(false);
    ui->pushButton_2->setText("Bishop");
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_2->setFlat(false);
    ui->pushButton_3->setText("Rook");
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_3->setFlat(false);
    ui->okButton->setText("Knight");
    is_promotion = true;
}

void Message::on_okButton_clicked()
{
    if (is_promotion)
    {
        emit promotion_chosen(ui->okButton->text());
    }
    close();
}

void Message::on_pushButton_1_clicked()
{
    std::cout << "sending" << std::endl;
    emit promotion_chosen(ui->pushButton_1->text());
    std::cout << "sent" << std::endl;
    close();
}

void Message::on_pushButton_2_clicked()
{
    emit promotion_chosen(ui->pushButton_2->text());
    close();
}

void Message::on_pushButton_3_clicked()
{
    emit promotion_chosen(ui->pushButton_3->text());
    close();
}
