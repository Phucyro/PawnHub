#ifndef __TURN__BASED__GAME__CPP__
#define __TURN__BASED__GAME__CPP__

#include "TurnBasedGame.hpp"

TurnBasedGame::TurnBasedGame(Piece** pieces, unsigned piecesAmount, Player* player1, Player* player2, unsigned lastStrongPiecesWhite, unsigned lastStrongPieceBlack):
	Game(pieces,piecesAmount, player1, player2, lastStrongPiecesWhite, lastStrongPieceBlack, nullptr)
{
	_board = new Board();
}



TurnBasedGame& TurnBasedGame::operator= (const TurnBasedGame& original){
	this->Game::operator= (original);
	return *this;
}


TurnBasedGame& TurnBasedGame::operator= (TurnBasedGame&& original){
	this->Game::operator= (original);
	return *this;
}



void TurnBasedGame::start()
{
	std::cout << "Starting Game" << std::endl;
	this->_initBoard();
	this->_sendGameMode();
	this->_sendPlayerColour();
	this->_sendStart();
	this->_sendBoard();
	do
	{
		++_turn;
		this->_sendTurn();
		this->_nextTurn();
		this->_sendBoard();
	}
	while(! this->_isFinish());
	std::cout << "Game finished" << std::endl;
}

#endif
