#include "ClientGameControl.hpp"

ClientGameControl::ClientGameControl(Socket _socket): board(), socket(_socket) {
  startParty();
}

void ClientGameControl::receiveBoard(std::string message) {
  board.draw_pieces(message);
}

void ClientGameControl::receiveUpdate(std::string message) {
  std::cout << message << std::endl;
}

void ClientGameControl::receivePlayerColour(std::string message) {
  std::cout << message << std::endl;
}

void ClientGameControl::receiveTurn(std::string message) {
  std::cout << message << std::endl;
}

void ClientGameControl::receiveAskMove(std::string message) {
  std::string move = board.get_movement();
  sendMove(move);
  // sendMove(board.get_movement());
}

void ClientGameControl::receiveAskPromotion(std::string message) {
  std::string promotion = board.get_promotion();
  sendPromotion(promotion);
}

void ClientGameControl::sendMove(std::string move) {
  std::string header = headerSendMap["move"];
  socket.sendMessage(header + move);
}

void ClientGameControl::sendPromotion(std::string promotion) {
  std::string header = headerSendMap["promote"];
  socket.sendMessage(header + promotion);
}

void ClientGameControl::handleMessage() {
  std::string message = socket.receiveMessage();
  char header = message[0];
  (this->*(headerReceiveMap[header]))(message.erase(0,1));
}

void ClientGameControl::startParty() {
  socket.sendMessage("4 0");
  if (socket.receiveMessage() == "4") {std::cout << "Placed in Queue" << std::endl;}
  board.init_ncurses();
  while(true) {handleMessage();}
}
