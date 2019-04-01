#ifndef __REAL__TIME__HORDE__HPP__
#define __REAL__TIME__HORDE__HPP__

#define KING_INDEX 4

#include "RealTimeGame.hpp"
#include "includesPieceHPP.hpp"

class RealTimeHorde: public RealTimeGame{
	private:
	void _Pieces();
	int _calculOffset(char playerColor){return playerColor == 'w' ? 0 : 16;}
	void _updateStat();
	
	protected:
	void _initBoard() override;
	void _sendGameMode() override;
	bool _isFinish() override;
	bool _isCheckmate(char);
	void _boardState(std::string&) override;
	void _changePawn(Piece*, Piece*, Board*) override;
	RealTimeHorde(const RealTimeHorde&) = delete;
	
	public:
	RealTimeHorde(Player* player1, Player* player2) noexcept : RealTimeGame(nullptr, 48, player1, player2, 7, 15) {_Pieces();}
	~RealTimeHorde();
	RealTimeHorde& operator=(const RealTimeHorde& original){
		this->RealTimeGame::operator=(original);
		return *this;
	}
	RealTimeHorde& operator=(RealTimeHorde&& original){
		this->RealTimeGame::operator=(original);
		return *this;
	}
};

#endif
