#include "message.h"
#include "ui_message.h"

Message::Message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Message),
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
}

void Message::set_okButton(QString text){
    ui->okButton->setText(text);
}

QString Message::get_choice()
{
    return choice;
}

void Message::on_okButton_clicked()
{
    cancel = true;
    choice = ui->okButton->text();
    close();
}

void Message::on_pushButton_1_clicked()
{
    choice = ui->pushButton_1->text();
    close();
}

void Message::on_pushButton_2_clicked()
{
    choice = ui->pushButton_2->text();
    close();
}

void Message::on_pushButton_3_clicked()
{
    choice = ui->pushButton_3->text();
    close();
}
bool Message::getCancel(){
    return cancel;
}
