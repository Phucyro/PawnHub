#include "gameChoice.h"
#include "ui_gameChoice.h"
#include "gameWithoutChat.h"
#include "gameWithoutChatWithAlice.h"
#include "message.h"

#include "../../Communication/Client.hpp"
#include "../Modified_Files/ClientFunctions.hpp"

GameChoice::GameChoice(QWidget *parent, Client* client_) :
    QDialog(parent),
    ui(new Ui::GameChoice),
    client(client_)
{
    ui->setupUi(this);
}

GameChoice::~GameChoice()
{
    delete ui;
}

void GameChoice::send_game_request(std::string gameMode)
{
    playGame(client->getSocket(), gameMode);

    Message message;
    message.set_title("In Queue");
    message.set_text("You have been placed in queue, please wait for an opponent.");
    message.popup();
    this->hide();
}

void GameChoice::on_classicPushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat(nullptr, client->getSocket());
    send_game_request("0");

    game->start();
    game->close();
    delete game;
    this->close();
}
void GameChoice::on_darkPushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat(nullptr, client->getSocket());
    game->setWindowTitle("Dark Chess");

    this->hide();
    game->exec();
    delete game;
}
void GameChoice::on_hordePushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat(nullptr, client->getSocket());
    game->setWindowTitle("Horde Chess");

    this->hide();
    game->exec();

    delete game;
}
void GameChoice::on_alicePushButton_pressed()
{
    GameWithoutChatWithAlice* game = new GameWithoutChatWithAlice;

    this->hide();
    game->exec();
    delete game;
}

void GameChoice::on_realTimeClassicPushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat(nullptr, client->getSocket());
    game->setWindowTitle("Classic Chess - Real Time");

    this->hide();
    game->exec();
    delete game;
}

void GameChoice::on_realTimeDarkPushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat(nullptr, client->getSocket());
    game->setWindowTitle("Dark Chess - Real Time");

    this->hide();
    game->exec();
    delete game;
}

void GameChoice::on_realTimeHordePushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat(nullptr, client->getSocket());
    game->setWindowTitle("Horde Chess - Real Time");

    this->hide();
    game->exec();
    delete game;
}

void GameChoice::on_realTimeAlicePushButton_pressed()
{
    GameWithoutChatWithAlice* game = new GameWithoutChatWithAlice;
    game->setWindowTitle("Alice Chess - Real Time");

    this->hide();
    game->exec();
    delete game;
}

void GameChoice::on_returnPushButton_pressed()
{
    close();
}
