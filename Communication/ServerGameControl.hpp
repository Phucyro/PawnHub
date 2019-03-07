#include <string>
#include <map>
#include <functional>

#include "Socket.hpp"
#include "../Code/Player.hpp"
#include "../Code/Game.hpp"
#include "ExecInfoThread.hpp"

#ifndef _SCONTROL_H_
#define _SCONTROL_H_

class Classic;

class ServerGameControl {
private:
  Player *player1, *player2;
  Game *game;
  ExecInfoThread* info;

  std::map<std::string, std::string> headerSendMap = {
   {"board", "B"},
   {"update", "U"},
   {"colour", "X"},
   {"gamemode", "G"},
   {"turn", "T"},
   {"askmove", "A"},
   {"move", "M"},
   {"promote", "P"},
  };

	void _playerDisconected(Socket*);

public:
  ServerGameControl(Player*, Player*, Game*, ExecInfoThread*);
  ServerGameControl(const ServerGameControl&);
  ServerGameControl& operator=(const ServerGameControl&);
  ~ServerGameControl();

private:
  void receiveMove(std::string);
  void receivePromotion(std::string);

public:
  void sendBoard(Socket*, std::string);
  void sendFirstBoard(Socket*, std::string);
  void sendSecondBoard(Socket*, std::string);
  void sendUpdate(Socket*, std::string);
  void sendStart(Socket*);
  void sendCheck(Socket*);
  void sendCheckmate(Socket*, std::string);
  void sendStalemate(Socket*);
  void sendGameMode(Socket*, std::string);
  void sendPlayerColour(Socket*, std::string);
  void sendTurn(Socket*, unsigned);
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
