#include "thread"
#include <string>
#include <map>
#include <functional>

#include "Socket.hpp"
#include "Timer.hpp"
#include "../Display/GameDisplay/board.hpp"

#ifndef _CCONTROL_H_
#define _CCONTROL_H_

class ClientGameControl {
private:
  Board board;
  Socket& socket;
  bool game_ongoing;
  bool is_alice;
  bool is_real_time;
  char _color;
  Timer timer;

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
  ClientGameControl(Socket&);

private:
  void receiveBoard(std::string);
  void receiveUpdate(std::string);
  void receiveGameMode(std::string);
  void receivePlayerColour(std::string);
  void receiveTurn(std::string);
  void receiveTime(std::string);
  void receiveGoodMove(std::string message);
  void receiveAskMove(std::string);
  void receiveAskPromotion(std::string);
  void receiveFirstMessage(std::string);
  void receiveGoodPremove(std::string);

  void sendMove(std::string);
  void sendPromotion(std::string);

  std::map<char, void(ClientGameControl::*)(std::string)> headerReceiveMap = {
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
  
  void handleMessage();
  void startParty();
  void cleanOldMsg();
};

#endif
