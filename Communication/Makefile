FLAGS= -std=c++17 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Weffc++ -Wstrict-null-sentinel -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

CXX= g++

CONFIG= config.hpp
SOCKETS= Socket.o BindSocket.o
LOGIN_CLIENT= ClientMessageHandler.hpp ClientFunctions.hpp SplitString.o
LOGIN_SERVER= ServerMessageHandler.hpp Data.o SplitString.o Matchmaking.o
GAME_CLIENT= StartPartyClient.hpp
GAME_SERVER= ../Code/Piece.o ../Code/Coordinate.o ../Code/Board.o ../Code/Game.o ../Code/Bishop.o ../Code/Knight.o ../Code/Classic.o ../Code/Rook.o ../Code/Pawn.o ../Code/King.o ../Code/Queen.o ../Code/GhostPawn.o ../Code/Player.o

all: clean server client

run: all
	./server

client: client.o $(SOCKETS) $(LOGIN_CLIENT) $(CONFIG) ClientMessageParser.hpp
	$(CXX) $(FLAGS) -o $@ $^ -lpthread

server: server.o $(SOCKETS) $(LOGIN_SERVER) $(CONFIG) $(GAME_SERVER) ServerMessageParser.hpp
	$(CXX) $(FLAGS) -o $@ $^ -lpthread

%.o: %.cpp %.hpp
	$(CXX) $(FLAGS) -c -o $@ $<


#Coordinate.o: ../Code/Coordinate.cpp ../Code/Coordinate.hpp
#	g++ -c $(FLAGS) ../Code/Coordinate.cpp

# Board.o: ../Code/Game.hpp ../Code/Board.hpp ../Code/Coordinate.hpp ../Code/Board.cpp ../Code/Board.hpp ../Code/Coordinate.hpp ../Code/Piece.hpp
# 	g++ -c $(FLAGS) ../Code/Board.cpp

#Piece.o : ../Code/Game.hpp ../Code/Board.hpp ../Code/Coordinate.hpp ../Code/Piece.hpp ../Code/Piece.cpp
#	g++ -c $(FLAGS) ../Code/Piece.cpp

#Bishop.o: ../Code/Bishop.cpp ../Code/Bishop.hpp ../Code/Game.hpp ../Code/Board.hpp ../Code/Coordinate.hpp ../Code/Piece.hpp ../Code/Piece.cpp ../Code/Pawn.hpp ../Code/GhostPawn.hpp
#	g++ -c $(FLAGS) ../Code/Bishop.cpp

#Knight.o: ../Code/Knight.cpp ../Code/Knight.hpp ../Code/Game.hpp ../Code/Board.hpp ../Code/Coordinate.hpp ../Code/Piece.hpp ../Code/Piece.cpp ../Code/Pawn.hpp ../Code/GhostPawn.hpp
#	g++ -c $(FLAGS) ../Code/Knight.cpp

#Rook.o: ../Code/Rook.cpp ../Code/Rook.hpp ../Code/Game.hpp ../Code/Board.hpp ../Code/Coordinate.hpp ../Code/Piece.hpp ../Code/Piece.cpp ../Code/Pawn.hpp ../Code/GhostPawn.hpp
#	g++ -c $(FLAGS) ../Code/Rook.cpp

# Pawn.o: ../Code/Pawn.cpp ../Code/Pawn.hpp ../Code/Game.hpp ../Code/Board.hpp ../Code/Coordinate.hpp ../Code/Piece.hpp ../Code/GhostPawn.hpp
# 	g++ -c $(FLAGS) ../Code/Pawn.cpp

# King.o: ../Code/King.cpp ../Code/King.hpp ../Code/Pawn.hpp ../Code/Rook.hpp ../Code/Game.hpp ../Code/Board.hpp ../Code/Coordinate.hpp ../Code/Piece.hpp ../Code/GhostPawn.hpp
# 	g++ -c $(FLAGS) ../Code/King.cpp

#Queen.o: ../Code/Queen.cpp ../Code/Queen.hpp ../Code/Game.hpp ../Code/Board.hpp ../Code/Coordinate.hpp ../Code/Piece.hpp ../Code/Piece.cpp ../Code/Pawn.hpp ../Code/GhostPawn.hpp
#	g++ -c $(FLAGS) ../Code/Queen.cpp

#GhostPawn.o: ../Code/GhostPawn.cpp ../Code/Pawn.hpp ../Code/Game.hpp ../Code/Board.hpp ../Code/Coordinate.hpp ../Code/Piece.hpp ../Code/GhostPawn.hpp#
	#g++ -c $(FLAGS) ../Code/GhostPawn.cpp

#Game.o: ../Code/Board.hpp ../Code/Coordinate.hpp ../Code/Piece.hpp ../Code/Player.hpp ../Code/Game.hpp ../Code/Game.cpp
#	g++ -c $(FLAGS) ../Code/Game.cpp

#Classic.o: ../Code/Board.hpp ../Code/Coordinate.hpp ../Code/Piece.hpp ../Code/Player.hpp ../Code/Game.hpp ../Code/Classic.hpp ../Code/Classic.cpp
#	g++ -c $(FLAGS) ../Code/Classic.cpp

#Player.o: ../Code/Board.hpp ../Code/Coordinate.hpp ../Code/Piece.hpp ../Code/Game.hpp ../Code/Player.hpp ../Code/Player.cpp
#	g++ -c $(FLAGS) ../Code/Player.cpp

#Matchmaking.o: Matchmaking.cpp Matchmaking.hpp ../Code/Player.hpp ../Code/Classic.hpp
#	g++ -c $(FLAGS) Matchmaking.cpp

#Data.o: Data.hpp Data.cpp
#	g++ -c $(FLAGS) Data.cpp

#SplitString.o: SplitString.hpp SplitString.cpp
#	g++ -c $(FLAGS) SplitString.cpp

clean:
	rm -f *.o

deepclean: clean
	rm -f server client
