#include "gameChoice.h"
#include "ui_gameChoice.h"

GameChoice::GameChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameChoice)
{
    ui->setupUi(this);
}

GameChoice::~GameChoice()
{
    delete ui;
}


void GameChoice::on_classicPushButton_pressed()
{

}
void GameChoice::on_darkPushButton_pressed()
{

}
void GameChoice::on_hordePushButton_pressed()
{

}
void GameChoice::on_alicePushButton_pressed()
{

}

void GameChoice::on_realTimeClassicPushButton_pressed()
{

}

void GameChoice::on_realTimeDarkPushButton_pressed()
{

}

void GameChoice::on_realTimeHordePushButton_pressed()
{

}

void GameChoice::on_realTimeAlicePushButton_pressed()
{

}
