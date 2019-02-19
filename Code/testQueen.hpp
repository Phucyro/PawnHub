#ifndef __TEST__QUEEN__HPP__
#define __TEST__QUEEN__HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Queen.hpp"
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
	bool testCheck(const char color) override {return _testCheck;}

};

class TestQueen: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE (TestQueen);
	CPPUNIT_TEST (testMove);
	CPPUNIT_TEST (testCheckMove);
	CPPUNIT_TEST_SUITE_END ();

	private:
	Queen *queenA;
  Queen *queenB;
	Queen *queenC;
	Queen *queenD;
	Queen *queenE;
	Queen *queenF;
	Queen *queenG;
	Queen *queenH;
	Queen *queenI;
	Queen *queenJ;
	Queen *queenK;
	Queen *queenL;
	Queen *queenM;


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
