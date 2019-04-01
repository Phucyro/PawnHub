#include "statisticsTab.h"
#include "ui_statisticsTab.h"

#include "gameChoiceStatistics.h"
#include "../Modified_Files/ClientFunctions.hpp"
#include "../../Communication/SplitString.hpp"             // A modifier ici

#include <vector>
#include <string>
#include <iostream>


StatisticsTab::StatisticsTab(int t, Client *c, int mode, QWidget *parent) : // Rajouter client pour pouvoir y accéder
    QDialog(parent),
    ui(new Ui::StatisticsTab),
    type(t),
    client(c),
    gamemode(mode)
{
    ui->setupUi(this);

    if (t == 0)
      setupStats(true);
    else
      setupStats(false);
}

void StatisticsTab::setupStats(bool mine){
    unsigned int rows = (mine ? 8 : 10);
    unsigned int columns = 5;
  ui->statisticsTableWidget->setRowCount(int(rows));
  ui->statisticsTableWidget->setColumnCount(int(columns));

  if (mine)
  {
      ui->statisticsTableWidget->setHorizontalHeaderLabels(QStringList({ "Gamemode", "Win", "Lose", "Tie", "Elo" }));
      checkMyStat(client->getSocket());
  }
  else
  {
      ui->statisticsTableWidget->setHorizontalHeaderLabels(QStringList({ "Username", "Win", "Lose", "Tie", "Elo" }));
      viewLadder(client->getSocket(), std::to_string(getGamemode()));
  }
  ui->statisticsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//disable editing

  for (unsigned int a = 0; a < rows; ++a){
    std::vector<std::string> stat = splitString(client->readPipe(), ' ');
    for (unsigned int b = 0; b < stat.size()-1; ++b){
      std::string temp = stat[b+1];
      ui->statisticsTableWidget->setItem(int(a), int(b), new QTableWidgetItem(QString::fromStdString(temp)));
    }
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
