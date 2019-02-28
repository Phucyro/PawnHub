#include <string>
#include <map>
#include <functional>

#include "Socket.hpp"
#include "../Display/GameDisplay/board.hpp"

#ifndef _CCONTROL_H_
#define _CCONTROL_H_

class ClientGameControl {
private:
  Board board;
  Socket socket;

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
  ClientGameControl(Socket);

private:
  void receiveBoard(std::string);
  void receiveUpdate(std::string);
  void receiveGameMode(std::string);
  void receivePlayerColour(std::string);
  void receiveTurn(std::string);
  void receiveAskMove(std::string);
  void receiveAskPromotion(std::string);

  void sendMove(std::string);
  void sendPromotion(std::string);

  std::map<char, void(ClientGameControl::*)(std::string)> headerReceiveMap = {
    {'B', &ClientGameControl::receiveBoard},
    {'U', &ClientGameControl::receiveUpdate},
    {'G', &ClientGameControl::receiveGameMode},
    {'X', &ClientGameControl::receivePlayerColour},
    {'T', &ClientGameControl::receiveTurn},
    {'A', &ClientGameControl::receiveAskMove},
    {'P', &ClientGameControl::receiveAskPromotion},
  };

  void handleMessage();
  void startParty();
};

#endif
