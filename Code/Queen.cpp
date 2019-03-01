#ifndef __QUEEN__CPP__
#define __QUEEN__CPP__

#include <cmath>
#include "Queen.hpp"

Queen& Queen::operator= (const Queen& original){
	this->Piece::operator= (original);
	return *this;
}

bool Queen::_checkMoveRook(Coordinate end, Board* board, Game& game){
  	int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
  	int rowDirection = rowMove == 0 ? 0 : rowMove/std::abs(rowMove);
  	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());
  	int columnDirection = columnMove == 0 ? 0 : columnMove/std::abs(columnMove);

  	if (rowMove){
  		if (columnMove) return false;

  		// check if there is no piece in the way
  		for (int i = int(_coords.getRealRow()) + rowDirection; i != end.getRealRow(); i += rowDirection){
  			if (!_isPlaceFree(Coordinate(end.getRealColumn(), unsigned(i)), board)) return false;
  		}
  	}
  	else if(columnMove){
  		// check if there is no piece in the way
  		for (int i = int(_coords.getRealColumn()) + columnDirection; i != end.getRealColumn(); i += columnDirection){
  			if (!_isPlaceFree(Coordinate(unsigned(i), end.getRealRow()), board)) return false;
  		}
  	}
  	else return false;
  	if ((!_isPlaceFree(end, board)) && board->getCase(end)->getColor() == this->getColor()) return false;
  	return true;
  }


bool Queen::_checkMoveBishop(Coordinate end, Board* board, Game& game){
	int rowMove = int(end.getRealRow()) - int(_coords.getRealRow());
	int rowDirection = rowMove == 0 ? 0 : rowMove/std::abs(rowMove);
	int columnMove = int(end.getRealColumn()) - int(_coords.getRealColumn());
	int columnDirection = columnMove == 0 ? 0 : columnMove/std::abs(columnMove);

	if (end == _coords) return false;
	if (std::abs(rowMove) != std::abs(columnMove)) return false; //test if the move normal for a Queen

	//test if there is no piece in the way
	int row = _coords.getRealRow(), column = _coords.getRealColumn();
	row += rowDirection;
	column += columnDirection;
	while(row != end.getRealRow()){
		if (!_isPlaceFree(Coordinate(column, row), board)) return false;
		row += rowDirection;
		column += columnDirection;
	}

	if ((!_isPlaceFree(end, board)) && board->getCase(end)->getColor() == this->getColor()) return false;
	return true;
}

bool Queen::_checkMove(Coordinate end, Board* board, Game& game){
  if (_checkMoveRook(end,board,game) || _checkMoveBishop(end,board,game)){
    return true;
  }else{
    return false;
  }
}

bool Queen::canMove(Board* board, Game& game){
	if (this->_isMovePossible(1, 1, board, game)) return true;
	if (this->_isMovePossible(0, 1, board, game)) return true;
	if (this->_isMovePossible(-1, 1, board, game)) return true;
	if (this->_isMovePossible(1, 0, board, game)) return true;
	if (this->_isMovePossible(-1, 0, board, game)) return true;
	if (this->_isMovePossible(1, -1, board, game)) return true;
	if (this->_isMovePossible(0, -1, board, game)) return true;
	if (this->_isMovePossible(-1, -1, board, game)) return true;
	return false;
}

#endif
