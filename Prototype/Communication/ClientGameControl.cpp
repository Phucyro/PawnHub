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
  sendMove(board.get_movement());
}

void ClientGameControl::receiveMove(std::string message) {
  std::cout << "Getting move" << std::endl;
  std::string move = board.get_movement();
  std::cout << "Requesting send of " << move << std::endl;
  sendMove(move);
}

void ClientGameControl::sendMove(std::string move) {
  std::string header = headerSendMap["move"];
  std::cout << "Sending Move as " << header + " " + move << std::endl;
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
