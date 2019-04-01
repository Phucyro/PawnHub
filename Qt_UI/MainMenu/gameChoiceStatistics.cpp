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
}

void GameChoiceStatistics::open_statistics_tab(int gameMode)
{
    StatisticsTab* stats = new StatisticsTab(type, client, gameMode);
    stats->exec();
    delete stats;
}


void GameChoiceStatistics::on_classicPushButton_pressed()
{
    open_statistics_tab(0);
}

void GameChoiceStatistics::on_darkPushButton_pressed()
{
    open_statistics_tab(1);
}
void GameChoiceStatistics::on_hordePushButton_pressed()
{
    open_statistics_tab(2);
}
void GameChoiceStatistics::on_alicePushButton_pressed()
{
    open_statistics_tab(3);
}

void GameChoiceStatistics::on_realTimeClassicPushButton_pressed()
{
    open_statistics_tab(4);
}

void GameChoiceStatistics::on_realTimeDarkPushButton_pressed()
{
   open_statistics_tab(5);
}

void GameChoiceStatistics::on_realTimeHordePushButton_pressed()
{
    open_statistics_tab(6);
}

void GameChoiceStatistics::on_realTimeAlicePushButton_pressed()
{
    open_statistics_tab(7);
}

void GameChoiceStatistics::on_returnPushButton_pressed()
{
    close();
}
