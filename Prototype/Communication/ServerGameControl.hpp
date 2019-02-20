#include <string>
#include <map>
#include <functional>

#include "Socket.hpp"
#include "../GameLogic/Player.hpp"
#include "../GameLogic/Classic.hpp"

#ifndef _SCONTROL_H_
#define _SCONTROL_H_

class ServerGameControl {
private:
  Player player;
  Classic game;
  Socket socket;

  std::map<std::string, std::string> headerSendMap = {
   {"board", "B"},
   {"update", "U"},
   {"colour", "P"},
   {"turn", "T"},
   {"movecheck", "C"},
   {"move", "M"},
   {"quit", "0"},
   {"register", "1"},
   {"login", "2"},
   {"chat", "3"},
   {"play", "4"},
   {"leave", "5"}
  };



public:
  ServerGameControl(Socket, Player);

private:
  void receiveUpdate(std::string);
  void receivePlayerColour(std::string);
  void receiveTurn(std::string);
  void receiveCheckResult(std::string);
  void receiveMove(std::string);

  void sendBoard(std::string);
  void sendCheckControl(bool);

  std::map<char, void(ServerGameControl::*)(std::string)> headerReceiveMap = {
    {'B', &ServerGameControl::receiveBoard},
    {'U', &ServerGameControl::receiveUpdate},
    {'P', &ServerGameControl::receivePlayerColour},
    {'T', &ServerGameControl::receiveTurn},
    {'C', &ServerGameControl::receiveCheckResult},
    {'M', &ServerGameControl::receiveMove},
  };

  void handleMessage();
};

#endif
