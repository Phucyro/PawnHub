#include "ClientGameControl.hpp"
#include "BoardParsing.hpp"

#include "../MainMenu/gameWithoutChat.h"
#include "../MainMenu/gameWithoutChatWithAlice.h"

std::string moveToString(int*);

ClientGameControl::ClientGameControl(Client* _client, GameWithoutChat* _game): client(_client), game(_game), alice_game(nullptr), previous_board(), second_previous_board(), game_ongoing(true), is_alice(false), is_real_time(false), colour('\0') {
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
}

ClientGameControl::ClientGameControl(Client* _client, GameWithoutChatWithAlice* _game): client(_client), game(nullptr), alice_game(_game), previous_board(), second_previous_board(), game_ongoing(true), is_alice(true), is_real_time(false), colour('\0') {
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
}

ClientGameControl::~ClientGameControl()
{
    game = nullptr;
    alice_game = nullptr;
    client = nullptr;
}

void ClientGameControl::callPieceUpdate(QIcon pieceIcon, QString piecePosition, QString pieceName)
{
    emit updatePiece(pieceIcon, piecePosition, pieceName);
}

void ClientGameControl::receiveBoard(QString message) {
  bool is_second_board = false;
  if (is_alice) {
      if (message[0] == '2') {
        is_second_board = true;
      }
      message.remove(0,1);
  }
  if (!(previous_board == message) && !(second_previous_board == message))
  {
      if (is_second_board) second_previous_board = message;
      else previous_board = message;
      emit clearBoard(is_second_board);
      stringToBoard(this, message.toStdString(), is_second_board);
  }
}

void ClientGameControl::receivePlayerColour(QString message) {
  colour = message.toStdString()[0];
  emit setColour(message);
}

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
  client->getSocket()->sendMessage("30~" + header + colour + move.toStdString());
}

void ClientGameControl::sendPromotion(QString promotion) {
  std::string header = headerSendMap["promote"];
  client->getSocket()->sendMessage("30~" + header + promotion.toStdString());
}

void ClientGameControl::setGameOngoing(bool value) {
    game_ongoing = value;
}

bool ClientGameControl::isGameOngoing() {
    return game_ongoing;
}

void ClientGameControl::setRealTime() {
    is_real_time = true;
}

void ClientGameControl::handleMessage() {
    std::string message = client->readGame();
    char header = message[0];
    (this->*(headerReceiveMap[header]))(QString::fromStdString(message.erase(0,1)));
}

void ClientGameControl::startParty() {
  game_ongoing = true;
  while(game_ongoing) {handleMessage();}
  emit finished();
}
