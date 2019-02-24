#include "ClientGameControl.hpp"

ClientGameControl::ClientGameControl(Socket _socket): board(), socket(_socket) {
  std::cout << "Instantiating" << std::endl;
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
  std::cout << "Getting move" << std::endl;
  std::string move = board.get_movement();
  std::cout << "Requesting send of " << move << std::endl;
  sendMove(move);
  // sendMove(board.get_movement());
}

void ClientGameControl::receiveAskPromotion(std::string message) {
  std::cout << "Getting promotion" << std::endl;
  std::string promotion = board.get_promotion();
  std::cout << "Requesting send of " << promotion << std::endl;
  sendMove(promotion);
  sendPromotion("Gotta fetch it first");
}

void ClientGameControl::sendMove(std::string move) {
  std::string header = headerSendMap["move"];
  std::cout << "Sending Move as " << header + move << std::endl;
  socket.sendMessage(header + move);
}

void ClientGameControl::sendPromotion(std::string promotion) {
  std::string header = headerSendMap["promote"];
  std::cout << "Sending Promotion as " << header + promotion << std::endl;
  socket.sendMessage(header + promotion);
}

void ClientGameControl::handleMessage() {
  std::string message = socket.receiveMessage();
  char header = message[0];
  (this->*(headerReceiveMap[header]))(message.erase(0,1));
}

void ClientGameControl::startParty() {
  std::cout << "Starting Party" << std::endl;
  board.init_ncurses();
  while(true) {handleMessage();}
}
