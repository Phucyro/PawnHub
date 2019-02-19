#include <map>
#include <string>
#include <functional>

#include "Socket.hpp"

#ifndef _MSGPARSER_H_
#define _MSGPARSER_H_

/*
IN-GAME
Server sends:
- 'B', board
- 'U', status update
- 'P', player colour
- 'T', turn
- 'C', move check
Server receives:
- 'M', player move

LOGIN
*/

std::map<std::string, std::string> headerSendMap = {
 {"board", "B"},
 {"update", "U"},
 {"colour", "P"},
 {"turn", "T"},
 {"movecheck", "C"},
 {"move", "M"}
};

// Send Functions
void sendBoard(Socket socket, std::string board) {
  std::string header = headerSendMap["board"];
  socket.sendMessage(header + board);
}

void sendUpdate(Socket socket, std::string status) {
  std::string header = headerSendMap["update"];
  socket.sendMessage(header + status);
}

void sendPlayerColour(Socket socket, std::string colour) {
  std::string header = headerSendMap["colour"];
  socket.sendMessage(header + colour);
}

void sendTurn(Socket socket, int turn) {
  std::string header = headerSendMap["turn"];
  socket.sendMessage(header + std::to_string(turn));
}

void sendCheckResult(Socket socket, bool movecheck) {
  std::string header = headerSendMap["movecheck"];
  socket.sendMessage(header + std::to_string(movecheck));
}

void sendMove(Socket socket, std::string move) {
  std::string header = headerSendMap["move"];
  socket.sendMessage(header + move);
}

// Receive Functions
void receiveBoard(std::string message) {std::cout << message << std::endl;}
void receiveUpdate(std::string message) {std::cout << message << std::endl;}
void receivePlayerColour(std::string message) {std::cout << message << std::endl;}
void receiveTurn(std::string message) {std::cout << message << std::endl;}
void receiveCheckResult(std::string message) {std::cout << message << std::endl;}
void receiveMove(std::string message) {std::cout << message << std::endl;}

std::map<char, std::function<void(std::string)>> headerReceiveMap = {
  {'B', &receiveBoard},
  {'U', &receiveUpdate},
  {'P', &receivePlayerColour},
  {'T', &receiveTurn},
  {'C', &receiveCheckResult},
  {'M', &receiveMove}
};

// Receive Parser
void handleMessage(Socket socket) {
  std::string message = socket.receiveMessage();
  char header = message[0];
  headerReceiveMap[header](message.erase(0,1));
}

#endif
