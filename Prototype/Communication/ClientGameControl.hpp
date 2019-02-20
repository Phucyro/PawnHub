#include <string>
#include <map>
#include <functional>

#include "Socket.hpp"
#include "../GameDisplay/board.hpp"

#ifndef _CCONTROL_H_
#define _CCONTROL_H_

class ClientGameControl {
private:
  Board board;
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
  ClientGameControl(Socket);

private:
  void receiveBoard(std::string);
  void receiveUpdate(std::string);
  void receivePlayerColour(std::string);
  void receiveTurn(std::string);
  void receiveCheckResult(std::string);
  void receiveMove(std::string);

  void sendMove(std::string move);

  std::map<char, void(ClientGameControl::*)(std::string)> headerReceiveMap = {
    {'B', &ClientGameControl::receiveBoard},
    {'U', &ClientGameControl::receiveUpdate},
    {'P', &ClientGameControl::receivePlayerColour},
    {'T', &ClientGameControl::receiveTurn},
    {'C', &ClientGameControl::receiveCheckResult},
    {'M', &ClientGameControl::receiveMove},
  };

  void handleMessage();
  void startParty();
};

#endif
