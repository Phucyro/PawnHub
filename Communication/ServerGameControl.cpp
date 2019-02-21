#include "ServerGameControl.hpp"

ServerGameControl::ServerGameControl(Socket _socket, Player _player): socket(_socket), player(_player) {
  game = Classic(&player, &player);
  game.start();
}

void ServerGameControl::receiveUpdate(std::string message) {
  std::cout << message << std::endl;
}

void ServerGameControl::receivePlayerColour(std::string message) {
  std::cout << message << std::endl;
}

void ServerGameControl::receiveTurn(std::string message) {
  std::cout << message << std::endl;
}

void ServerGameControl::receiveCheckResult(std::string message) {
  std::cout << message << std::endl;
}

void ServerGameControl::receiveMove(std::string message) {
  player.receiveMove(message);
}

void ServerGameControl::sendBoard(std::string move) {
  std::string header = headerSendMap["board"];
  socket.sendMessage(header + move);
}

void ServerGameControl::sendCheckResult(bool move_check) {
  std::string header = headerSendMap["board"];
  socket.sendMessage(header + std::to_string(move_check));
}

void ServerGameControl::handleMessage() {
  std::string message = socket.receiveMessage();
  char header = message[0];
  (this->*(headerReceiveMap[header]))(message.erase(0,1));
}
