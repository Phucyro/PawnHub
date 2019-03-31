#ifndef GAMECHOICE_H
#define GAMECHOICE_H

#include "gameWithoutChat.h"
#include "gameWithoutChatWithAlice.h"

#include <QDialog>

#include <thread>

#include "message.h"

class Client;

namespace Ui {
class GameChoice;
}

class GameChoice : public QDialog
{
    Q_OBJECT

public:
    explicit GameChoice(QWidget *parent = nullptr, Client* client_=nullptr);
    ~GameChoice();

private:
    Ui::GameChoice *ui;
    Client* client;
    std::thread* msgThread;
    bool cancel;
    Message message;

    void send_game_request(std::string);
    void run_game(GameWithoutChat* game);
    void run_game(GameWithoutChatWithAlice* game);
    void closeMessage(){message.close();}

private slots:
    void on_classicPushButton_pressed();
    void on_darkPushButton_pressed();
    void on_hordePushButton_pressed();
    void on_alicePushButton_pressed();

    void on_realTimeClassicPushButton_pressed();
    void on_realTimeDarkPushButton_pressed();
    void on_realTimeHordePushButton_pressed();
    void on_realTimeAlicePushButton_pressed();

    void on_returnPushButton_pressed();
};

#endif // GAMECHOICE_H
