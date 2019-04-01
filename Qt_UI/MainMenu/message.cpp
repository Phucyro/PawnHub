#include "message.h"
#include "ui_message.h"
#include <iostream>

#include <QCloseEvent>

Message::Message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Message),
    is_promotion(false),    
    cancel(false)
{
    ui->setupUi(this);
}

Message::~Message()
{
    cancel = false;
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
    promotion = QString();
    is_promotion = true;
}

void Message::set_okButton(QString text){
    ui->okButton->setText(text);
}

void Message::on_okButton_clicked()
{
    cancel = true;
    if (is_promotion)
    {
        promotion = ui->okButton->text();
        emit promotion_chosen(promotion);
    }
    close();
}

void Message::on_pushButton_1_clicked()
{
    promotion = ui->pushButton_1->text();
    emit promotion_chosen(promotion);
    close();
}

void Message::on_pushButton_2_clicked()
{
    promotion = ui->pushButton_2->text();
    emit promotion_chosen(promotion);
    close();
}

void Message::on_pushButton_3_clicked()
{
    promotion = ui->pushButton_3->text();
    emit promotion_chosen(promotion);
    close();
}

bool Message::getCancel()
{
    return cancel;
}

void Message::closeEvent(QCloseEvent* event)
{
    if (is_promotion && promotion == "") event->ignore();
    else event->accept();
}
