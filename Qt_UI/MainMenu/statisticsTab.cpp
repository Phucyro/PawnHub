#include "statisticsTab.h"
#include "ui_statisticsTab.h"

StatisticsTab::StatisticsTab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatisticsTab)
{
    ui->setupUi(this);
}

StatisticsTab::~StatisticsTab()
{
    delete ui;
}

void StatisticsTab::on_returnPushButton_pressed()
{
    close();
}
