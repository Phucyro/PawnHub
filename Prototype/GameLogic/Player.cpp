#ifndef __PLAYER__CPP__
#define __PLAYER__CPP__

#include <iostream>
#include"Player.hpp"
#include "../Communication/ServerMessageHandler.hpp"

void askMoveToClient(Socket* socket){
	std::cout<<"askMove"<<std::endl;
	socket->sendMessage("Cnope");
}
void sendBoard(Socket* socket, std::string board){
	std::cout << "sending board:" << std::endl;
	std::cout << std::string("B") + board<<std::endl;
	socket->sendMessage(std::string("B") + board);
}

void askPromotionToClient(Socket* socket){
	socket->sendMessage("P");
}

Player& Player::operator= (Player&& original) {
	_sock = original._sock;
	_pipe = original._pipe;
	original._pipe = nullptr;
	_name = original._name;
	return *this;
}


std::string Player::askMove(){
	askMoveToClient(_sock);
	receiveMessageHandler(*_sock, *this, nullptr, nullptr, nullptr);
	std::cout<<"end receiveMessageHandler"<<std::endl;
	char res[5];
	read(_pipe[0], &res, sizeof(char)*4);
	res[4] = '\0';
	std::cout<<"end askMove"<<std::endl;
	return std::string(res);
}

void Player::showBoard(std::string board){
	sendBoard(_sock, board);
}

char Player::askPromotion(){
	askPromotionToClient(_sock);
	char res;
	read(_pipe[0], &res, sizeof(char));
	return res;
}

std::string Player::getName() const {
	return _name;
}

Socket* Player::getSocket() const {
	return _sock;
}

unsigned int Player::getQueueNumber() const {
	return _queueNumber;
}

void Player::setName(std::string name){
	_name = name;
}

void Player::setSocket(Socket* socket){
	_sock = socket;
}

void Player::setQueueNumber(int queueNumber){
	_queueNumber = queueNumber;
}

void Player::receiveMove(std::string& message) {
	char str[message.length()+1];
	std::strcpy(str, message.c_str());
	std::cout<<"reciveMove"<<std::endl;
	write(_pipe[1], str, 4*sizeof(char));
	std::cout<<"move written"<<std::endl;
}

void Player::receivePromotion(std::string& message) {
	char str[message.length()+1];
	std::strcpy(str, message.c_str());
	write(_pipe[1], str, sizeof(char));
}

#endif
