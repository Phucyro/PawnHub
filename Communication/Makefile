FLAGS= -std=c++17 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Weffc++ -Wstrict-null-sentinel -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

CXX= g++

CONFIG= config.hpp
SOCKETS= Socket.o BindSocket.o
LOGIN_CLIENT= LoginClient.hpp ClientMessageHandler.hpp
LOGIN_SERVER= LoginServer.hpp ServerMessageHandler.hpp Data.o SplitString.hpp
GAME_CLIENT= StartPartyClient.hpp
GAME_SERVER= StartPartyServer.hpp

all: server client clean

run: all
	./server

client: client.o $(SOCKETS) $(LOGIN_CLIENT) $(CONFIG)
	$(CXX) $(FLAGS) -o $@ $^

server: server.o $(SOCKETS) $(LOGIN_SERVER) $(CONFIG)
	$(CXX) $(FLAGS) -o $@ $^ -lpthread

%.o: %.cpp %.hpp
	$(CXX) $(FLAGS) -c -o $@ $<

clean:
	rm -f *.o

deepclean: clean
	rm -f server client
