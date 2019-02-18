#ifndef _CLASSIC_HPP_
#define _CLASSIC_HPP_

#include <string>
#include "includesPieceHPP.hpp"
#include "Game.hpp"

class Classic : public Game {

	private :

	void _Pieces();

	Player* _getCurrentPlayer(){
		if(_turn%2) return _player1;
		else return _player2;
	}
	bool _fitInBoard(char* playerMove){return playerMove[0] < 'A' && playerMove[0] > 'H' && playerMove[1] < '1' && playerMove[1] > '8' && playerMove[2] < 'A' && playerMove[2] > 'H' && playerMove[3] < '1' && playerMove[3] > '8';}

	bool _executeMove(Coordinate, Coordinate, char);
	bool _isCheckmate(char);
	bool _isStalemate(char);
	bool _notEnoughtPieces();
	void _boardState(std::string&);

	int _calculOffset(char playerColor){return playerColor == 'w' ? 0 : 16;}


	protected :

	void _initBoard() override;
	void _nextTurn() override;
	bool _isFinish() override;
	Classic(const Classic&) = delete;
	using Game::_pieces;

	void _changePawn(Piece*, Piece*) override;

	public :

	Classic() noexcept : Game(nullptr, 32) {_Pieces();}
	virtual ~Classic();
	Classic& operator=(const Classic&) = delete;
	bool testCheck(const char color) override;
};

void Classic::_Pieces() {

	_pieces[0] = new Rook('w', 'A', '1');		//0 -> 7 : pièces fortes blanches
	_pieces[1] = new Knight('w', 'B', '1');
	_pieces[2] = new Bishop('w', 'C', '1');
	_pieces[3] = new Queen('w', 'D', '1');
	_pieces[4] = new King('w', 'E', '1');
	_pieces[5] = new Bishop('w', 'F', '1');
	_pieces[6] = new Knight('w', 'G', '1');
	_pieces[7] = new Rook('w', 'H', '1');
	_pieces[8] = new Pawn('w', 'A', '2');		//8 -> 15 : pions blancs
	_pieces[9] = new Pawn('w', 'B', '2');
	_pieces[10] = new Pawn('w', 'C', '2');
	_pieces[11] = new Pawn('w', 'D', '2');
	_pieces[12] = new Pawn('w', 'E', '2');
	_pieces[13] = new Pawn('w', 'F', '2');
	_pieces[14] = new Pawn('w', 'G', '2');
	_pieces[15] = new Pawn('w', 'H', '2');

	_pieces[16] = new Rook('b', 'A', '8');		//16 -> 23 : pièces fortes noires
	_pieces[17] = new Knight('b', 'B', '8');
	_pieces[18] = new Bishop('b', 'C', '8');
	_pieces[19] = new Queen('b', 'D', '8');
	_pieces[20] = new King('b', 'E', '8');
	_pieces[21] = new Bishop('b', 'F', '8');
	_pieces[22] = new Knight('b', 'G', '8');
	_pieces[23] = new Rook('b', 'H', '8');
	_pieces[24] = new Pawn('b', 'A', '7');		//24 -> 31 : pions noirs
	_pieces[25] = new Pawn('b', 'B', '7');
	_pieces[26] = new Pawn('b', 'C', '7');
	_pieces[27] = new Pawn('b', 'D', '7');
	_pieces[28] = new Pawn('b', 'E', '7');
	_pieces[29] = new Pawn('b', 'F', '7');
	_pieces[30] = new Pawn('b', 'G', '7');
	_pieces[31] = new Pawn('b', 'H', '7');
}

#endif
