#include "ClientGameControl.hpp"

#include "../MainMenu/gameWithoutChat.h"
#include "../MainMenu/gameWithoutChatWithAlice.h"

std::string moveToString(int*);

ClientGameControl::ClientGameControl(Socket* _socket, GameWithoutChat* _game): socket(_socket), game(_game), game_ongoing(true), is_alice(false), is_real_time(false), colour('\0') {
    connect(this, &ClientGameControl::receiveBoard, game, &GameWithoutChat::update_board);
    connect(this, &ClientGameControl::receiveUpdate, game, &GameWithoutChat::show_update);
    connect(this, &ClientGameControl::receiveGameMode, game, &GameWithoutChat::set_mode);
    connect(this, &ClientGameControl::receivePlayerColour, game, &GameWithoutChat::set_colour);
    connect(this, &ClientGameControl::receiveTurn, game, &GameWithoutChat::set_turn);
    connect(this, &ClientGameControl::receiveAskMove, game, &GameWithoutChat::get_move);
    connect(this, &ClientGameControl::receiveAskPromotion, game, &GameWithoutChat::get_promotion);

    connect(game, &GameWithoutChat::move_declared, this, &ClientGameControl::sendMove);
    connect(game, &GameWithoutChat::promotion_declared, this, &ClientGameControl::sendPromotion);
    connect(game, &GameWithoutChat::game_ongoing_changed, this, &ClientGameControl::setGameOngoing);
    connect(game, &GameWithoutChat::is_realtime, this, &ClientGameControl::setRealTime);
}

ClientGameControl::ClientGameControl(Socket* _socket, GameWithoutChatWithAlice* _game): socket(_socket), alice_game(_game), game_ongoing(true), is_alice(true), is_real_time(false), colour('\0') {
//  startParty();
}

ClientGameControl::~ClientGameControl()
{
    game = nullptr;
    socket = nullptr;
}

//void ClientGameControl::receiveBoard(QString message) {
//  if (!is_alice) {
//    board.draw_pieces(message);
//    board.refresh_board();
//  }
//  else if (message[0] == '1') {
//    stringToBoard(game, message.toStdString());
//  }
//  else {
//    board.draw_alice_pieces(message.erase(0,1));
//    board.refresh_board();
//  }
//}

void ClientGameControl::receiveUpdate(QString message) {
  if (message == "start") {
    game->show_update("Game has started.");
   }
  else if (message == "alice") {
//    board.draw_alice_board();
  }
  else if (message == "realtime") {
    is_real_time = true;
  }
  else if (message == "check") {
    game->show_update("Check: protect your king!");
  }
  else {
    game_ongoing = false;
//    game->set_gameOngoing(false);
    if (message == "stalemate") {
      message = "Stalemate!";
    }
    else if (message == "surrend") {
      message = "You win: your oppenent gave up!";
    }
    else if (message == "white"){
      message = "Checkmate: white player won!";
    }
    else {
      message = "Checkmate: black player won!";
    }
    game->show_update(message);
  }
}

void ClientGameControl::receiveGameMode(QString message) {
    game->set_mode(message);
}

void ClientGameControl::receivePlayerColour(QString message) {
  colour = message.toStdString()[0];
  game->set_colour(message);
}

void ClientGameControl::receiveTurn(QString message) {
  game->set_turn(message);
}

void ClientGameControl::receiveAskMove(QString message) {
    game->show_update("Your turn: please choose your move");

//  std::string move = board.get_movement();
//  if (game_ongoing){
//    sendMove(move);
//    if (move == "/end"){
//      game_ongoing = false;
//      board.clear_get_movement();
//      board.endgame("You gave up.");
//    }
//  }
}


void ClientGameControl::receiveAskPromotion(QString message) {
//    QString promotion = game->get_promotion();
//    sendPromotion(promotion.toStdString());
}

void ClientGameControl::sendMove(std::string move) {
  std::string header = headerSendMap["move"];
  socket->sendMessage("30~" + header + colour + move);
}

void ClientGameControl::sendPromotion(std::string promotion) {
  std::string header = headerSendMap["promote"];
  socket->sendMessage("30~" + header + promotion);
}

void ClientGameControl::setGameOngoing(bool value) {
    game_ongoing = value;
}

void ClientGameControl::setRealTime() {
    is_real_time = true;
}

void ClientGameControl::handleMessage() {
//  if (is_real_time) listenSocketAndKeyboard();
//  else{
    std::string message = socket->receiveMessage();
    char header = message[0];
    (this->*(headerReceiveMap[header]))(QString::fromStdString(message.erase(0,1)));
//  }
}

//void ClientGameControl::listenSocketAndKeyboard(){
//	int move[4], i = 0, sockfd = socket.getFileDescriptor(), newch = STDIN_FILENO;
//	int nfd = sockfd < STDIN_FILENO ? STDIN_FILENO+1 : sockfd+1;
//	fd_set read;
//	std::string effective_move;
//	board.ask_ipos();
//	while(game_ongoing){
//		FD_ZERO(&read);
//		FD_SET(sockfd, &read);
//		FD_SET(newch, &read);
//		if (select(nfd, &read, nullptr, nullptr, nullptr) == -1) throw std::runtime_error("Select failed");
//		if (FD_ISSET(sockfd, &read)){
//			std::string message = socket.receiveMessage();
//  			char header = message[0];
//  			(this->*(headerReceiveMap[header]))(message.erase(0,1));
//		}
//		if(FD_ISSET(newch, &read)){
//			move[i] = board.getchar();
//			if (i < 2) board.print_ipos(move[i], i);
//			else board.print_epos(move[i], i%2);
//			i++;
//			if (i == 2) board.ask_epos();
//			else if (i == 4){
//				board.clear_get_movement();
//				effective_move = moveToString(move);
//				sendMove(effective_move);
//				i=0;
//				board.ask_ipos();
//				if (effective_move == "/end"){
//      					game_ongoing = false;
//      					board.endgame("You gave up.");
//    				}
//			}
//		}
//	}
//}

void ClientGameControl::startParty() {
  game_ongoing = true;
  while(game_ongoing) {handleMessage();}
  emit finished();
}
