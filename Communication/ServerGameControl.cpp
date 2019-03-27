#include "ServerGameControl.hpp"

ServerGameControl::ServerGameControl(Player* _player1, Player* _player2, Game* _game, ExecInfoThread* infoThread): player1(_player1), player2(_player2), game(_game), info(infoThread) {
  startParty();
}

ServerGameControl::ServerGameControl(const ServerGameControl& _other): player1(_other.player1), player2(_other.player2), game(_other.game), info(_other.info) {
}

ServerGameControl& ServerGameControl::operator=(const ServerGameControl& _other) {
  player1 = _other.player1;
  player2 = _other.player2;
  game = _other.game;
  info = _other.info;
  return *this;
}

ServerGameControl::~ServerGameControl() {
  player1 = nullptr;
  player2 = nullptr;
  delete game;
  info->setFinished(true);
  info = nullptr;
}

void ServerGameControl::receiveMove(std::string message) {
  std::cout << "Received move " << message << std::endl;
  player1->receiveMove(message);
  player2->receiveMove(message);
}

void ServerGameControl::receivePromotion(std::string message) {
  player1->receivePromotion(message);
  player2->receivePromotion(message);
}

void ServerGameControl::sendBoard(Socket* socket, std::string board) {
  std::string header = headerSendMap["board"];
  try{
    socket->sendMessage(std::string("30~") + header + board);
    sendTurn(socket, game->getTurn());
  }
  catch(std::runtime_error e){
    std::cout<<"error in sendBoard: "<<e.what()<<std::endl;
    _playerDisconected(socket);
  }
}

void ServerGameControl::sendFirstMsg(Socket* socket) {
  std::string header = headerSendMap["firstmsg"];
  try{socket->sendMessage(std::string("30~") + header + "garbage");}
  catch(std::runtime_error e){
    std::cout<<"error in sendFirstMsg: "<<e.what()<<std::endl;
    _playerDisconected(socket);
  }
}

void ServerGameControl::sendFirstBoard(Socket* socket, std::string board) {
  sendBoard(socket, "1" + board);
}

void ServerGameControl::sendSecondBoard(Socket* socket, std::string board) {
  sendBoard(socket, "2" + board);
}

void ServerGameControl::sendUpdate(Socket* socket, std::string update) {
  std::string header = headerSendMap["update"];
  try{socket->sendMessage(std::string("30~") + header + update);}
  catch(std::runtime_error e){
  	std::cout<<"error in sendUpdate: "<<e.what()<<std::endl;
  	_playerDisconected(socket);
  }
}


void ServerGameControl::sendStart(Socket* socket) {
  sendUpdate(socket, "start");
}

void ServerGameControl::sendCheck(Socket* socket) {
  sendUpdate(socket, "check");
}

void ServerGameControl::sendCheckmate(Socket* socket, std::string winner) {
  sendUpdate(socket, winner);
}

void ServerGameControl::sendStalemate(Socket* socket) {
  sendUpdate(socket, "stalemate");
}

void ServerGameControl::sendSurrend(Socket* socket) {
  sendUpdate(socket, "surrend");
}

void ServerGameControl::sendTimeout(Socket* socket) {
  sendUpdate(socket, "timeout");
}

void ServerGameControl::sendGameMode(Socket* socket, std::string mode) {
  std::string header = headerSendMap["gamemode"];
  try{socket->sendMessage(std::string("30~") + header + mode);}
  catch(std::runtime_error e){
  	std::cout<<"error in sendGameMode: "<<e.what()<<std::endl;
  	_playerDisconected(socket);
  }
}

void ServerGameControl::sendPlayerColour(Socket* socket, std::string colour) {
  std::string header = headerSendMap["colour"];
  try{socket->sendMessage(std::string("30~") + header + colour);}
  catch(std::runtime_error e){
  	std::cout<<"error in sendPlayerColour: "<<e.what()<<std::endl;
  	_playerDisconected(socket);
  }
}

void ServerGameControl::sendTurn(Socket* socket, unsigned turn) {
  std::string header = headerSendMap["turn"];
  try{socket->sendMessage(std::string("30~") + header + std::to_string(turn));}
  catch(std::runtime_error e){
  	std::cout<<"error in sendTurn: "<<e.what()<<std::endl;
  	_playerDisconected(socket);
  }
}

void ServerGameControl::sendTime(Socket* socket, int time) {
  std::string header = headerSendMap["time"];
  try{socket->sendMessage(std::string("30~") + header + std::to_string(time));}
  catch(std::runtime_error e){
  	std::cout<<"error in sendTime: "<<e.what()<<std::endl;
  	_playerDisconected(socket);
  }
}

void ServerGameControl::sendGoodMove(Socket* socket) {
  std::string header = headerSendMap["goodmove"];
  try{socket->sendMessage(std::string("30~") + header + "waw");}
  catch(std::runtime_error e){
  	std::cout<<"error in sendGoodMove: "<<e.what()<<std::endl;
  	_playerDisconected(socket);
  }
}

void ServerGameControl::sendGoodPremove(Socket* socket) {
  std::string header = headerSendMap["goodpremove"];
  try{socket->sendMessage(std::string("30~") + header + "waw");}
  catch(std::runtime_error e){
  	std::cout<<"error in sendGoodPremove: "<<e.what()<<std::endl;
  	_playerDisconected(socket);
  }
}

void ServerGameControl::sendAskMove(Socket* socket) {
  std::string header = headerSendMap["askmove"];
  try{socket->sendMessage(std::string("30~") + header + "gimme");}
  catch(std::runtime_error e){
  	std::cout<<"error in sendAskMove: "<<e.what()<<std::endl;
  	_playerDisconected(socket);
  }
}

void ServerGameControl::sendAskPromotion(Socket* socket) {
  std::string header = headerSendMap["promote"];
  try{socket->sendMessage(std::string("30~") + header + "please");}
  catch(std::runtime_error e){
  	std::cout<<"error in sendAskPromotion: "<<e.what()<<std::endl;
  	_playerDisconected(socket);
  }
}

void ServerGameControl::handleMessage(Player* player) {
	std::string message;
	try{
		message = player->readControlPipe();
		char header = message[0];
  	std::cout << "HEADER : "<< header << " : " << message.substr(1) << '\n';
    std::cout << "Taille du message : " << message.size() << std::endl;
  	(this->*(headerReceiveMap[header]))(message.substr(1));
	}
	catch(std::runtime_error e){
		std::cout<<"error in handleMessageSocket: "<<e.what()<<std::endl;
		_playerDisconected(player->getSocket());
	}
}

void ServerGameControl::startParty() {
  player1->startGame();
  player2->startGame();
  player1->setControl(this);
  player2->setControl(this);
  game->start();
  player1->endGame();
  player2->endGame();
}
void ServerGameControl::_playerDisconected(Socket* socket){
	if(player1->getSocket() == socket) player1->surrend();
	else player2->surrend();
}
