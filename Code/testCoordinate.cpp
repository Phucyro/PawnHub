#ifndef __TEST__COORDINATE__CPP__
#define __TEST__COORDINATE__CPP__

#include"testCoordinate.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION (TestCoordinate);

void TestCoordinate :: setUp(void)
{
	a = new Coordinate(0,0);
	b = new Coordinate(7,7);
	c = new Coordinate(4,3);
	d = new Coordinate(2,5);
}


void TestCoordinate :: tearDown(void)
{
	delete a;
	delete b;
	delete c;
	delete d;
}




void TestCoordinate :: testAbstractConstructor(void)
{
	CPPUNIT_ASSERT (Coordinate('A','1').getRealColumn() == 0);
	CPPUNIT_ASSERT (Coordinate('H','8').getRealColumn() == 7);
	CPPUNIT_ASSERT (Coordinate('E','4').getRealColumn() == 4);
	CPPUNIT_ASSERT (Coordinate('C','6').getRealColumn() == 2);
	CPPUNIT_ASSERT (Coordinate('A','1').getRealRow() == 0);
	CPPUNIT_ASSERT (Coordinate('H','8').getRealRow() == 7);
	CPPUNIT_ASSERT (Coordinate('E','4').getRealRow() == 3);
	CPPUNIT_ASSERT (Coordinate('C','6').getRealRow() == 5);
}


void TestCoordinate :: testEqual(void)
{
	CPPUNIT_ASSERT (*a == Coordinate(0,0));
	CPPUNIT_ASSERT (*b == Coordinate(7,7));
	CPPUNIT_ASSERT (*c == Coordinate(4,3));
	CPPUNIT_ASSERT (*d == Coordinate(2,5));
}


void TestCoordinate :: testGetAbstractColumn(void)
{
	CPPUNIT_ASSERT_EQUAL (a->getAbstractColumn(),'A');
	CPPUNIT_ASSERT_EQUAL (b->getAbstractColumn(),'H');
	CPPUNIT_ASSERT_EQUAL (c->getAbstractColumn(),'E');
	CPPUNIT_ASSERT_EQUAL (d->getAbstractColumn(),'C');
}


void TestCoordinate :: testGetAbstractRow(void)
{
	CPPUNIT_ASSERT_EQUAL (a->getAbstractRow(),'1');
	CPPUNIT_ASSERT_EQUAL (b->getAbstractRow(),'8');
	CPPUNIT_ASSERT_EQUAL (c->getAbstractRow(),'4');
	CPPUNIT_ASSERT_EQUAL (d->getAbstractRow(),'6');
}

#endif



















































