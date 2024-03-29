#ifndef _DARK_HPP_
#define _DARK_HPP_

#define KING_INDEX 4

#include <iostream>
#include <string>
#include "includesPieceHPP.hpp"
#include "TurnBasedGame.hpp"

class Dark: public TurnBasedGame{
	private :

	void _Pieces();

	Player* _getCurrentPlayer() const override {
		if(_turn%2) return _player1;
		else return _player2;
	}
	

	bool _isCheckmate(char);
	bool _isStalemate(char);
	bool _executeMove(Coordinate, Coordinate, char);

	int _calculOffset(char playerColor){return playerColor == 'w' ? 0 : 16;}
	bool _isVisible(Piece*, char);
	void _updateStat();

	protected :

	void _initBoard() override;
	void _sendGameMode() override;
	bool _isFinish() override;
	void _boardState(std::string&) override;
	void _sendBoard() override;

	void _changePawn(Piece*, Piece*, Board*) override;

	public :
	Dark(Player* player1, Player* player2) noexcept : TurnBasedGame(nullptr, 32, player1, player2, 7, 22) {_Pieces();}
	Dark(const Dark&) = delete;
	virtual ~Dark();

	Dark& operator=(const Dark& original){
		this->TurnBasedGame::operator=(original);
		return *this;
	}
	Dark& operator=(Dark&& original){
		this->TurnBasedGame::operator=(original);
		return *this;
	}

	bool testCheck(const char color) override {return false;}
};

#endif
