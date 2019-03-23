#ifndef __TURN__BASED__GAME__HPP__
#define __TURN__BASED__GAME__HPP__

#include "Game.hpp"

class TurnBasedGame: public Game{
	
	protected:
	virtual void _nextTurn();
	virtual bool _executeMove(Coordinate, Coordinate, char) = 0;
	virtual Player* _getCurrentPlayer() const = 0;
	virtual Player* _getOtherPlayer() const = 0;
	virtual bool _fitInBoard(std::string playerMove) {return playerMove[0] >= 'A' && playerMove[0] <= 'H' && playerMove[1] >= '1' && playerMove[1] <= '8' && playerMove[2] >= 'A' && playerMove[2] <= 'H' && playerMove[3] >= '1' && playerMove[3] <= '8';}
	
	void _sendTime() override;
	
	TurnBasedGame(Piece**, unsigned, Player*, Player*, unsigned lastStrongPiecesWhite, unsigned lastStrongPieceBlack);
	TurnBasedGame(const TurnBasedGame&) = delete;
	
	public:
	virtual ~TurnBasedGame() = default;
	
	TurnBasedGame& operator= (const TurnBasedGame&);
	TurnBasedGame& operator= (TurnBasedGame&&);
	
	void start() override;
};

#endif
