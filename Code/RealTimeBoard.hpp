#ifndef __REAL__TIME__BOARD__HPP__
#define __REAL__TIME__BOARD__HPP__

#include "Board.hpp"

class RealTimeBoard: public Board{
	protected:
	bool** _locks;
	void _copyState(const Board&) override;
	void _delState() override;
	
	public:
	RealTimeBoard(unsigned = 8, unsigned = 8);
	RealTimeBoard(const RealTimeBoard&);
	RealTimeBoard(RealTimeBoard&&);
	virtual ~RealTimeBoard() = default;

	RealTimeBoard& operator= (const RealTimeBoard&);
	RealTimeBoard& operator= (RealTimeBoard&&);
	
	bool isCaseEmpty(Coordinate place) const override {return this->Board::isCaseEmpty(place) && !isLock(place);}
	void lock(Coordinate place){_locks[place.getRealColumn()][place.getRealRow()] = true;}
	void unlock(Coordinate place){_locks[place.getRealColumn()][place.getRealRow()] = false;}
	bool isLock(Coordinate place) const {return _locks[place.getRealColumn()][place.getRealRow()];}
};

#endif
