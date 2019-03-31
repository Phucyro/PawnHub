#include "ClientGameControl.hpp"
#include "BoardParsing.hpp"

#include "../MainMenu/gameWithoutChat.h"
#include "../MainMenu/gameWithoutChatWithAlice.h"

#define TIMER_UPDATE_RATE 1000000 //microsecond
std::string moveToString(int*);

ClientGameControl::ClientGameControl(Client* _client, GameWithoutChat* _game): client(_client), game(_game), alice_game(nullptr), game_ongoing(true), is_alice(false), is_real_time(false), colour('\0') {
    connect(this, &ClientGameControl::updatePiece, game, &GameWithoutChat::set_piece);
    connect(this, &ClientGameControl::receiveUpdate, game, &GameWithoutChat::show_update);
    connect(this, &ClientGameControl::receiveGameMode, game, &GameWithoutChat::set_mode);
    connect(this, &ClientGameControl::setColour, game, &GameWithoutChat::set_colour);
    connect(this, &ClientGameControl::receiveTurn, game, &GameWithoutChat::set_turn);
    connect(this, &ClientGameControl::receiveTime, game, &GameWithoutChat::set_time);
    connect(this, &ClientGameControl::clearBoard, game, &GameWithoutChat::clear_board, Qt::DirectConnection);
    connect(this, &ClientGameControl::receiveAskMove, game, &GameWithoutChat::get_move);
    connect(this, &ClientGameControl::receiveAskPromotion, game, &GameWithoutChat::get_promotion);
    connect(this, &ClientGameControl::pauseTimer, game, &GameWithoutChat::pause_timer);
    connect(this, &ClientGameControl::reduceTimer, game, &GameWithoutChat::reduce_timer);

    connect(game, &GameWithoutChat::move_declared, this, &ClientGameControl::sendMove);
    connect(game, &GameWithoutChat::promotion_declared, this, &ClientGameControl::sendPromotion);
    connect(game, &GameWithoutChat::game_ongoing_changed, this, &ClientGameControl::setGameOngoing);
    connect(game, &GameWithoutChat::is_realtime, this, &ClientGameControl::setRealTime);
}

ClientGameControl::ClientGameControl(Client* _client, GameWithoutChatWithAlice* _game): client(_client), game(nullptr), alice_game(_game), game_ongoing(true), is_alice(true), is_real_time(false), colour('\0') {
    connect(this, &ClientGameControl::updatePiece, alice_game, &GameWithoutChatWithAlice::set_piece);
    connect(this, &ClientGameControl::receiveUpdate, alice_game, &GameWithoutChatWithAlice::show_update);
    connect(this, &ClientGameControl::receiveGameMode, alice_game, &GameWithoutChatWithAlice::set_mode);
    connect(this, &ClientGameControl::setColour, alice_game, &GameWithoutChatWithAlice::set_colour);
    connect(this, &ClientGameControl::receiveTurn, alice_game, &GameWithoutChatWithAlice::set_turn);
    connect(this, &ClientGameControl::receiveTime, alice_game, &GameWithoutChatWithAlice::set_time);
    connect(this, &ClientGameControl::clearBoard, alice_game, &GameWithoutChatWithAlice::clear_board, Qt::DirectConnection);
    connect(this, &ClientGameControl::receiveAskMove, alice_game, &GameWithoutChatWithAlice::get_move);
    connect(this, &ClientGameControl::receiveAskPromotion, alice_game, &GameWithoutChatWithAlice::get_promotion);
    connect(this, &ClientGameControl::pauseTimer, alice_game, &GameWithoutChatWithAlice::pause_timer);
    connect(this, &ClientGameControl::reduceTimer, alice_game, &GameWithoutChatWithAlice::reduce_timer);

    connect(alice_game, &GameWithoutChatWithAlice::move_declared, this, &ClientGameControl::sendMove);
    connect(alice_game, &GameWithoutChatWithAlice::promotion_declared, this, &ClientGameControl::sendPromotion);
    connect(alice_game, &GameWithoutChatWithAlice::game_ongoing_changed, this, &ClientGameControl::setGameOngoing);
    connect(alice_game, &GameWithoutChatWithAlice::is_realtime, this, &ClientGameControl::setRealTime);
}

ClientGameControl::~ClientGameControl()
{
    game = nullptr;
    client = nullptr;
}

void ClientGameControl::callPieceUpdate(QIcon pieceIcon, QString piecePosition, QString pieceName)
{
    emit updatePiece(pieceIcon, piecePosition, pieceName);
}

void ClientGameControl::receiveBoard(QString message) {
  emit clearBoard();

  bool is_second_board = false;
  if (is_alice) {
      if (message[0] == '2') {
        is_second_board = true;
      }
      message.remove(0,1);
  }
  stringToBoard(this, message.toStdString(), is_second_board);
}

void ClientGameControl::receivePlayerColour(QString message) {
  colour = message.toStdString()[0];
  emit setColour(message);
}

// void ClientGameControl::receiveAskMove(std::string message) {
// 	struct timeval updateRate;
// 	int move[4], i = 0, newch = STDIN_FILENO;
// 	fd_set read;
// 	std::string effective_move;
// 	int timeLeft = timer.get_remaining_time();
//
// 	board.print_your_turn();
// 	board.ask_ipos();
// 	timer.start();
// 	timer.unpause();
//
//   while (i < 4 && timeLeft){
//   	updateRate.tv_sec = int(TIMER_UPDATE_RATE / 1000000);
//   	updateRate.tv_usec = int(TIMER_UPDATE_RATE % 1000000);
//   	FD_ZERO(&read);
// 		FD_SET(newch, &read);
// 		if (select(newch+1, &read, nullptr, nullptr, &updateRate) == -1) throw std::runtime_error("Select failed");
// 		timeLeft = timer.get_remaining_time();
//
// 		if (FD_ISSET(newch, &read)){
// 			move[i] = board.getchar();
// 			if (i < 2) board.print_ipos(move[i], i);
// 			else board.print_epos(move[i], i%2);
// 			i++;
// 			if (i == 2) board.ask_epos();
// 			else if (i == 4){
// 				board.clear_premove();
// 				effective_move = moveToString(move);
// 			}
// 		}
// 		board.show_time_left(timer);
//   }
//   if (!timeLeft){
//   	sendMove("/tim");
//   	game_ongoing = false;
//   	board.clear_get_movement();
//   	board.endgame("Time out! You lost.");
//   }
//
//   if (game_ongoing){
//     sendMove(effective_move);
//     if (effective_move == "/end"){
//       game_ongoing = false;
//       board.clear_get_movement();
//       board.endgame("You gave up.");
//     }
//   }
// }

void ClientGameControl::receiveGoodMove(QString) {
	if (!is_real_time){
        emit pauseTimer();
    }
}

void ClientGameControl::receiveFirstMessage(QString) {
    //just here to be sure no one use the F as header.
    //can be used to do something just after the clean up.
}

void ClientGameControl::receiveGoodPremove(QString) {
    if (!is_real_time) {
        emit reduceTimer(100);
	}
}

void ClientGameControl::sendMove(QString move) {
  std::string header = headerSendMap["move"];
  std::cout << "Sending: " << move.toStdString() << std::endl;
  client->getSocket()->sendMessage("30~" + header + colour + move.toStdString());
}

void ClientGameControl::sendPromotion(QString promotion) {
  std::string header = headerSendMap["promote"];
  client->getSocket()->sendMessage("30~" + header + promotion.toStdString());
}

void ClientGameControl::setGameOngoing(bool value) {
    game_ongoing = value;
}

void ClientGameControl::setRealTime() {
    is_real_time = true;
}

void ClientGameControl::handleMessage() {
    std::string message = client->readGame();
    char header = message[0];
    (this->*(headerReceiveMap[header]))(QString::fromStdString(message.erase(0,1)));
}

void ClientGameControl::cleanOldMsg() {
	// to avoid message from previous game to break everything
	bool firstMsgRecv = false;
	std::string message;
    while (!firstMsgRecv) {
        message = client->readGame();
        if(message[0] == 'F') {
			firstMsgRecv = true;
			char header = message[0];
            (this->*(headerReceiveMap[header]))(QString::fromStdString(message.erase(0,1)));
        }
    }
}

void ClientGameControl::startParty() {
  game_ongoing = true;
  cleanOldMsg();
  while(game_ongoing) {handleMessage();}
  emit finished();
}
