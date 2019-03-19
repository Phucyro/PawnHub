#ifndef __GAME__HPP__
#define __GAME__HPP__

#include <string>
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
	unsigned _lastStrongPiecesWhite;
	unsigned _lastStrongPieceBlack;

	virtual void _sendStart();
	virtual void _sendPlayerColour();
	virtual void _sendTurn();
	virtual void _sendBoard();
	virtual void _sendCheck();
	virtual void _sendCheckmate();
	virtual void _sendStalemate();
	virtual void _sendSurrend();

	virtual void _initBoard() = 0;
	virtual void _sendGameMode() = 0;
	virtual bool _isFinish() = 0;
	virtual void _changePawn(Piece*, Piece*, Board*) = 0;
	virtual void _boardState(std::string&) = 0;

	Game(Piece**, unsigned, Player*, Player*, unsigned lastStrongPiecesWhite, unsigned lastStrongPieceBlack, Board*);
	Game(const Game&) = delete;
	Game(Game&&);

	public:
	virtual ~Game();

	Game& operator= (const Game&);
	Game& operator= (Game&&);

	virtual void start() = 0;
	virtual bool testCheck(const char color) = 0;
	unsigned getTurn() const {return _turn;}
	virtual void promote(Piece*);

	Player* getWinner(){return _winner;}
	Player* getPlayer1(){return _player1;}
	Player* getPlayer2(){return _player2;}
	unsigned getTurn(){return _turn;}
	//Board* getBoard(){return _board;}
};
#include "Player.hpp"
#include "Piece.hpp"
#include"Board.hpp"
#endif
