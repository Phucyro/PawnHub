#ifndef __PLAYER__CPP__
#define __PLAYER__CPP__

#include <iostream>
#include"Player.hpp"

void askMoveToClient(Socket*, Player* player){
	std::cout<<"Player "<<player<<" enter move"<<std::endl;
	std::string move;
	std::cin>>move;
	player->reciveMove(move);
}
void sendBoard(Socket*, std::string board){std::cout<<board<<std::endl;}
void askPromotionToClient(Socket*, Player* player){
	std::string message = std::string("q");
	player->recivePromotion(message);
}

Player& Player::operator= (Player&& original) {
		_sock = original._sock;
		_pipe = original._pipe;
		original._pipe = nullptr;
		_name = original._name;
		return *this;
	}


std::string Player::askMove(){
	askMoveToClient(_sock, this);
	char res[5];
	read(_pipe[0], &res, sizeof(char)*4);
	res[4] = '\0';
	return std::string(res);
}

void Player::showBoard(std::string board){
	sendBoard(_sock, board);
}

char Player::askPromotion(){
	askPromotionToClient(_sock, this);
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

void Player::reciveMove(std::string& message){
	char str[message.length()+1];
	std::strcpy(str, message.c_str());
	write(_pipe[1], str, 4*sizeof(char));
}

void Player::recivePromotion(std::string& message){
	char str[message.length()+1];
	std::strcpy(str, message.c_str());
	write(_pipe[1], str, sizeof(char));
}

#endif
