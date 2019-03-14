#ifndef __REAL__TIME__BOARD__CPP__
#define __REAL__TIME__BOARD__CPP__

#include <stdexcept>
#include "RealTimeBoard.hpp"

RealTimeBoard::RealTimeBoard(unsigned column, unsigned row): Board(column, row), _locks(nullptr){
	_locks = new bool*[_column];
	for (int i = 0; i < _column; i++) _locks[i] = new bool[_row];
}


RealTimeBoard::RealTimeBoard(const RealTimeBoard& original): Board(original), _locks(nullptr){}

RealTimeBoard::RealTimeBoard(RealTimeBoard&& original): Board(original), _locks(original._locks){
	original._locks = nullptr;
}



RealTimeBoard& RealTimeBoard::operator= (const RealTimeBoard& original){
	this->Board::operator= (original);
	return *this;
}


RealTimeBoard& RealTimeBoard::operator= (RealTimeBoard&& original){
	this->Board::operator= (original);
	_locks = original._locks;
	original._locks = nullptr;
	return *this;
}



void RealTimeBoard::_copyState(const Board& original){
	this->Board::_copyState(original);
	
	const Board* p = &original;
	const RealTimeBoard *rbOriginal = dynamic_cast<const RealTimeBoard*>(p);
	if (!rbOriginal) throw std::invalid_argument("RealTimeBoard::_copyState: Try to copy the state of a non-RealTime Board.");
	
	_locks = new bool*[rbOriginal->_column];
	for (int i = 0; i < rbOriginal->_column; i++){
		_locks[i] = new bool[rbOriginal->_row];
		for (int j = 0; j < rbOriginal->_row; j++){
			_locks[i][j] = rbOriginal->_locks[i][j];
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

#endif

















































