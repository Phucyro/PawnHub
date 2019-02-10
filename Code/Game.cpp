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
	_turn(original._turn),
	_board(original._board),
	_pieces(original._pieces),
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
	_turn = original._turn;
	_board = original._board;
	_pieces = original._pieces;
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

bool Game::_isFinish() const {

	if (_winner != nullptr) return true;
	else return false;
}

void Game::_nextTurn() {

	++_turn;

	/* Déroulement d'un tour à mettre */
}

void _initBoard() {

	//White part

	_board.setCase(Coordinate('A', '1'), Rook('w', 'A', '1'));
	_board.setCase(Coordinate('B', '1'), Knight('w', 'B', '1'));
	_board.setCase(Coordinate('C', '1'), Bishop('w', 'C', '1'));
	_board.setCase(Coordinate('D', '1'), Queen('w', 'D', '1'));
	_board.setCase(Coordinate('E', '1'), King('w', 'E', '1'));
	_board.setCase(Coordinate('F', '1'), Bishop('w', 'F', '1'));
	_board.setCase(Coordinate('G', '1'), Knight('w', 'G', '1'));
	_board.setCase(Coordinate('H', '1'), Rook('w', 'H', '1'));
	_board.setCase(Coordinate('A', '2'), Pawn('w', 'A', '2'));
	_board.setCase(Coordinate('B', '2'), Pawn('w', 'B', '2'));
	_board.setCase(Coordinate('C', '2'), Pawn('w', 'C', '2'));
	_board.setCase(Coordinate('D', '2'), Pawn('w', 'D', '2'));
	_board.setCase(Coordinate('E', '2'), Pawn('w', 'E', '2'));
	_board.setCase(Coordinate('F', '2'), Pawn('w', 'F', '2'));
	_board.setCase(Coordinate('G', '2'), Pawn('w', 'G', '2'));
	_board.setCase(Coordinate('H', '2'), Pawn('w', 'H', '2'));

	//Black part

	_board.setCase(Coordinate('A', '8'), Rook('b', 'A', '8'));
	_board.setCase(Coordinate('B', '8'), Knight('b', 'B', '8'));
	_board.setCase(Coordinate('C', '8'), Bishop('b', 'C', '8'));
	_board.setCase(Coordinate('D', '8'), Queen('b', 'D', '8'));
	_board.setCase(Coordinate('E', '8'), King('b', 'E', '8'));
	_board.setCase(Coordinate('F', '8'), Bishop('b', 'F', '8'));
	_board.setCase(Coordinate('G', '8'), Knight('b', 'G', '8'));
	_board.setCase(Coordinate('H', '8'), Rook('b', 'H', '8'));
	_board.setCase(Coordinate('A', '7'), Pawn('b', 'A', '7'));
	_board.setCase(Coordinate('B', '7'), Pawn('b', 'B', '7'));
	_board.setCase(Coordinate('C', '7'), Pawn('b', 'C', '7'));
	_board.setCase(Coordinate('D', '7'), Pawn('b', 'D', '7'));
	_board.setCase(Coordinate('E', '7'), Pawn('b', 'E', '7'));
	_board.setCase(Coordinate('F', '7'), Pawn('b', 'F', '7'));
	_board.setCase(Coordinate('G', '7'), Pawn('b', 'G', '7'));
	_board.setCase(Coordinate('H', '7'), Pawn('b', 'H', '7'));
}

#endif

















































