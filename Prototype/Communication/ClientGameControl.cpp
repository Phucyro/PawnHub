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

void ClientGameControl::receiveCheckResult(std::string message) {
  std::cout << "Getting player movement" << std::endl;
  sendMove(board.get_movement());
}

void ClientGameControl::receiveMove(std::string message) {
  std::cout << "Weird: getting player movement" << std::endl;
  sendMove(board.get_movement());
}

void ClientGameControl::sendMove(std::string move) {
  std::string header = headerSendMap["move"];
  socket.sendMessage(header + " " + move);
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
