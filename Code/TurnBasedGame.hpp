#ifndef __TURN__BASED__GAME__HPP__
#define __TURN__BASED__GAME__HPP__

#include "Game.hpp"

class TurnBasedGame: public Game{
	
	protected:
	virtual void _nextTurn() = 0;
	virtual Player* _getCurrentPlayer() const = 0;
	virtual Player* _getOtherPlayer() const = 0;
	
	TurnBasedGame(Piece**, unsigned, Player*, Player*, unsigned lastStrongPiecesWhite, unsigned lastStrongPieceBlack);
	TurnBasedGame(const TurnBasedGame&) = delete;
	
	public:
	virtual ~TurnBasedGame() = default;
	
	TurnBasedGame& operator= (const TurnBasedGame&);
	TurnBasedGame& operator= (TurnBasedGame&&);
	
	void start() override;
};

#endif
