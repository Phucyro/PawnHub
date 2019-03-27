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

void Message::promotion_choice()
{
    set_title("Promotion");
    set_text("Please choose your pawn's promotion.");
    ui->pushButton_1->setText("Queen");
    ui->pushButton_2->setText("Bishop");
    ui->pushButton_3->setText("Rook");
    ui->okButton->setText("Knight");
}

QString Message::get_choice()
{
    return choice;
}

void Message::on_okButton_clicked()
{
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
