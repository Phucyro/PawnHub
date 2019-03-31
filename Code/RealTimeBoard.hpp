#ifndef __REAL__TIME__BOARD__HPP__
#define __REAL__TIME__BOARD__HPP__

#include <list>
#include "Board.hpp"

class RealTimeBoard: public Board{
	protected:
	bool** _locks;
	std::list<Piece*>** _movingPieces;
	void _copyState(const Board&) override;
	void _delState() override;
	
	public:
	RealTimeBoard(unsigned = 8, unsigned = 8);
	RealTimeBoard(const RealTimeBoard&);
	RealTimeBoard(RealTimeBoard&&);
	virtual ~RealTimeBoard() = default;

	RealTimeBoard& operator= (const RealTimeBoard&);
	RealTimeBoard& operator= (RealTimeBoard&&);
	
	Piece* getCase(Coordinate) const override;
	bool isCaseEmpty(Coordinate place) const override {return this->Board::isCaseEmpty(place) && !isLock(place) && _movingPieces[place.getRealColumn()][place.getRealRow()].empty();}
	void lock(Coordinate place){_locks[place.getRealColumn()][place.getRealRow()] = true;}
	void unlock(Coordinate place){_locks[place.getRealColumn()][place.getRealRow()] = false;}
	bool isLock(Coordinate place) const {return _locks[place.getRealColumn()][place.getRealRow()];}
	std::list<Piece*>& getMovingPiecesAt(Coordinate place) const {return _movingPieces[place.getRealColumn()][place.getRealRow()];}
	void addTo(Coordinate place, Piece* piece) {getMovingPiecesAt(place).push_back(piece);}
	void remove(Piece*);
	void moveTo(Coordinate, Piece*);
	void stopMoving(Piece*);
	void startMoving(Piece*);
	
};

#endif
