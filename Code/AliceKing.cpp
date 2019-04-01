#ifndef __ALICE__KING__CPP__
#define __ALICE__KING__CPP__

#include <iostream>
#include "AliceKing.hpp"

Piece* AliceKing::_doMove(Coordinate end, Board* board, Game& game){
	_reverseEnable = true;
	Coordinate start = _coords;
	Piece* takenPiece = this->King::_doMove(end, board, game);
	this->_setCoordinate(end);
	std::cout<<"is in check: "<<game.testCheck(this->getColor())<<std::endl;
	if(game.testCheck(this->getColor())){
		std::cout<<"enter"<<std::endl;
		this->_setCoordinate(start);
		_reverseEnable = false;
		this->King::_reverseMove(end, board, game, takenPiece);
		return nullptr;
	}
	_swapDimension();
	return takenPiece;
}

void AliceKing::_reverseMove(Coordinate end, Board* board, Game& game, Piece* takenPiece){
	if (_reverseEnable){
		this->King::_reverseMove(end, board, game, takenPiece);
		_swapDimension();
	}
}

bool AliceKing::move(Coordinate end, Board* board, Game& game){
	bool moved = _moved;
	Coordinate start = _coords;
	bool res = this->Piece::move(end, board, game);
	std::cout<<"reverse is enable: "<<_reverseEnable<<std::endl;
	if (!_reverseEnable) {
		this->_setCoordinate(start);
		_moved = moved;
	}
	return res && _reverseEnable;
}

bool AliceKing::_isPlaceFree(Coordinate place ,Board* board, bool careOfMoving){
	return this->King::_isPlaceFree(place, board, careOfMoving) || this->AlicePiece::_isPlaceFree(place, board);
}

bool AliceKing::_checkMove(Coordinate end, Board* board, Game& game, bool careOfMoving){
	return this->AlicePiece::_checkMove(end, board, game) && this->King::_checkMove(end, board, game, careOfMoving);
}

bool AliceKing::_isMovePossible(Coordinate end, Board* board, Game& game){
	if (this->King::_isMovePossible(end, board, game)){
		_swapDimension();
		return true;
	}
	return false;
}

void AliceKing::stopMoving(Game& game, Board* board){
	this->Piece::stopMoving(game, board);
	this->AlicePiece::stopMoving(game);
}

#endif
