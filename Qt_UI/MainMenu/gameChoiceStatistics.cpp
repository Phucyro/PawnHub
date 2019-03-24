#include "gameChoiceStatistics.h"
#include "ui_gameChoiceStatistics.h"

GameChoiceStatistics::GameChoiceStatistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameChoiceStatistics)
{
    ui->setupUi(this);
}

GameChoiceStatistics::~GameChoiceStatistics()
{
    delete ui;
}


void GameChoiceStatistics::on_classicPushButton_pressed()
{

}

void GameChoiceStatistics::on_darkPushButton_pressed()
{

}
void GameChoiceStatistics::on_hordePushButton_pressed()
{

}
void GameChoiceStatistics::on_alicePushButton_pressed()
{

}

void GameChoiceStatistics::on_realTimeClassicPushButton_pressed()
{

}

void GameChoiceStatistics::on_realTimeDarkPushButton_pressed()
{

}

void GameChoiceStatistics::on_realTimeHordePushButton_pressed()
{

}

void GameChoiceStatistics::on_realTimeAlicePushButton_pressed()
{

}
