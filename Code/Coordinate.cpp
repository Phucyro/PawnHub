#ifndef __COORDINATE__CPP__
#define __COORDINATE__CPP__

#include"Coordinate.hpp"

//constructor with real coordinate
Coordinate::Coordinate(unsigned column, unsigned row):
	_column(column),
	_row(row){}

//constructor with real coordinate
Coordinate::Coordinate(int column, int row):
	Coordinate(unsigned(column), unsigned(row)){}

//constructor with abstract coordinate
Coordinate::Coordinate(char column, char row):
	_column(column - 'A'),
	_row(row - '1'){}





bool Coordinate::operator== (const Coordinate& other)
{
	return this->getRealColumn() == other.getRealColumn() && this->getRealRow() == other.getRealRow();
}

bool Coordinate::operator!= (const Coordinate& other)
{
	return !(*this == other);
}




char Coordinate::getAbstractColumn() const
{
	return char(this->getRealColumn()+'A');
}


char Coordinate::getAbstractRow() const
{
	return char(this->getRealRow()+'1');
}

#endif
