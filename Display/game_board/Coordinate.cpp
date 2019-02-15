#ifndef __COORDINATE__CPP__
#define __COORDINATE__CPP__

#include"Coordinate.hpp"


bool Coordinate::operator== (const Coordinate& other) const
{
	return _column == other._column && _row == other._row;
}

bool Coordinate::operator!= (const Coordinate& other) const
{
	return !(*this == other);
}




char Coordinate::getAbstractColumn() const
{
	return char(_column+'A');
}


char Coordinate::getAbstractRow() const
{
	return char(_row+'1');
}

#endif
