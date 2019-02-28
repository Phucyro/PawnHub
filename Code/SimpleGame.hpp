#ifndef __SIMPLE__GAME__
#define __SIMPLE__GAME__

#include <string>
#include "Game.hpp"

class SimpleGame: public Game
{
	private:
	bool _testCheck;

	protected:
		void _initBoard() override{}
		void _nextTurn() override{}
		bool _isFinish() override{return true;}
		void _changePawn(Piece*, Piece*) override{}
		Player* _getCurrentPlayer() override{return nullptr;}
		void _boardState(std::string&) override {}

	public:
	SimpleGame() : Game(nullptr, 0, nullptr, nullptr, 0, 0), _testCheck(false){}
	bool changeTestCheck(){_testCheck = !_testCheck;}
	bool testCheck(const char color) override {return _testCheck;}
};

#endif
