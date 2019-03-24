#include "gameWithAlice.h"
#include "ui_gameWithAlice.h"

GameWithAlice::GameWithAlice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWithAlice)
{
    ui->setupUi(this);
}

GameWithAlice::~GameWithAlice()
{
    delete ui;
}

void GameWithAlice::on_sendPushButton_pressed()
{
    ui->chatText->appendPlainText(ui->sendingTextField->text());
    ui->sendingTextField->clear();
}

void GameWithAlice::on_sendingTextField_returnPressed()
{
    ui->chatText->appendPlainText(ui->sendingTextField->text());
    ui->sendingTextField->clear();
}

void GameWithAlice::on_surrendButton_pressed()
{
    close();
}
