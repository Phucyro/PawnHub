#include "statisticsChoice.h"
#include "ui_statisticsChoice.h"
#include "gameChoiceStatistics.h"

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
    GameChoiceStatistics* choice = new GameChoiceStatistics(0,client);
    this->hide();
    choice->exec();
    this->show();
    delete choice;
}


void StatisticsChoice::on_globalPushButton_pressed()
{
    GameChoiceStatistics* choice = new GameChoiceStatistics(1,client);
    this->hide();
    choice->exec();
    this->show();
    delete choice;
}
