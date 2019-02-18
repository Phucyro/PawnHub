#ifndef __GAME__CPP__
#define __GAME__CPP__

#include"Game.hpp"

//constructor
Game::Game(Piece** pieces, unsigned piecesAmount, Player* player1, Player* player2, unsigned lastStrongPiecesWhite, unsigned lastStrongPieceBlack):
	_player1(player1),
	_player2(player2),
	_winner(nullptr),
	_turn(0),
	_board(nullptr),
	_pieces(pieces),
	_piecesAmount(piecesAmount),
	_lastStrongPiecesWhite(lastStrongPiecesWhite),
	_lastStrongPieceBlack(lastStrongPieceBlack)
{
	_board = new Board();
}



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
	_lastStrongPieceBlack(original.__lastStrongPieceBlack)
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
	_lastStrongPieceBlack = original.__lastStrongPieceBlack;
	return *this;
}


void Game::start()
{
	this->_initBoard();
	do
	{
		this->_nextTurn();
	}
	while(! this->_isFinish());


}

void promote(Piece* pawn)
{
	char type = this->_getCurrentPlayer()->askPromotion();
	Piece* promotedPawn;
	switch (type) {
		case 'q': {
			promotedPawn = new Queen(*pawn);
			break;
		}

		case 'b':{
			promotedPawn = new Bishop(*pawn);
			break;
		}

		case 'h':
			promotedPawn = new Knight(*pawn);
			break;
		}

		case 'r':{
			promotedPawn = new Rook(*pawn);
			break;
		}

	}
	this->changePawn(pawn, promotedPawn)
	delete pawn;

}

#endif
