#include "gameChoiceStatistics.h"
#include "ui_gameChoiceStatistics.h"
#include "statisticsTab.h"

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
    StatisticsTab* stats = new StatisticsTab;
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}

void GameChoiceStatistics::on_darkPushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab;
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}
void GameChoiceStatistics::on_hordePushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab;
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}
void GameChoiceStatistics::on_alicePushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab;
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}

void GameChoiceStatistics::on_realTimeClassicPushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab;
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}

void GameChoiceStatistics::on_realTimeDarkPushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab;
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}

void GameChoiceStatistics::on_realTimeHordePushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab;
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}

void GameChoiceStatistics::on_realTimeAlicePushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab;
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}

void GameChoiceStatistics::on_returnPushButton_pressed()
{
    close();
}
