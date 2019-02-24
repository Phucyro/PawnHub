#include <string>
#include <map>
#include <functional>

#include "Socket.hpp"
#include "../GameLogic/Player.hpp"
#include "../GameLogic/Classic.hpp"

#ifndef _SCONTROL_H_
#define _SCONTROL_H_

class Classic;

class ServerGameControl {
private:
  Socket socket;
  Player *player1, *player2;
  Classic *game;

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
  ServerGameControl(Socket);
  ~ServerGameControl();

private:
  void receiveMove(std::string);
  void receivePromotion(std::string);

public:
  void sendBoard(std::string);
  void sendUpdate(std::string);
  void sendPlayerColour(std::string);
  void sendTurn(int);
  void sendAskMove();
  void sendAskPromotion();

  std::map<char, void(ServerGameControl::*)(std::string)> headerReceiveMap = {
    {'M', &ServerGameControl::receiveMove},
    {'P', &ServerGameControl::receivePromotion},
  };

  void handleMessage();
  void startParty();
};

#endif
