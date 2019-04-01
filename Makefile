FLAGS= -std=c++17 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Weffc++ -Wstrict-null-sentinel -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

CXX= g++

LOGIC= $(wildcard Code/*.cpp)
CONFIG= Communication/config.hpp
SOCKETS= Communication/Socket.o Communication/BindSocket.o
LOGIN_CLIENT= Communication/ClientMessageHandler.hpp Communication/ClientFunctions.hpp Communication/SplitString.o Communication/CheckFormat.o Communication/Menu.hpp Communication/Client.o Communication/Timer.o
LOGIN_SERVER= Communication/ServerMessageHandler.hpp Communication/ServerHandler.hpp Communication/cleanThread.hpp Communication/Data.o Communication/SplitString.o Communication/Matchmaking.o Communication/ExecInfoThread.o
GAME_CLIENT= Communication/ClientGameControl.o
DISPLAY_CLIENT= Display/GameDisplay/board.o Display/MenuHandler/MenuHandler.o
GAME_SERVER=  Code/includesPieceHPP.hpp $(subst Code/%.cpp, Code/%.o, $(LOGIC)) Communication/ServerGameControl.o

CLIENT_LFLAGS= -lpthread -lncurses
SERVER_LFLAGS= -lpthread

all: server client clean

run: all
	./server

client: Communication/client.o $(SOCKETS) $(GAME_CLIENT) $(LOGIN_CLIENT) $(DISPLAY_CLIENT) $(CONFIG)
	$(CXX) $(FLAGS) -o $@ $^ $(CLIENT_LFLAGS)

server: Communication/server.o $(SOCKETS) $(GAME_SERVER) $(LOGIN_SERVER) $(CONFIG)
	$(CXX) $(FLAGS) -o $@ $^ $(SERVER_LFLAGS)

Communication/%.o: %.cpp %.hpp
	$(CXX) $(FLAGS) -c -o $@ $<

Code/%.o: %.cpp %.hpp
	$(CXX) $(FLAGS) -c -o $@ $<

clean:
	rm -f *.o Communication/*.o Display/GameDisplay/*.o Display/MenuHandler/*.o Code/*.o

deepclean: clean
	rm -f server client
