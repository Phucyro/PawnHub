#include "thread"
#include <string>
#include <map>
#include <functional>

#include "../../Communication/Socket.hpp"

#include "../MainMenu/gameWithoutChat.h"
#include "../MainMenu/gameWithoutChatWithAlice.h"

#ifndef CCONTROL_H
#define CCONTROL_H

class ClientGameControl : public QObject {

    Q_OBJECT

private:
  Socket* socket;
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
   {"askmove", "A"},
   {"promote", "P"},
   {"move", "M"},
  };



public:
  ClientGameControl(Socket*, GameWithoutChat*);
  ClientGameControl(Socket*, GameWithoutChatWithAlice*);
  ~ClientGameControl();

public slots:
  void startParty();
  void sendMove(std::string);
  void sendPromotion(std::string);
  void setGameOngoing(bool);
  void setRealTime();

signals:
  void receiveBoard(QString);
  void receiveUpdate(QString);
  void receiveGameMode(QString);
  void receivePlayerColour(QString);
  void receiveTurn(QString);
  void receiveAskMove(QString);
  void receiveAskPromotion(QString);

  void finished();

private:
  void handleMessage();

  std::map<char, void(ClientGameControl::*)(QString)> headerReceiveMap = {
    {'B', &ClientGameControl::receiveBoard},
    {'U', &ClientGameControl::receiveUpdate},
    {'G', &ClientGameControl::receiveGameMode},
    {'X', &ClientGameControl::receivePlayerColour},
    {'T', &ClientGameControl::receiveTurn},
    {'A', &ClientGameControl::receiveAskMove},
    {'P', &ClientGameControl::receiveAskPromotion},
  };
  void listenSocketAndKeyboard();
};

#endif
