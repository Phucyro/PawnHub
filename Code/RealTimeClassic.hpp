#ifndef __REAL__TIME__CLASSIC__HPP__
#define __REAL__TIME__CLASSIC__HPP__

#define KING_INDEX 4

#include "RealTimeGame.hpp"
#include "includesPieceHPP.hpp"

class RealTimeClassic: public RealTimeGame{
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
	RealTimeClassic(const RealTimeClassic&) = delete;
	
	public:
	RealTimeClassic(Player* player1, Player* player2) noexcept : RealTimeGame(nullptr, 32, player1, player2, 7, 22) {_Pieces();}
	~RealTimeClassic();
	RealTimeClassic& operator=(const RealTimeClassic& original){
		this->RealTimeGame::operator=(original);
		return *this;
	}
	RealTimeClassic& operator=(RealTimeClassic&& original){
		this->RealTimeGame::operator=(original);
		return *this;
	}
};

#endif
