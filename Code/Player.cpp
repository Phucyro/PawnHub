#ifndef __PLAYER__CPP__
#define __PLAYER__CPP__

#include <iostream>
#include "Player.hpp"
#include "../Communication/ServerMessageHandler.hpp"


Player& Player::operator= (Player&& original) {
		_sock = original._sock;
		_control = original._control;
		_pipe = original._pipe;
		_pipeControl = original._pipeControl;
		original._pipe = nullptr;
		_name = original._name;
		_recvActive = original._recvActive;
		_color = original._color;
		_premoves = original._premoves;
		return *this;
	}


std::string Player::askMove(){
	if (_premoves.empty()){
		_control->sendAskMove(getSocket());
		char res[5];
		read(_pipe[0], &res, sizeof(char)*4);
		res[4] = '\0';
		return std::string(res);
	}
	else {
		std::string res = _premoves.front().getPreMove();
		_premoves.pop();
		return res;
	} 
}

void Player::showBoard(std::string board){
	_control->sendBoard(getSocket(), board);
}

char Player::askPromotion(){
	_control->sendAskPromotion(getSocket());
	_recvActive = true;
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

void Player::setColor(char color){
	_color = color;
}


void Player::transferFirstMsg(){
	_control->sendFirstMsg(getSocket());
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

void Player::transferSurrend(){
	_control->sendSurrend(getSocket());
}

void Player::transferTimeout(){
	_control->sendTimeout(getSocket());
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

void Player::transferTime(int time) {
	_control->sendTime(getSocket(), time);
}

void Player::transferGoodMove() {
	_control->sendGoodMove(getSocket());
}

void Player::receiveMove(std::string& message){
	if (message[0] == _color){
		if (_recvActive){
			_recvActive = false;
			char str[5+1];				// 4 characters for a move, 1 for \0
			std::strcpy(str, message.c_str());
			write(_pipe[1], &(str[1]), 4*sizeof(char));
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

void Player::surrend(){
	char message[5]="/end";
	write(_pipe[1], message, 4*sizeof(char));
}


void Player::activateControlRecv(){
	if (_control) _control->handleMessage(this);
}

std::string Player::readControlPipe(){
	char buffer[MSG_LENGTH+1];

	read(_pipeControl[0], buffer, sizeof(buffer));
	std::string msg = buffer;
	return msg;
}

void Player::writeControlPipe(std::string msg){
	char buffer[MSG_LENGTH+1];

	std::strcpy(buffer, msg.c_str());
	write(_pipeControl[1], buffer, sizeof(buffer));
}

void Player::cleanPreMove() {
	while (!_premoves.empty()) _premoves.pop();
}

#endif
