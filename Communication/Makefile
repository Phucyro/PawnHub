FLAGS= -std=c++17 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Weffc++ -Wstrict-null-sentinel -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

CXX= g++

CONFIG= config.hpp
SOCKETS= Socket.o BindSocket.o
LOGIN_CLIENT= ClientMessageHandler.hpp ClientFunctions.hpp SplitString.o
LOGIN_SERVER= ServerMessageHandler.hpp Data.o SplitString.o ../Code/Player.o Matchmaking.o
GAME_CLIENT= StartPartyClient.hpp
GAME_SERVER= StartPartyServer.hpp
MSG_PARSER= MessageParser.hpp

all: clean server client

run: all
	./server

client: client.o $(SOCKETS) $(LOGIN_CLIENT) $(CONFIG) $(MSG_PARSER)
	$(CXX) $(FLAGS) -o $@ $^ -lpthread

server: server.o $(SOCKETS) $(LOGIN_SERVER) $(CONFIG) $(MSG_PARSER)
	$(CXX) $(FLAGS) -o $@ $^ -lpthread

%.o: %.cpp %.hpp
	$(CXX) $(FLAGS) -c -o $@ $<

clean:
	rm -f *.o

deepclean: clean
	rm -f server client
