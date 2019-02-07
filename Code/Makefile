all: mainTest

mainTest: testCoordinate.o Coordinate.o mainTest.cpp 
	g++ -Wall  mainTest.cpp -o mainTest -lcppunit

testCoordinate.o: testCoordinate.cpp testCoordinate.hpp
	g++ -c -Wall testCoordinate.cpp 


Coordinate.o: Coordinate.cpp Coordinate.hpp
	g++ -c -Wall Coordinate.cpp
