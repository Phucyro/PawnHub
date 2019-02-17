FLAGS= -std=c++17 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Wstrict-null-sentinel -Wold-style-cast -Weffc++ -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override -Woverloaded-virtual -Winline
FLAGS2= -std=c++17 -masm=intel -fconcepts -mlong-double-128 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Wsign-conversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override -lquadmath

all: mainTest clean run

mainTest: testRook.o testBishop.o testCoordinate.o testBoard.o Board.o Coordinate.o Game.o mainTest.cpp Piece.o Player.hpp Bishop.o testKnight.o Knight.o Classic.o Rook.o testPawn.o Pawn.o
	g++ $(FLAGS) testBoard.o Piece.o Coordinate.o Board.o Player.hpp testCoordinate.o testBishop.o Game.o Bishop.o testKnight.o Knight.o Classic.o testRook.o Rook.o testPawn.o Pawn.o mainTest.cpp -o mainTest -lcppunit



testCoordinate.o: testCoordinate.cpp testCoordinate.hpp Coordinate.hpp
	g++ -c $(FLAGS) testCoordinate.cpp -lcppunit

testBoard.o: testBoard.cpp testBoard.hpp Piece.hpp Board.hpp Coordinate.hpp
	g++ -c $(FLAGS) testBoard.cpp -lcppunit

testBishop.o : testBishop.cpp testBishop.hpp Piece.hpp Board.hpp Game.hpp
	g++ -c $(FLAGS) testBishop.cpp -lcppunit

testKnight.o : testKnight.cpp testKnight.hpp Piece.hpp Board.hpp Game.hpp
	g++ -c $(FLAGS) testKnight.cpp -lcppunit

testRook.o : testRook.cpp testRook.hpp Piece.hpp Board.hpp Game.hpp
	g++ -c $(FLAGS) testRook.cpp -lcppunit

testPawn.o : testPawn.cpp testPawn.hpp Piece.hpp Board.hpp Game.hpp
	g++ -c $(FLAGS) testPawn.cpp -lcppunit


Coordinate.o: Coordinate.cpp Coordinate.hpp
	g++ -c $(FLAGS) Coordinate.cpp

Board.o: Game.hpp Board.hpp Coordinate.hpp Board.cpp Board.hpp Coordinate.hpp Piece.hpp
	g++ -c $(FLAGS) Board.cpp

Piece.o : Game.hpp Board.hpp Coordinate.hpp Piece.hpp Piece.cpp
	g++ -c $(FLAGS) Piece.cpp

Bishop.o: Bishop.cpp Bishop.hpp Game.hpp Board.hpp Coordinate.hpp Piece.hpp Piece.cpp Pawn.hpp GhostPawn.hpp
	g++ -c $(FLAGS) Bishop.cpp

Knight.o: Knight.cpp Knight.hpp Game.hpp Board.hpp Coordinate.hpp Piece.hpp Piece.cpp Pawn.hpp GhostPawn.hpp
	g++ -c $(FLAGS) Knight.cpp

Rook.o: Rook.cpp Rook.hpp Game.hpp Board.hpp Coordinate.hpp Piece.hpp Piece.cpp Pawn.hpp GhostPawn.hpp
	g++ -c $(FLAGS) Rook.cpp

Pawn.o: Pawn.cpp Pawn.hpp Game.hpp Board.hpp Coordinate.hpp Piece.hpp GhostPawn.hpp
	g++ -c $(FLAGS) Pawn.cpp

Game.o: Board.hpp Coordinate.hpp Piece.hpp Player.hpp Game.hpp Game.cpp
	g++ -c $(FLAGS) Game.cpp

Classic.o: Board.hpp Coordinate.hpp Piece.hpp Player.hpp Game.hpp Classic.hpp Classic.cpp
	g++ -c $(FLAGS) Classic.cpp



run : mainTest
	./$<
clean:
	rm *.o

mrproper: clean
	rm -f test
.PHONY : clean
