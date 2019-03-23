#include "gameChoice.h"
#include "ui_gameChoice.h"
#include "gameWithoutChat.h"
#include "gameWithoutChatWithAlice.h"

GameChoice::GameChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameChoice)
{
    ui->setupUi(this);
}

GameChoice::~GameChoice()
{
    delete ui;
}


void GameChoice::on_classicPushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat;
    this->hide();
    game->exec();
    this->show();
    delete game;
}
void GameChoice::on_darkPushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat;
    this->hide();
    game->exec();
    this->show();
    delete game;
}
void GameChoice::on_hordePushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat;
    this->hide();
    game->exec();
    this->show();
    delete game;
}
void GameChoice::on_alicePushButton_pressed()
{
    GameWithoutChatWithAlice* game = new GameWithoutChatWithAlice;
    this->hide();
    game->exec();
    this->show();
    delete game;
}

void GameChoice::on_realTimeClassicPushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat;
    this->hide();
    game->exec();
    this->show();
    delete game;
}

void GameChoice::on_realTimeDarkPushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat;
    this->hide();
    game->exec();
    this->show();
    delete game;
}

void GameChoice::on_realTimeHordePushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat;
    this->hide();
    game->exec();
    this->show();
    delete game;
}

void GameChoice::on_realTimeAlicePushButton_pressed()
{
    GameWithoutChatWithAlice* game = new GameWithoutChatWithAlice;
    this->hide();
    game->exec();
    this->show();
    delete game;
}

void GameChoice::on_returnPushButton_pressed()
{
    exit(0);
}
