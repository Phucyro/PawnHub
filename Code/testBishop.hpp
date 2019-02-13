#ifndef __TEST__BISHOP__HPP__
#define __TEST__BISHOP__HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Bishop.hpp"
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

	public:
	SimpleGame() : Game(nullptr, 0), _testCheck(false){}
	bool changeTestCheck(){_testCheck = !_testCheck;}
	bool testCheck(const char& color) const override {return _testCheck;}

};

class TestBishop: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE (TestBishop);
	CPPUNIT_TEST (testMove);
	CPPUNIT_TEST (testCheckMove);
	CPPUNIT_TEST_SUITE_END ();

	private:
	Bishop *bishopA;
  Bishop *bishopB;
	Bishop *bishopC;
	Bishop *bishopD;
	Bishop *bishopE;
	Bishop *bishopF;
	Bishop *bishopG;
	Bishop *bishopH;
	Bishop *bishopI;
	Bishop *bishopJ;
	Bishop *bishopK;
	Bishop *bishopL;
	Bishop *bishopM;


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
