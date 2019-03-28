#ifndef CCONTROL_H
#define CCONTROL_H

// #include "thread" // ?
#include <string>
#include <map>
#include <functional>

#include "../../Communication/Client.hpp"

#include "../MainMenu/gameWithoutChat.h"
#include "../MainMenu/gameWithoutChatWithAlice.h"

class QIcon;

class ClientGameControl : public QObject {

    Q_OBJECT

private:
  Client* client;
  GameWithoutChat* game;
  GameWithoutChatWithAlice* alice_game;
  bool game_ongoing;
  bool is_alice;
  bool is_real_time;
  char colour;

  std::map<std::string, std::string> headerSendMap = {
    {"board", "B"},
    {"update", "U"},
    {"gamemode", "G"},
    {"colour", "X"},
    {"turn", "T"},
    {"time", "C"},
    {"askmove", "A"},
    {"promote", "P"},
    {"move", "M"},
    {"goodmove", "L"},
    {"first", "F"},
    {"goodpremove", "D"}
  };



public:
  ClientGameControl(Client*, GameWithoutChat*);
  ClientGameControl(Client*, GameWithoutChatWithAlice*);
  ~ClientGameControl();

  void callPieceUpdate(QIcon, QString, QString);

public slots:
  void startParty();
  void sendMove(QString);
  void sendPromotion(QString);
  void setGameOngoing(bool);
  void setRealTime();

signals:
  void updatePiece(QIcon, QString, QString);
  void receiveUpdate(QString);
  void receiveGameMode(QString);
  void receivePlayerColour(QString);
  void receiveTurn(QString);
  void receiveTime(QString);
  void receiveAskMove(QString);
  void receiveAskPromotion(QString);

  void pauseTimer();
  void reduceTimer(int);
  void finished();

private:
  void handleMessage();
  void receiveBoard(QString);
  void receiveGoodMove(QString);
  void receiveFirstMessage(QString);
  void receiveGoodPremove(QString);
  void cleanOldMsg();

  std::map<char, void(ClientGameControl::*)(QString)> headerReceiveMap = {
    {'B', &ClientGameControl::receiveBoard},
    {'U', &ClientGameControl::receiveUpdate},
    {'G', &ClientGameControl::receiveGameMode},
    {'X', &ClientGameControl::receivePlayerColour},
    {'T', &ClientGameControl::receiveTurn},
    {'C', &ClientGameControl::receiveTime},
    {'A', &ClientGameControl::receiveAskMove},
    {'P', &ClientGameControl::receiveAskPromotion},
    {'L', &ClientGameControl::receiveGoodMove},
    {'F', &ClientGameControl::receiveFirstMessage},
    {'D', &ClientGameControl::receiveGoodPremove},
  };
};

#endif
