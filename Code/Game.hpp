#ifndef __GAME__HPP__
#define __GAME__HPP__

#include "Coordinate.hpp"

class Player;
class Piece;
class Board;

class Game
{
	protected:
	Player *_player1, *_player2, *_winner;
	unsigned _turn;
	Board *_board;
	Piece** _pieces;
	unsigned _piecesAmount;

	virtual void _initBoard() = 0;
	virtual void _nextTurn() = 0;
	virtual bool _isFinish() = 0;

	Game(Piece**, unsigned);
	Game(const Game&) = delete;
	Game(Game&&);

	public:
	virtual ~Game();

	Game& operator= (const Game&) = delete;
	Game& operator= (Game&&);

	Player* start(Player*, Player*);
	virtual bool testCheck(const char color) = 0;
	unsigned getTurn() const {return _turn;}
};
#include "Piece.hpp"
#include"Board.hpp"
#include "Player.hpp"
#endif
