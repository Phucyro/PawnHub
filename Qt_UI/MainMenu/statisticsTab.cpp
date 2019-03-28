#include "statisticsTab.h"
#include "ui_statisticsTab.h"
#include "gameChoiceStatistics.h"
#include <iostream>
#include "../Modified_Files/ClientFunctions.hpp"
#include "../../Communication/SplitString.hpp"             // A modifier ici
#include <vector>
#include <string>


StatisticsTab::StatisticsTab(int t, Client *c, int mode, QWidget *parent) : // Rajouter client pour pouvoir y accéder
    QDialog(parent),
    ui(new Ui::StatisticsTab),
    type(t),
    client(c),
    gamemode(mode)
{
    ui->setupUi(this);

    if (t == 0)
      setupMyStats();
    else
      setupGlobalStats();
}

void StatisticsTab::setupMyStats(){
  ui->staisticsTableWidget->setHorizontalHeaderLabels(QStringList({ "Name", "Win", "Lose", "Tie" }));
  ui->staisticsTableWidget->horizontalHeader()->setVisible(true);


  checkMyStat(client->getSocket());
  ui->staisticsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//disable editing
  ui->staisticsTableWidget->setRowCount(8);
  ui->staisticsTableWidget->setColumnCount(4);

  for (unsigned int a = 0; a < 8; ++a){
    std::vector<std::string> stat = splitString(client->readPipe(), ' ');
    for (unsigned int b = 0; b < stat.size()-1; ++b){
      std::string temp = stat[b+1];
      ui->staisticsTableWidget->setItem(a,b,new QTableWidgetItem(QString::fromStdString(temp)));
    }
    //std::cout << strVectorToStr(stat) << std::endl;
  }
}

void StatisticsTab::setupGlobalStats(){
  ui->staisticsTableWidget->setHorizontalHeaderLabels(QStringList({ "Gametype", "Win", "Lose", "Tie" }));
  ui->staisticsTableWidget->horizontalHeader()->setVisible(true);

  viewLadder(client->getSocket(), std::to_string(getGamemode()));
  ui->staisticsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//disable editing
  ui->staisticsTableWidget->setRowCount(10);
  ui->staisticsTableWidget->setColumnCount(4);

  for (unsigned int a = 0; a < 10; ++a){
    std::vector<std::string> stat = splitString(client->readPipe(), ' ');
    for (unsigned int b = 0; b < stat.size()-1; ++b){
      std::string temp = stat[b+1];
      ui->staisticsTableWidget->setItem(a,b,new QTableWidgetItem(QString::fromStdString(temp)));
    }
    //std::cout << strVectorToStr(stat) << std::endl;
  }
}

StatisticsTab::~StatisticsTab()
{
    delete ui;
}

void StatisticsTab::on_returnPushButton_pressed()
{
    close();
}

int StatisticsTab::getGamemode()
{
    return gamemode;
}
