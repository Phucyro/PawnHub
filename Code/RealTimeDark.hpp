#ifndef __REAL__TIME__DARK__HPP__
#define __REAL__TIME__DARK__HPP__

#define KING_INDEX 4

#include "RealTimeGame.hpp"
#include "includesPieceHPP.hpp"

class RealTimeDark: public RealTimeGame{
	private:
	void _Pieces();
	int _calculOffset(char playerColor){return playerColor == 'w' ? 0 : 16;}
	bool _isVisible(Piece*, char);
	
	protected:
	void _initBoard() override;
	void _sendGameMode() override;
	bool _isFinish() override;
	bool _isCheckmate(char);
	void _boardState(std::string&) override;
	void _changePawn(Piece*, Piece*, Board*) override;
	RealTimeDark(const RealTimeDark&) = delete;
	void _sendBoard() override;
	
	public:
	RealTimeDark(Player* player1, Player* player2) noexcept : RealTimeGame(nullptr, 32, player1, player2, 7, 22) {_Pieces();}
	~RealTimeDark();
	RealTimeDark& operator=(const RealTimeDark& original){
		this->RealTimeGame::operator=(original);
		return *this;
	}
	RealTimeDark& operator=(RealTimeDark&& original){
		this->RealTimeGame::operator=(original);
		return *this;
	}
};

#endif
