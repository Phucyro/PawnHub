#ifndef __COORDINATE__HPP__
#define __COORDINATE__HPP__

class Coordinate
{
	private:
	unsigned _column;
	unsigned _row;
	
	public:
	constexpr Coordinate(unsigned column, unsigned row) noexcept : _column(column), _row(row) {}
	constexpr Coordinate(int column, int row) noexcept : Coordinate(unsigned(column), unsigned(row)) {}
	constexpr Coordinate(char column, char row) noexcept : _column(column - 'A'), _row(row - '1') {}
	constexpr Coordinate(const Coordinate&) noexcept = default;
	~Coordinate() = default;
	
	Coordinate& operator= (const Coordinate&) = default;
	bool operator== (const Coordinate&) const;
	bool operator!= (const Coordinate&) const;
	
	unsigned getRealColumn() const {return _column;}
	unsigned getRealRow() const {return _row;}
	char getAbstractColumn() const;
	char getAbstractRow() const;
};

#endif
