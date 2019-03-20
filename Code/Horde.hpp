#ifndef _HORDE_HPP_
#define _HORDE_HPP_

#define KING_INDEX 4

#include "includesPieceHPP.hpp"
#include "TurnBasedGame.hpp"

class Horde: public TurnBasedGame{
	private :
	void _Pieces();
	Player* _getCurrentPlayer() override {
		if(_turn%2) return _player1;
		else return _player2;
	}
	bool _fitInBoard(std::string playerMove){return playerMove[0] >= 'A' && playerMove[0] <= 'H' && playerMove[1] >= '1' && playerMove[1] <= '8' && playerMove[2] >= 'A' && playerMove[2] <= 'H' && playerMove[3] >= '1' && playerMove[3] <= '8';}

	int _calculOffset(char playerColor){return playerColor == 'w' ? 0 : 16;}

	bool _executeMove(Coordinate, Coordinate, char);
	bool _isCheckmate(char);
	bool _isStalemate(char);
	void _updateStat();

	protected :
	void _initBoard() override;
	void _sendGameMode() override;
	void _nextTurn() override;
	bool _isFinish() override;
	void _changePawn(Piece*, Piece*, Board*) override;
	void _boardState(std::string&) override;

	public :
	Horde(Player* player1, Player* player2) noexcept : TurnBasedGame(nullptr, 48, player1, player2, 7, 15) {_Pieces();}
	Horde(const Horde&) = delete;
	virtual ~Horde();
	Horde& operator=(const Horde& original){
		this->TurnBasedGame::operator=(original);
		return *this;
	}
	Horde& operator=(Horde&& original){
		this->TurnBasedGame::operator=(original);
		return *this;
	}
	bool testCheck(const char color) override;
};

#endif
