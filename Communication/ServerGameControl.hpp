#include <string>
#include <map>
#include <functional>

#include "Socket.hpp"
#include "../Code/Player.hpp"
#include "../Code/Game.hpp"

#ifndef _SCONTROL_H_
#define _SCONTROL_H_

class Classic;

class ServerGameControl {
private:
  Player *player1, *player2;
  Game *game;

  std::map<std::string, std::string> headerSendMap = {
   {"board", "B"},
   {"update", "U"},
   {"colour", "X"},
   {"turn", "T"},
   {"askmove", "A"},
   {"move", "M"},
   {"promote", "P"},
   {"quit", "0"},
   {"register", "1"},
   {"login", "2"},
   {"chat", "3"},
   {"play", "4"},
   {"leave", "5"}
  };



public:
  ServerGameControl(Player*, Player*, Game*);
  ~ServerGameControl();

private:
  void receiveMove(std::string);
  void receivePromotion(std::string);

public:
  void sendBoard(Socket*, std::string);
  void sendUpdate(Socket*, std::string);
  void sendPlayerColour(Socket*, std::string);
  void sendTurn(Socket*, int);
  void sendAskMove(Socket*);
  void sendAskPromotion(Socket*);

  std::map<char, void(ServerGameControl::*)(std::string)> headerReceiveMap = {
    {'M', &ServerGameControl::receiveMove},
    {'P', &ServerGameControl::receivePromotion},
  };

  void handleMessage(Socket*);
  void startParty();
};

#endif
