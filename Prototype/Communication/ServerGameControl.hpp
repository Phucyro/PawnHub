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
  void receiveBoard(std::string);
  void receiveUpdate(std::string);
  void receivePlayerColour(std::string);
  void receiveTurn(std::string);
  void receiveAskMove(std::string);
  void receiveMove(std::string);

public:
  void sendBoard(std::string);
  void sendAskMove();

  std::map<char, void(ServerGameControl::*)(std::string)> headerReceiveMap = {
    {'B', &ServerGameControl::receiveBoard},
    {'U', &ServerGameControl::receiveUpdate},
    {'X', &ServerGameControl::receivePlayerColour},
    {'T', &ServerGameControl::receiveTurn},
    {'A', &ServerGameControl::receiveAskMove},
    {'M', &ServerGameControl::receiveMove},
  };

  void handleMessage();
  void startParty();
};

#endif
