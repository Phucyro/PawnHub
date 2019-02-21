#include "ServerGameControl.hpp"

ServerGameControl::ServerGameControl(Socket _socket): socket(_socket), player1(nullptr), player2(nullptr), game(nullptr) {
  player1 = new Player(&socket);
  player2 = new Player(&socket);
  game = new Classic(player1, player2);
  startParty();
}

ServerGameControl::~ServerGameControl() {
  delete player1;
  delete player2;
  delete game;
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

void ServerGameControl::receiveAskMove(std::string message) {
  std::cout << message << std::endl;
}

void ServerGameControl::receiveMove(std::string message) {
  player1->receiveMove(message);
  player2->receiveMove(message);
}

void ServerGameControl::sendBoard(std::string board) {
  std::string header = headerSendMap["board"];
  socket.sendMessage(header + board);
}

void ServerGameControl::sendAskMove() {
  std::string header = headerSendMap["askmove"];
  socket.sendMessage(header + "gimme");
}

void ServerGameControl::handleMessage() {
  std::string message = socket.receiveMessage();
  char header = message[0];
  (this->*(headerReceiveMap[header]))(message.erase(0,1));
}

void ServerGameControl::startParty() {
  player1->setControl(this);
  player2->setControl(this);
  game->start();
}
