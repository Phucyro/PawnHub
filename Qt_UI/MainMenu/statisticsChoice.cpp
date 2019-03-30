#include "statisticsChoice.h"
#include "ui_statisticsChoice.h"
#include "gameChoiceStatistics.h"
#include "statisticsTab.h"

StatisticsChoice::StatisticsChoice(Client *c,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatisticsChoice),
    client(c)
{
    ui->setupUi(this);
}

StatisticsChoice::~StatisticsChoice()
{
    delete ui;
}

void StatisticsChoice::on_returnPushButton_pressed()
{
    close();
}

void StatisticsChoice::on_myStatsPushButton_pressed()
{
    StatisticsTab* stats = new StatisticsTab(0,client,0);
    stats->exec();
    delete stats;
}


void StatisticsChoice::on_globalPushButton_pressed()
{
    GameChoiceStatistics* choice = new GameChoiceStatistics(1,client);
    choice->exec();
    delete choice;
}
