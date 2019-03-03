#ifndef __PLAYER__CPP__
#define __PLAYER__CPP__

#include <iostream>
#include "Player.hpp"
#include "../Communication/ServerMessageHandler.hpp"


Player& Player::operator= (Player&& original) {
		_sock = original._sock;
		_control = original._control;
		_pipe = original._pipe;
		original._pipe = nullptr;
		_name = original._name;
		_recvActive = original._recvActive;
		return *this;
	}


std::string Player::askMove(){
	_control->sendAskMove(getSocket());
	_recvActive = true;
	_control->handleMessage(getSocket());
	char res[5];
	read(_pipe[0], &res, sizeof(char)*4);
	res[4] = '\0';
	return std::string(res);
}

void Player::showBoard(std::string board){
	_control->sendBoard(getSocket(), board);
}

char Player::askPromotion(){
	_control->sendAskPromotion(getSocket());
	_recvActive = true;
	_control->handleMessage(getSocket());
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

int Player::getQueueNumber() const {
	return _queueNumber;
}

void Player::setName(std::string name){
	_name = name;
}

void Player::setControl(ServerGameControl* control){
	_control = control;
}

void Player::setSocket(Socket* socket){
	_sock = socket;
}

void Player::setQueueNumber(int queueNumber){
	_queueNumber = queueNumber;
}


void Player::transferStart() {
	_control->sendStart(getSocket());
}

void Player::transferUpdate(std::string& update) {
	_control->sendUpdate(getSocket(), update);
}

void Player::transferCheck() {
	_control->sendCheck(getSocket());
}

void Player::transferCheckmate(std::string& winner) {
	_control->sendCheckmate(getSocket(), winner);
}

void Player::transferStalemate() {
	_control->sendStalemate(getSocket());
}

void Player::transferGameMode(std::string& game) {
	_control->sendGameMode(getSocket(), game);
}

void Player::transferColour(std::string& colour) {
	_control->sendPlayerColour(getSocket(), colour);
}

void Player::transferTurn(unsigned turn) {
	_control->sendTurn(getSocket(), turn);
}

void Player::receiveMove(std::string& message){
	if (_recvActive){
		_recvActive = false;
		char str[4+1];				// 4 characters for a move, 1 for \0
		std::strcpy(str, message.c_str());
		write(_pipe[1], str, 4*sizeof(char));
	}
}

void Player::receivePromotion(std::string& message){
	if (_recvActive){
		_recvActive = false;
		char str[1+1];				// 1 character for promotion request, 1 for \0
		std::strcpy(str, message.c_str());
		write(_pipe[1], str, sizeof(char));
	}
}

#endif
