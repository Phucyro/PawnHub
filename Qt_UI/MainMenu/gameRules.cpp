#include "gameRules.h"
#include "ui_gameRules.h"


GameRules::GameRules(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameRules)
{
    ui->setupUi(this);
}

GameRules::~GameRules()
{
    delete ui;
}


void GameRules::on_classicPushButton_pressed()
{
    ui->rulesTextEdit->clear();
    ui->rulesTextEdit->appendPlainText("Classic");
}
void GameRules::on_darkPushButton_pressed()
{
    ui->rulesTextEdit->clear();
    ui->rulesTextEdit->appendPlainText("Dark");
}
void GameRules::on_hordePushButton_pressed()
{
    ui->rulesTextEdit->clear();
    ui->rulesTextEdit->appendPlainText("Horde");
}
void GameRules::on_alicePushButton_pressed()
{
    ui->rulesTextEdit->clear();
    ui->rulesTextEdit->appendPlainText("Alice");
}

void GameRules::on_realTimeClassicPushButton_pressed()
{
    ui->rulesTextEdit->clear();
    ui->rulesTextEdit->appendPlainText("Realtime Classic");
}

void GameRules::on_realTimeDarkPushButton_pressed()
{
    ui->rulesTextEdit->clear();
    ui->rulesTextEdit->appendPlainText("Realtime Dark");
}

void GameRules::on_realTimeHordePushButton_pressed()
{
    ui->rulesTextEdit->clear();
    ui->rulesTextEdit->appendPlainText("Realtime Horde");
}

void GameRules::on_realTimeAlicePushButton_pressed()
{
    ui->rulesTextEdit->clear();
    ui->rulesTextEdit->appendPlainText("Realtime Alice");
}

void GameRules::on_returnPushButton_pressed()
{
    close();
}
