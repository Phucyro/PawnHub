#ifndef __GAME__CPP__
#define __GAME__CPP__

#include"Game.hpp"

//constructor
Game::Game(Piece* pieces, unsigned piecesAmount):
	_player1(nullptr),
	_player2(nullptr),
	_winner(nullptr),
	_turn(0),
	_board(Board()),
	_pieces(pieces),
	_piecesAmount(piecesAmount){}
	
	

//transfert
Game::Game(Game&& original):
	_player1(original._player1),
	_player2(original._player2),
	_winner(original._winner),
	original._player1 = nullptr;
	original._player2 = nullptr;
	original._winner = nullptr;
	_turn(original._turn),
	_board(original._board),
	_pieces(original._pieces),
	original._pieces = nullptr;
	_piecesAmount(original._piecesAmount){}



//destructor
Game::~Game()
{
	_player1 = nullptr;
	_player2 = nullptr;
	_winner = nullptr;
	_pieces = nullptr;
}




//=transfert
Game& Game::operator= (Game&& original)
{
	_player1 = original._player1;
	_player2 = original._player2;
	_winner = original._winner;
	original._player1 = nullptr;
	original._player2 = nullptr;
	original._winner = nullptr;
	_turn = original._turn;
	_board = original._board;
	_pieces = original._pieces;
	original._pieces = nullptr;
	_piecesAmount = original._piecesAmount;
	return *this;
}




Player* Game::start(Player* player1, Player* player2)
{
	_player1 = player1;
	_player2 = player2;
	this->_initBoard();
	do
	{
		this->_nextTurn();
	}
	while(! this->_isFinish());
	
	return _winner;
}

#endif

















































