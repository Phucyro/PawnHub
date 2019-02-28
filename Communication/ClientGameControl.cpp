#include "ClientGameControl.hpp"

ClientGameControl::ClientGameControl(Socket _socket): board(), socket(_socket) {
  startParty();
}

void ClientGameControl::receiveBoard(std::string message) {
  board.draw_pieces(message);
}

void ClientGameControl::receiveUpdate(std::string message) {
  if (message == "start") {
    board.init_ncurses();
  }
  else if (message == "check") {
    //board.declare_check();
  }
  else {
    //board.endgame(message)      // either stalemate or checkmate
  }
}

void ClientGameControl::receiveGameMode(std::string message) {
  const char* msg = message.c_str();
  board.set_mode(msg);
}

void ClientGameControl::receivePlayerColour(std::string message) {
  const char* msg = message.c_str();
  board.set_colour(msg);
}

void ClientGameControl::receiveTurn(std::string message) {
  const char* msg = message.c_str();
  board.update_turn(msg);
}

void ClientGameControl::receiveAskMove(std::string message) {
  std::string move = board.get_movement();
  sendMove(move);
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
  while(true) {handleMessage();}
}
