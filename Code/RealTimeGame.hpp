#ifndef __REAL__TIME__GAME__HPP__
#define __REAL__TIME__GAME__HPP__

#include "Game.hpp"
#include "RealTimeBoard.hpp"
#include "ChainedMove.hpp"
#define UPDATE_RATE 10 //milliseconds
#define MOVE_TIME 1000u //milliseconds

class RealTimeGame: public Game{
	private:
	int _timeBeforeUpdate(){return int(_lastUpdate)+UPDATE_RATE - int(_turn);}	
	
	protected:
	Player* _currentPlayer;
	unsigned _lastUpdate;
	RealTimeBoard* _getBoard() const {return dynamic_cast<RealTimeBoard*>(_board);}
	
	RealTimeGame(Piece**, unsigned, Player*, Player*, unsigned lastStrongPiecesWhite, unsigned lastStrongPieceBlack);
	RealTimeGame(const RealTimeGame&) = delete;
	virtual void _mainLoop();
	void _sendBoard() override;
	void _executeMove(Piece*, Coordinate);
	bool _isMovePossible(Coordinate, Coordinate);
	
	public:
	virtual ~RealTimeGame() = default;
	
	RealTimeGame& operator= (const RealTimeGame&);
	RealTimeGame& operator= (RealTimeGame&&);
	
	void start() override;
	bool testCheck(char) override {return false;}
	void promote(Piece*) override;
};


#endif
