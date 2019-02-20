FLAGS= -std=c++17 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Weffc++ -Wstrict-null-sentinel -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

CXX= g++

CONFIG= Communication/config.hpp
SOCKETS= Communication/Socket.o Communication/BindSocket.o
GAME_CLIENT= Communication/ClientGameControl.o
DISPLAY_CLIENT= GameDisplay/board.o
GAME_SERVER= Communication/ServerMessageParser.hpp

CLIENT_LFLAGS= -pthread -lncurses
SERVER_LFLAGS= -pthread

all: clean server client

run: all
	./server

client: Communication/client.o $(SOCKETS) $(GAME_CLIENT) $(DISPLAY_CLIENT) $(CONFIG)
	$(CXX) $(FLAGS) -o $@ $^ $(CLIENT_LFLAGS)

server: Communication/server.o $(SOCKETS) $(GAME_SERVER) $(CONFIG)
	$(CXX) $(FLAGS) -o $@ $^ $(SERVER_LFLAGS)

%.o: %.cpp %.hpp
	$(CXX) $(FLAGS) -c -o $@ $<

clean:
	rm -f *.o Communication/*.o GameDisplay/*.o GameLogic/*.o

deepclean: clean
	rm -f server client
