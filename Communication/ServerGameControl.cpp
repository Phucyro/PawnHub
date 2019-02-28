#include "ServerGameControl.hpp"

ServerGameControl::ServerGameControl(Player* _player1, Player* _player2, Game* _game): player1(_player1), player2(_player2), game(_game) {
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

void ServerGameControl::sendBoard(Socket* socket, std::string board) {
  std::string header = headerSendMap["board"];
  socket->sendMessage(header + board);
  sendTurn(socket, game->getTurn());
}

void ServerGameControl::sendUpdate(Socket* socket, std::string update) {
  std::string header = headerSendMap["update"];
  socket->sendMessage(header + update);
}

void ServerGameControl::sendGameMode(Socket* socket, std::string mode) {
  std::string header = headerSendMap["gamemode"];
  socket->sendMessage(header + mode);
}

void ServerGameControl::sendPlayerColour(Socket* socket, std::string colour) {
  std::string header = headerSendMap["colour"];
  socket->sendMessage(header + colour);
}

void ServerGameControl::sendTurn(Socket* socket, unsigned turn) {
  std::string header = headerSendMap["turn"];
  socket->sendMessage(header + std::to_string(turn));
}

void ServerGameControl::sendAskMove(Socket* socket) {
  std::string header = headerSendMap["askmove"];
  socket->sendMessage(header + "gimme");
}

void ServerGameControl::sendAskPromotion(Socket* socket) {
  std::string header = headerSendMap["promote"];
  socket->sendMessage(header + "please");
}

void ServerGameControl::handleMessage(Socket* socket) {
  std::string message = socket->receiveMessage();
  char header = message[0];
  (this->*(headerReceiveMap[header]))(message.erase(0,1));
}

void ServerGameControl::startParty() {
  player1->setControl(this);
  player2->setControl(this);
  game->start();
}
