#ifndef __REAL__TIME__BOARD__CPP__
#define __REAL__TIME__BOARD__CPP__

#include <stdexcept>
#include "RealTimeBoard.hpp"

RealTimeBoard::RealTimeBoard(unsigned column, unsigned row): Board(column, row), _locks(nullptr), _movingPieces(nullptr){
	_locks = new bool*[_column];
	for (int i = 0; i < _column; i++) _locks[i] = new bool[_row];
	_movingPieces = new std::list<Piece*>*[_column];
	for (int i = 0; i < _column; i++) _movingPieces[i] = new std::list<Piece*>[_row];
}


RealTimeBoard::RealTimeBoard(const RealTimeBoard& original): Board(original), _locks(nullptr){}

RealTimeBoard::RealTimeBoard(RealTimeBoard&& original): Board(original), _locks(original._locks), _movingPieces(original._movingPieces){
	original._locks = nullptr;
	original._movingPieces = nullptr;
}



RealTimeBoard& RealTimeBoard::operator= (const RealTimeBoard& original){
	this->Board::operator= (original);
	return *this;
}


RealTimeBoard& RealTimeBoard::operator= (RealTimeBoard&& original){
	this->Board::operator= (original);
	_locks = original._locks;
	original._locks = nullptr;
	_movingPieces = original._movingPieces;
	original._movingPieces = nullptr;
	return *this;
}



void RealTimeBoard::_copyState(const Board& original){
	this->Board::_copyState(original);
	
	const Board* p = &original;
	const RealTimeBoard *rbOriginal = dynamic_cast<const RealTimeBoard*>(p);
	if (!rbOriginal) throw std::invalid_argument("Try to copy the state of a non-RealTime Board.");
	
	_locks = new bool*[rbOriginal->_column];
	for (int i = 0; i < rbOriginal->_column; i++){
		_locks[i] = new bool[rbOriginal->_row];
		for (int j = 0; j < rbOriginal->_row; j++){
			_locks[i][j] = rbOriginal->_locks[i][j];
		}
	}
	_movingPieces = new std::list<Piece*>*[rbOriginal->_column];
	for (int i = 0; i < rbOriginal->_column; i++){
		_movingPieces[i] = new std::list<Piece*>[rbOriginal->_row];
		for (int j = 0; j < rbOriginal->_row; j++){
			_movingPieces[i][j] = rbOriginal->_movingPieces[i][j];
		}
	}
}

void RealTimeBoard::_delState(){
	this->Board::_delState();
	for (int i = 0; i < _column; i++){
		delete[] _locks[i];
	}
	delete[] _locks;
	_locks = nullptr;
}

Piece* RealTimeBoard::getCase(Coordinate place) const{
	 Piece* piece = Board::getCase(place);
	 if (piece) return piece;
	 else  return getMovingPiecesAt(place).empty() ? nullptr : getMovingPiecesAt(place).front();
}

void RealTimeBoard::remove(Piece* piece){
	Coordinate place = piece->getCoord();
	if (Board::getCase(place)) setCase(place, nullptr);
	else getMovingPiecesAt(place).remove(piece);
}

void RealTimeBoard::moveTo(Coordinate place, Piece* piece){
	getMovingPiecesAt(piece->getCoord()).remove(piece);
	getMovingPiecesAt(place).push_back(piece);
}

void RealTimeBoard::stopMoving(Piece* piece){
	getMovingPiecesAt(piece->getCoord()).remove(piece);
	setCase(piece->getCoord(), piece);
}

void RealTimeBoard::startMoving(Piece* piece){
	setCase(piece->getCoord(), nullptr);
	getMovingPiecesAt(piece->getCoord()).push_back(piece);
}

#endif

















































