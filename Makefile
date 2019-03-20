FLAGS= -std=c++17 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Weffc++ -Wstrict-null-sentinel -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

CXX= g++

LOGIC= $(wildcard Code/*.cpp)
CONFIG= Communication/config.hpp
SOCKETS= Communication/Socket.o Communication/BindSocket.o
LOGIN_CLIENT= Communication/ClientMessageHandler.hpp Communication/ClientFunctions.hpp Communication/SplitString.o Communication/CheckFormat.o Communication/Menu.hpp
LOGIN_SERVER= Communication/ServerMessageHandler.hpp Communication/ServerHandler.hpp Communication/cleanThread.hpp Communication/Data.o Communication/SplitString.o Communication/Matchmaking.o Communication/ExecInfoThread.o
GAME_CLIENT= Communication/ClientGameControl.o
# DISPLAY_CLIENT= Display/GameDisplay/board.o Display/MenuHandler/MenuHandler.o
DISPLAY_CLIENT= Qt_UI/Connection/connectiondialog.o
GAME_SERVER=  Code/includesPieceHPP.hpp $(subst Code/%.cpp, Code/%.o, $(LOGIC)) Communication/ServerGameControl.o

INCLUDE= -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets

CLIENT_LFLAGS= -lpthread -lncurses -L/usr/lib/x86_64-linux-gnu -L/usr/lib/qt5/bin -lQt5Gui -lQt5Core -lQt5Widgets
SERVER_LFLAGS= -lpthread

all: server client clean

run: all
	./server

client: Communication/client.o $(SOCKETS) $(GAME_CLIENT) $(LOGIN_CLIENT) $(DISPLAY_CLIENT) $(CONFIG)
	$(CXX) $(FLAGS) -o $@ $^ $(CLIENT_LFLAGS) $(INCLUDE)

server: Communication/server.o $(SOCKETS) $(GAME_SERVER) $(LOGIN_SERVER) $(CONFIG)
	$(CXX) $(FLAGS) -o $@ $^ $(SERVER_LFLAGS)

Communication/%.o: %.cpp %.hpp
	$(CXX) $(FLAGS) -c -o $@ $<

Code/%.o: %.cpp %.hpp
	$(CXX) $(FLAGS) -c -o $@ $<

Qt_UI/Connection/%.o:
	Qt_UI/Connection/make $@




# -------------------------------------

clean:
	rm -f *.o Communication/*.o Display/GameDisplay/*.o Display/MenuHandler/*.o Code/*.o

deepclean: clean
	rm -f server client
