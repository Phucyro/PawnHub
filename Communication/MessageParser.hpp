#include <map>
#include <string>
#include <functional>

#include "Socket.hpp"
#include "SplitString.hpp"
#include "ServerHandler.hpp"

#ifndef _MSGPARSER_H_
#define _MSGPARSER_H_

// how to differentiate between different games?
// - pass identifier into string? need global objects for identification
// - pass as attribute into receive functions

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
 {"move", "M"},
 {"quit", "0"},
 {"register", "1"},
 {"login", "2"},
 {"chat", "3"},
 {"play", "4"},
 {"leave", "5"}
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

void sendQuit(Socket socket) {
  std::string header = headerSendMap["quit"];
  socket.sendMessage(header);
}

void sendRegister(Socket socket, std::string username, std::string password) {
  std::string header = headerSendMap["register"];
  socket.sendMessage(header + username + " " + password);
}

void sendLogin(Socket socket, std::string username, std::string password) {
  std::string header = headerSendMap["login"];
  socket.sendMessage(header + username + " " + password);
}

void sendPlayRequest(Socket socket, unsigned int game_type) {
  std::string header = headerSendMap["play"];
  socket.sendMessage(header + std::to_string(game_type));
}

void sendLeaveQueue(Socket socket) {
  std::string header = headerSendMap["leave"];
  socket.sendMessage(header);
}

void sendChat(Socket socket, std::string sender, std::string target, std::string text) {
  std::string header = headerSendMap["chat"];
  socket.sendMessage(header + " " + sender + " " + target + " " + text);
}

// Receive Functions
void receiveBoard(Socket socket, std::string message) {std::cout << message << std::endl;}
void receiveUpdate(Socket socket, std::string message) {std::cout << message << std::endl;}
void receivePlayerColour(Socket socket, Socket socket, std::string message) {std::cout << message << std::endl;}
void receiveTurn(Socket socket, std::string message) {std::cout << message << std::endl;}
void receiveCheckResult(Socket socket, std::string message) {std::cout << message << std::endl;}
void receiveMove(Socket socket, std::string message) {std::cout << message << std::endl;}
void receiveQuit(Socket socket, std::string message) {}
void receiveRegister(Socket socket, std::string message) {
  std::vector<std::string> user_info = splitString(message, ' ');
  signUpHandler(&socket, data, user_info[0], user_info[1]);
}
void receiveLogin(Socket socket, std::string message) {
  std::vector<std::string> user_info = splitString(message, ' ');
  signInHandler(&socket, players_map, data, &player, user_info[0], user_info[1]);
}
void receivePlayRequest(Socket socket, std::string message) {}
void receiveLeaveQueue(Socket socket, std::string message) {}
void receiveChat(Socket socket, std::string message) {}

std::map<char, std::function<void(Socket, std::string)>> headerReceiveMap = {
  {'B', &receiveBoard},
  {'U', &receiveUpdate},
  {'P', &receivePlayerColour},
  {'T', &receiveTurn},
  {'C', &receiveCheckResult},
  {'M', &receiveMove},
  {"0", &receiveQuit},
  {"1", &receiveRegister},
  {"2", &receiveLogin},
  {"3", &receivePlayRequest},
  {"4", &receiveLeaveQueue},
  {"5", &receiveChat}
};

// Receive Parser
void handleMessage(Socket socket) {
  std::string message = socket.receiveMessage();
  char header = message[0];
  headerReceiveMap[header](socket, message.erase(0,1));
}

#endif
