#include "ClientGameControl.hpp"

ClientGameControl::ClientGameControl(Socket& _socket): board(), socket(_socket), game_ongoing(false), is_alice(false) {
  startParty();
}

void ClientGameControl::receiveBoard(std::string message) {
  if (!is_alice) {
    board.draw_pieces(message);
  }
  else if (message[0] == '1') {
    board.draw_pieces(message.erase(0,1));
  }
  else {
    board.draw_alice_pieces(message.erase(0,1));
  }
}

void ClientGameControl::receiveUpdate(std::string message) {
  if (message == "start") {
    board.init_ncurses();
  }
  else if (message == "alice") {
    is_alice = true;
    board.draw_alice_board();
  }
  else if (message == "check") {
    board.declare_check();
  }
  else {
    game_ongoing = false;
    if (message == "stalemate") {
      message = "Stalemate !";
    }
    else if (message == "surrend") {
      message = "You win: your oppenent gave up !";
    }
    else if (message == "white"){
      message = "Checkmate: white player won !";
    }
    else {
      message = "Checkmate: black player won !";
    }
    board.endgame(message.c_str());
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
  if (move == "/end"){
  	game_ongoing = false;
  	board.clear_board();
  	board.endgame("You gave up.");
  }
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
  game_ongoing = true;
  while(game_ongoing) {handleMessage();}
  board.exit();
}
