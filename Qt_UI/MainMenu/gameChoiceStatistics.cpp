#include "gameChoiceStatistics.h"
#include "ui_gameChoiceStatistics.h"
#include "statisticsTab.h"

GameChoiceStatistics::GameChoiceStatistics(int t,Client *c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameChoiceStatistics),
    type(t),
    client(c)
{
    ui->setupUi(this);
}

GameChoiceStatistics::~GameChoiceStatistics()
{
    delete ui;
    delete client;
}


void GameChoiceStatistics::on_classicPushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab(type, client, 0);
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}

void GameChoiceStatistics::on_darkPushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab(type, client, 1);
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}
void GameChoiceStatistics::on_hordePushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab(type, client, 2);
    this->hide();
    stats->exec();
    delete stats;
}
void GameChoiceStatistics::on_alicePushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab(type, client, 3);
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}

void GameChoiceStatistics::on_realTimeClassicPushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab(type, client, 4);
    this->hide();
    stats->exec();
    delete stats;
}

void GameChoiceStatistics::on_realTimeDarkPushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab(type, client, 5);
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}

void GameChoiceStatistics::on_realTimeHordePushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab(type, client, 6);
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}

void GameChoiceStatistics::on_realTimeAlicePushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab(type, client, 7);
    this->hide();
    stats->exec();
    this->show();
    delete stats;
}

void GameChoiceStatistics::on_returnPushButton_pressed()
{
    close();
}
