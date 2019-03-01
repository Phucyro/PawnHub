#ifndef _ALICE_HPP_
#define _ALICE_HPP_

#define KING_INDEX 4

#include <iostream>
#include <string>
#include "includesAlicePieceHPP.hpp"
#include "AlicePiece.hpp"
#include "Game.hpp"


class Alice : public Game {

	private :

	void _Pieces();

	Player* _getCurrentPlayer() override {
		if(_turn%2) return _player1;
		else return _player2;
	}
	bool _fitInBoard(std::string playerMove){return playerMove[0] >= 'A' && playerMove[0] <= 'H' && playerMove[1] >= '1' && playerMove[1] <= '8' && playerMove[2] >= 'A' && playerMove[2] <= 'H' && playerMove[3] >= '1' && playerMove[3] <= '8';}

	bool _executeMove(Coordinate, Coordinate, char);
	bool _isCheckmate(char);
	bool _isStalemate(char);
	bool _notEnoughtPieces();

	int _calculOffset(char playerColor){return playerColor == 'w' ? 0 : 16;}


	protected :

	void _initBoard() override;
	void _nextTurn() override;
	bool _isFinish() override;
	void _boardState(std::string&) override;
	Alice(const Alice&) = delete;
	using Game::_pieces;

	void _changePawn(Piece*, Piece*, Board*) override;

	public :

	Alice(Player* player1, Player* player2) noexcept : Game(nullptr, 32, player1, player2, 7, 22) {_Pieces();}
	virtual ~Alice();
	Alice& operator=(const Alice& original){
		this->Game::operator=(original);
		return *this;
	}
	Alice& operator=(Alice&& original){
		this->Game::operator=(original);
		return *this;
	}


	bool testCheck(const char color) override {
		Coordinate leftMaybePawn, rightMaybePawn;
		if (color == 'w' || color == 'a'){	//White		//a = all

		//Pawn
		AlicePiece* aliceKing = dynamic_cast<AlicePiece*>(_pieces[KING_INDEX]);
		leftMaybePawn = Coordinate(_pieces[KING_INDEX]->getCoord().getRealColumn()+1, _pieces[KING_INDEX]->getCoord().getRealRow()+1);
		Piece* MaybePawn = nullptr;
		AlicePiece* aliceMaybePawn;
		if (_board->isInBoard(leftMaybePawn)){
			MaybePawn = Game::_board->getCase(leftMaybePawn);
			aliceMaybePawn = dynamic_cast<AlicePiece*>(MaybePawn);
		}
		if (MaybePawn && MaybePawn->getColor() == 'b' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k') && aliceMaybePawn->getDimension() == aliceKing->getDimension()) return true;

		rightMaybePawn = Coordinate(_pieces[KING_INDEX]->getCoord().getRealColumn()-1, _pieces[KING_INDEX]->getCoord().getRealRow()+1);
		MaybePawn = nullptr;
		if (_board->isInBoard(rightMaybePawn)){
			MaybePawn = Game::_board->getCase(rightMaybePawn);
			aliceMaybePawn = dynamic_cast<AlicePiece*>(MaybePawn);
		}
		if (MaybePawn && MaybePawn->getColor() == 'b' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k') && aliceMaybePawn->getDimension() == aliceKing->getDimension()) return true;

		//strong pieces
		for (unsigned i = 16; i <= _lastStrongPieceBlack; ++i){
			if (!_pieces[i]->isTaken())
				if (_pieces[i]->_checkMove(_pieces[KING_INDEX]->getCoord(), Game::_board, *this)) return true;
		}
	}

		if (color == 'b' || color == 'a'){	//Black		//a = all

			//Pawn
			AlicePiece* aliceKing = dynamic_cast<AlicePiece*>(_pieces[KING_INDEX+16]);
			leftMaybePawn = Coordinate(_pieces[16+KING_INDEX]->getCoord().getRealColumn()-1, _pieces[16+KING_INDEX]->getCoord().getRealRow()-1);
			Piece* MaybePawn = nullptr;
			AlicePiece* aliceMaybePawn;
			if (_board->isInBoard(leftMaybePawn)){
				MaybePawn = Game::_board->getCase(leftMaybePawn);
				aliceMaybePawn = dynamic_cast<AlicePiece*>(MaybePawn);
			}
			if (MaybePawn && MaybePawn->getColor() == 'w' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k') && aliceMaybePawn->getDimension() == aliceKing->getDimension()) return true;

			rightMaybePawn = Coordinate(_pieces[16+KING_INDEX]->getCoord().getRealColumn()+1, _pieces[16+KING_INDEX]->getCoord().getRealRow()-1);
			MaybePawn = nullptr;
			if (_board->isInBoard(rightMaybePawn)){
				MaybePawn = Game::_board->getCase(rightMaybePawn);
				aliceMaybePawn = dynamic_cast<AlicePiece*>(MaybePawn);
			}
			if (MaybePawn && MaybePawn->getColor() == 'w' && (MaybePawn->getType() == 'p' || MaybePawn->getType() == 'b' || MaybePawn->getType() == 'q' || MaybePawn->getType() == 'k') && aliceMaybePawn->getDimension() == aliceKing->getDimension()) return true;

			//strong pieces
			for (unsigned i = 0; i <= _lastStrongPiecesWhite; ++i){
				if (!_pieces[i]->isTaken())
					if (_pieces[i]->_checkMove(_pieces[KING_INDEX+16]->getCoord(), Game::_board, *this)) return true;
			}
		}
		return false;
	}
};

#endif
