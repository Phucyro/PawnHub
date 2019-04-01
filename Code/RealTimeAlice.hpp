#ifndef __REAL__TIME__ALICE__HPP__
#define __REAL__TIME__ALICE__HPP__

#define KING_INDEX 4

#include "RealTimeGame.hpp"
#include "includesAlicePieceHPP.hpp"

class RealTimeAlice: public RealTimeGame{
	private:
	void _Pieces();
	int _calculOffset(char playerColor){return playerColor == 'w' ? 0 : 16;}
	void _updateStat();
	
	protected:
	void _initBoard() override;
	void _sendGameMode() override;
	void _sendBoard() override;
	void _sendStart() override;
	bool _isFinish() override;
	bool _isCheckmate(char);
	void _boardState(std::string&) override;
	void _changePawn(Piece*, Piece*, Board*) override;
	bool _canFight(Piece*, Piece*, Coordinate) override;
	RealTimeAlice(const RealTimeAlice&) = delete;
	
	public:
	RealTimeAlice(Player* player1, Player* player2) noexcept : RealTimeGame(nullptr, 32, player1, player2, 7, 22) {_Pieces();}
	~RealTimeAlice();
	RealTimeAlice& operator=(const RealTimeAlice& original){
		this->RealTimeGame::operator=(original);
		return *this;
	}
	RealTimeAlice& operator=(RealTimeAlice&& original){
		this->RealTimeGame::operator=(original);
		return *this;
	}
	void promote(Piece*) override;
};

#endif
