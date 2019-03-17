#ifndef __GAME__CPP__
#define __GAME__CPP__

#include <iostream>
#include"Game.hpp"
#include "includesPieceHPP.hpp"

//constructor
Game::Game(Piece** pieces, unsigned piecesAmount, Player* player1, Player* player2, unsigned lastStrongPiecesWhite, unsigned lastStrongPieceBlack, Board* board):
	_player1(player1),
	_player2(player2),
	_winner(nullptr),
	_turn(0),
	_board(board),
	_pieces(pieces),
	_piecesAmount(piecesAmount),
	_lastStrongPiecesWhite(lastStrongPiecesWhite),
	_lastStrongPieceBlack(lastStrongPieceBlack)
{}



//transfert
Game::Game(Game&& original):
	_player1(original._player1),
	_player2(original._player2),
	_winner(original._winner),
	_turn(original._turn),
	_board(original._board),
	_pieces(original._pieces),
	_piecesAmount(original._piecesAmount),
	_lastStrongPiecesWhite(original._lastStrongPiecesWhite),
	_lastStrongPieceBlack(original._lastStrongPieceBlack)
{
	original._board = nullptr;
}



//destructor
Game::~Game()
{
	_player1 = nullptr;
	_player2 = nullptr;
	_winner = nullptr;
	_pieces = nullptr;
	delete _board;
}


//=copy
Game& Game::operator= (const Game& original)
{
	_player1 = original._player1;
	_player2 = original._player2;
	_winner = original._winner;
	_turn = original._turn;
	_board = original._board;
	_pieces = original._pieces;
	_piecesAmount = original._piecesAmount;
	_lastStrongPiecesWhite = original._lastStrongPiecesWhite;
	_lastStrongPieceBlack = original._lastStrongPieceBlack;
	std::cout<<"end of game copy"<<std::endl;
	return *this;
}

//=transfert
Game& Game::operator= (Game&& original)
{
	_player1 = original._player1;
	_player2 = original._player2;
	_winner = original._winner;
	_turn = original._turn;
	_board = original._board;
	original._board = nullptr;
	_pieces = original._pieces;
	_piecesAmount = original._piecesAmount;
	_lastStrongPiecesWhite = original._lastStrongPiecesWhite;
	_lastStrongPieceBlack = original._lastStrongPieceBlack;
	std::cout<<"end of game transfert"<<std::endl;
	return *this;
}

void Game::_sendStart(){
	_player1->transferStart();
	_player2->transferStart();
}

void Game::_sendPlayerColour(){
	std::string colour = "white";
	_player1->transferColour(colour);
	colour = "black";
	_player2->transferColour(colour);
}

void Game::_sendTurn(){
	_player1->transferTurn(getTurn());
	_player2->transferTurn(getTurn());
}

void Game::_sendBoard(){
	if (!_winner){
		std::string state;
		this->_boardState(state);
		_player1->showBoard(state);
		_player2->showBoard(state);
	}
}


void Game::_sendCheck() {
	_player1->transferCheck();
	_player2->transferCheck();
}

void Game::_sendCheckmate() {
	std::string winner;
	if (_winner == _player1) winner = "white";
	else winner = "black";
	_player1->transferCheckmate(winner);
	_player2->transferCheckmate(winner);
}

void Game::_sendStalemate() {
	_player1->transferStalemate();
	_player2->transferStalemate();
}

void Game::_sendSurrend(){
	_winner->transferSurrend();
}

void Game::promote(Piece* piece)
{	
	this->_sendBoard();
	Player *currentPlayer = piece->getColor() == 'w' ? _player1 : _player2;
	char type = currentPlayer->askPromotion();
	if (type == '/'){
		if (currentPlayer == _player1) _winner = _player2;
		else _winner = _player1;
	}
	Pawn *pawn = dynamic_cast<Pawn*>(piece);
	if (!pawn) throw std::string("the piece to promote is not a pawn");
	Piece* promotedPawn;
	switch (type) {
		case 'q':
			promotedPawn = new Queen(*pawn);
			break;


		case 'b':
			promotedPawn = new Bishop(*pawn);
			break;


		case 'h':
			promotedPawn = new Knight(*pawn);
			break;


		case 'r':
			promotedPawn = new Rook(*pawn);
			break;


	}
	this->_changePawn(pawn, promotedPawn, _board);
}

#endif
