#ifndef __BOARD__CPP__
#define __BOARD__CPP__

#include"Board.hpp"


//constructor
Board::Board(unsigned column, unsigned row):
	_column(column),
	_row(row),
	_state(nullptr)
{
	_state = new Piece**[this->getColumn()];
	for (int i = 0; i < this->getColumn(); i++)
	{
		_state[i] = new Piece*[this->getRow()];
		for (int j = 0; j < this->getRow(); j++)
		{
			_state[i][j] = nullptr;
		}
	}
}


//copy
Board::Board(const Board& original):
	_column(original.getColumn()),
	_row(original.getRow()),
	_state(nullptr)
{
	this->_copyState(original);
}


//transfert
Board::Board(Board&& original):
	_column(original.getColumn()),
	_row(original.getRow()),
	_state(original._state)
{
	original._state = nullptr;
}


//destructor
Board::~Board()
{
	this->_delState();
}




//=copy
Board& Board::operator= (const Board& original)
{
	_column = original.getColumn();
	_row = original.getRow();
	this->_delState();
	this->_copyState(original);
	return *this;
}


//=transfert
Board& Board::operator= (Board&& original)
{
	_column = original.getColumn();
	_row = original.getRow();
	_state = original._state;
	original._state = nullptr;
	return *this;
}




void Board::_copyState(const Board& original)
/*
Copy the state from a Board to this one.
precondition: the original board have the same size than this one.
postcondition: this board have the same state than original.
*/
{
	_state = new Piece**[this->getColumn()];
	for (int i = 0; i < this->getColumn(); i++)
	{
		_state[i] = new Piece*[this->getRow()];
		for (int j = 0; j < this->getRow(); j++)
		{
			_state[i][j] = original._state[i][j];//getPiece? TODO
		}
	}
}


void Board::_delState()
/*
Free the place taken by _state and change it to nullptr
postcondition: _state == nullptr
*/
{
	for (int i; i < this->getColumn(); i++)
	{
		delete _state[i];
	}
	delete _state;
	_state = nullptr;
}




Piece* Board::getCase(Coordinate& place)
{
	return _state[place.getRealColumn()][place.getRealRow()];
}


Piece* Board::movePiece(Coordinate& start, Coordinate& end)
{
	Piece* eaten = this->getCase(end);
	this->setCase(end, this->getCase(start));
	return eaten;
}


void Board::setCase(Coordinate& place, Piece* piece)
{
	_state[place.getRealColumn()][place.getRealRow()] = piece;
}

#endif























































