#ifndef __COORDINATE__HPP__
#define __COORDINATE__HPP__

class Coordinate
{
	private:
	unsigned _column;
	unsigned _row;
	
	public:
	Coordinate(unsigned, unsigned);
	Coordinate(int, int);
	Coordinate(char, char);
	Coordinate(const Coordinate&) = default;
	~Coordinate() = default;
	
	Coordinate& operator= (const Coordinate&) = default;
	bool operator== (const Coordinate&);
	bool operator!= (const Coordinate&);
	
	unsigned getRealColumn() const {return _column;}
	unsigned getRealRow() const {return _row;}
	char getAbstractColumn() const;
	char getAbstractRow() const;
};

#endif
