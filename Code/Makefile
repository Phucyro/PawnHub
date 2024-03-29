FLAGS= -std=c++17 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Wstrict-null-sentinel -Wold-style-cast -Weffc++ -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override -Woverloaded-virtual -Winline
FLAGS2= -std=c++17 -masm=intel -fconcepts -mlong-double-128 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Wsign-conversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override -lquadmath

all: mainTest testClassic testHorde testDark clean run

mainTest: testRook.o testBishop.o testCoordinate.o testBoard.o Board.o Coordinate.o Game.o mainTest.cpp Piece.o Bishop.o testKnight.o Knight.o Classic.o Rook.o  GhostPawn.o Pawn.o testPawn.o Player.o King.o testKing.o Queen.o 
	g++ $(FLAGS) testBoard.o Piece.o Coordinate.o Board.o testCoordinate.o Player.hpp testBishop.o Game.o Bishop.o testKnight.o Knight.o Classic.o testRook.o Rook.o  Pawn.o testPawn.o King.o testKing.o Queen.o GhostPawn.o Player.o mainTest.cpp -o mainTest -lcppunit

testClassic: testClassic.cpp Board.o Coordinate.o Game.o Piece.o Bishop.o Knight.o Classic.o Rook.o  GhostPawn.o Pawn.o Player.o King.o Queen.o Socket.o
	g++ $(FLAGS) Piece.o Coordinate.o Board.o Game.o Bishop.o Knight.o Classic.o Rook.o  Pawn.o King.o Queen.o GhostPawn.o Player.o Socket.o testClassic.cpp -o testClassic

testHorde: testHorde.cpp Board.o Coordinate.o Game.o Piece.o Bishop.o Knight.o Horde.o Rook.o  GhostPawn.o Pawn.o Player.o King.o Queen.o Socket.o
	g++ $(FLAGS) Piece.o Coordinate.o Board.o Game.o Bishop.o Knight.o Horde.o Rook.o  Pawn.o King.o Queen.o GhostPawn.o Player.o Socket.o testHorde.cpp -o testHorde

testDark: testDark.cpp Board.o Coordinate.o Game.o Piece.o Bishop.o Knight.o Dark.o Rook.o  GhostPawn.o Pawn.o Player.o King.o Queen.o Socket.o
	g++ $(FLAGS) Piece.o Coordinate.o Board.o Game.o Bishop.o Knight.o Dark.o Rook.o  Pawn.o King.o Queen.o GhostPawn.o Player.o Socket.o testDark.cpp -o testDark


testCoordinate.o: testCoordinate.cpp testCoordinate.hpp Coordinate.hpp SimpleGame.hpp
	g++ -c $(FLAGS) testCoordinate.cpp -lcppunit

testBoard.o: testBoard.cpp testBoard.hpp Piece.hpp Board.hpp Coordinate.hpp SimpleGame.hpp
	g++ -c $(FLAGS) testBoard.cpp -lcppunit

testBishop.o : testBishop.cpp testBishop.hpp Piece.hpp Board.hpp Game.hpp SimpleGame.hpp
	g++ -c $(FLAGS) testBishop.cpp -lcppunit

testKnight.o : testKnight.cpp testKnight.hpp Piece.hpp Board.hpp Game.hpp SimpleGame.hpp
	g++ -c $(FLAGS) testKnight.cpp -lcppunit

testRook.o : testRook.cpp testRook.hpp Piece.hpp Board.hpp Game.hpp SimpleGame.hpp
	g++ -c $(FLAGS) testRook.cpp -lcppunit

testPawn.o : testPawn.cpp testPawn.hpp Piece.hpp Board.hpp Game.hpp SimpleGame.hpp
	g++ -c $(FLAGS) testPawn.cpp -lcppunit

testKing.o : testKing.cpp testKing.hpp Piece.hpp Board.hpp Game.hpp SimpleGame.hpp
	g++ -c $(FLAGS) testKing.cpp -lcppunit


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

King.o: King.cpp King.hpp Pawn.hpp Rook.hpp Game.hpp Board.hpp Coordinate.hpp Piece.hpp GhostPawn.hpp
	g++ -c $(FLAGS) King.cpp

Queen.o: Queen.cpp Queen.hpp Game.hpp Board.hpp Coordinate.hpp Piece.hpp Piece.cpp Pawn.hpp GhostPawn.hpp
	g++ -c $(FLAGS) Queen.cpp

GhostPawn.o: GhostPawn.cpp Pawn.hpp Game.hpp Board.hpp Coordinate.hpp Piece.hpp GhostPawn.hpp
	g++ -c $(FLAGS) GhostPawn.cpp

Game.o: Board.hpp Coordinate.hpp Piece.hpp Player.hpp Game.hpp Game.cpp
	g++ -c $(FLAGS) Game.cpp

Classic.o: Board.hpp Coordinate.hpp Piece.hpp Player.hpp Game.hpp Classic.hpp Classic.cpp
	g++ -c $(FLAGS) Classic.cpp
	
Horde.o: Board.hpp Coordinate.hpp Piece.hpp Player.hpp Game.hpp Horde.hpp Horde.cpp
	g++ -c $(FLAGS) Horde.cpp

Dark.o: Board.hpp Coordinate.hpp Piece.hpp Player.hpp Game.hpp Dark.hpp Dark.cpp
	g++ -c $(FLAGS) Dark.cpp

Player.o: Board.hpp Coordinate.hpp Piece.hpp Game.hpp Player.hpp Player.cpp
	g++ -c $(FLAGS) Player.cpp

Socket.o: ../Communication/Socket.cpp ../Communication/Socket.hpp ../Communication/config.hpp
	g++ -c $(FLAGS) ../Communication/Socket.cpp



run : mainTest
	./$<
clean:
	rm *.o

mrproper: clean
	rm -f test
.PHONY : clean
