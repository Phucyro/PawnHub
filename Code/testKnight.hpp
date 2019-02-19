#ifndef __TEST__KNIGHT__HPP__
#define __TEST__KNIGHT__HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Knight.hpp"
#include "Coordinate.hpp"
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

	public:
	SimpleGame() : Game(nullptr, 0, nullptr, nullptr, 0, 0), _testCheck(false){}
	bool changeTestCheck(){_testCheck = !_testCheck;}
	bool testCheck(const char& color, const unsigned& promote) override {return _testCheck;}

};

class TestKnight: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE (TestKnight);
	CPPUNIT_TEST (testMove);
	CPPUNIT_TEST (testCheckMove);
	CPPUNIT_TEST_SUITE_END ();

	private:
	Knight *knightA;
	Knight *knightB;
	Knight *knightC;
	Knight *knightD;
	Knight *knightE;
	Knight *knightF;
	Knight *knightG;
	Knight *knightH;
	Knight *knightI;
	Knight *knightJ;
	Knight *knightK;
	Knight *knightL;
	Knight *knightM;
	Knight *knightN;
	Knight *knightO;
	Knight *knightP;


	SimpleGame *game;
	Board *board;

	protected:
	void testMove();
	void testCheckMove();

	public:
	void setUp();
	void tearDown();
};



#endif
