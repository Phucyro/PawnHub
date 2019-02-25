#ifndef __GAME__HPP__
#define __GAME__HPP__

#include"Player.hpp"
#include"Board.hpp"

class Game
{
	protected:
	Player *_player1, *_player2, *_winner;
	unsigned _turn;
	Board _board;
	Piece* _pieces;
	unsigned _piecesAmount;
	
	void _initBoard();
	void _nextTurn();
	bool _isFinish() const;
	
	Game(Piece*, unsigned);
	Game(const Game&) = delete;
	Game(Game&&);
	
	public:
	virtual ~Game();
	
	Game& operator= (const Game&) = delete;
	Game& operator= (Game&&);
	
	Player* start(Player*, Player*);
	virtual bool testCheck() = 0;
};

#endif
