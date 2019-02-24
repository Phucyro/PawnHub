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

void ServerGameControl::receiveMove(std::string message) {
  std::cout << "Received move" << message << std::endl;
  player1->receiveMove(message);
  player2->receiveMove(message);
}

void ServerGameControl::receivePromotion(std::string message) {
  player1->receivePromotion(message);
  player2->receivePromotion(message);
}

void ServerGameControl::sendBoard(std::string board) {
  std::string header = headerSendMap["board"];
  socket.sendMessage(header + board);
}

void ServerGameControl::sendUpdate(std::string update) {
  std::string header = headerSendMap["update"];
  socket.sendMessage(header + update);
}

void ServerGameControl::sendPlayerColour(std::string colour) {
  std::string header = headerSendMap["colour"];
  socket.sendMessage(header + colour);
}

void ServerGameControl::sendTurn(int turn) {
  std::string header = headerSendMap["turn"];
  socket.sendMessage(header + std::to_string(turn));
}

void ServerGameControl::sendAskMove() {
  std::string header = headerSendMap["askmove"];
  socket.sendMessage(header + "gimme");
}

void ServerGameControl::sendAskPromotion() {
  std::string header = headerSendMap["promote"];
  socket.sendMessage(header + "please");
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
