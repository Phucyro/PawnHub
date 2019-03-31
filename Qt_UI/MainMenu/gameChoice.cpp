#include "gameChoice.h"
#include "ui_gameChoice.h"

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
}

void GameChoice::run_game(GameWithoutChat* game)
{
    this->hide();
    game->start();
    game->close();
    delete game;
    this->close();
}

void GameChoice::run_game(GameWithoutChatWithAlice* game)
{
    this->hide();
    game->start();
    game->close();
    delete game;
    this->close();
}

void GameChoice::on_classicPushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat(nullptr, client);
    send_game_request("0");

    run_game(game);
}
void GameChoice::on_darkPushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat(nullptr, client);
    game->setWindowTitle("Dark Chess");
    send_game_request("1");

    run_game(game);
}
void GameChoice::on_hordePushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat(nullptr, client);
    game->setWindowTitle("Horde Chess");
    send_game_request("2");

    run_game(game);
}
void GameChoice::on_alicePushButton_pressed()
{
    GameWithoutChatWithAlice* game = new GameWithoutChatWithAlice(nullptr, client);
    send_game_request("3");

    run_game(game);
}

void GameChoice::on_realTimeClassicPushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat(nullptr, client);
    game->setWindowTitle("Classic Chess - Real Time");
    send_game_request("4");

    run_game(game);
}

void GameChoice::on_realTimeDarkPushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat(nullptr, client);
    game->setWindowTitle("Dark Chess - Real Time");
    send_game_request("5");

    run_game(game);
}

void GameChoice::on_realTimeHordePushButton_pressed()
{
    GameWithoutChat* game = new GameWithoutChat(nullptr, client);
    game->setWindowTitle("Horde Chess - Real Time");
    send_game_request("6");

    run_game(game);
}

void GameChoice::on_realTimeAlicePushButton_pressed()
{
    GameWithoutChatWithAlice* game = new GameWithoutChatWithAlice(nullptr, client);
    game->setWindowTitle("Alice Chess - Real Time");
    send_game_request("7");

    run_game(game);
}

void GameChoice::on_returnPushButton_pressed()
{
    close();
}
