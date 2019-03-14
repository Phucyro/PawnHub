#ifndef __CHAINED__MOVE__CPP__
#define __CHAINED__MOVE__CPP__

#include "ChainedMove.hpp"

ChainedMove::ChainedMove(Piece* movingPiece, Coordinate end): _movingPiece(movingPiece), _moves(), _currentMove(), _moment(0u){
	Coordinate start = _movingPiece->getCoord();
	int rowMove = int(end.getRealRow()) - int(start.getRealRow());
	int rowDirection = rowMove == 0 ? 0 : rowMove/std::abs(rowMove);
	int columnMove = int(end.getRealColumn()) - int(start.getRealColumn());
	int columnDirection = columnMove == 0 ? 0 : columnMove/std::abs(columnMove);
	
	int i = 1;
	while (rowMove && columnMove){
		_moves.push(Coordinate(int(start.getRealColumn()) + i*columnDirection, int(start.getRealRow()) + i*rowDirection));
		i++;
		rowMove -= rowDirection;
		columnMove -= columnDirection;
	}
	int iStop = i; 
	while (rowMove){
		_moves.push(Coordinate(int(start.getRealColumn()) + iStop*columnDirection, int(start.getRealRow()) + i*rowDirection));
		i++;
		rowMove -= rowDirection;
	}
	
	while (columnMove){
		_moves.push(Coordinate(int(start.getRealColumn()) + i*columnDirection, int(start.getRealRow()) + iStop*rowDirection));
		i++;
		columnMove -= columnDirection;
	}
	if (!_moves.empty()) _currentMove = start;
}

Coordinate ChainedMove::nextMove(){
	_currentMove = _moves.front();
	_moves.pop();
	return _currentMove;
}

#endif
