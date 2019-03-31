#ifndef __PLAYER__HPP__
#define __PLAYER__HPP__

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <iostream>
#include <mutex>
#include <queue>
#include "Game.hpp"
#include "Board.hpp"
#include "../Communication/Socket.hpp"
#include "../Communication/ServerGameControl.hpp"
#include "../Communication/Data.hpp"

class Player{

	private :
	Socket *_sock;
	ServerGameControl* _control;
	int *_pipe;
	int *_pipeControl;
	std::string _name = "Guest";
	int _queueNumber = -1; // Numero de file inexistante
	bool _recvActive;
	bool _realTime;
	char _color;
	std::mutex *_inGameMutex;
	std::queue<std::string> _premoves;


	public :
	Player(Socket* socket): _sock(socket), _control(nullptr), _pipe(nullptr), _pipeControl(nullptr), _recvActive(false), _realTime(false), _color('\0'), _inGameMutex(nullptr), _premoves() {
		_pipe = new int[2];
		if ((pipe(_pipe)) == -1) throw std::runtime_error("Fail while constructing a pipe for an object of type 'Player': ");
		
		_pipeControl = new int[2];
		if ((pipe(_pipeControl)) == -1) throw std::runtime_error("Fail while constructing a pipe for an object of type 'Player': ");
		
		_inGameMutex = new std::mutex();
	}
	Player(const Player&) = delete;
	Player(Player&& original): _sock(original._sock), _control(original._control), _pipe(original._pipe), _pipeControl(original._pipeControl), _name(original._name), _recvActive(original._recvActive), _realTime(false) {original._pipe = nullptr;}

	~Player(){
		delete _sock;
		close(_pipe[0]);
		close(_pipe[1]);
		delete[] _pipe;
		delete _inGameMutex;
		close(_pipeControl[0]);
		close(_pipeControl[1]);
		delete[] _pipeControl;
	}

	Player& operator= (const Player&) = delete;
	Player& operator= (Player&& original);

	std::string askMove();
	void cleanPreMove() {while (!_premoves.empty()) _premoves.pop();}
	void showBoard(std::string);
	char askPromotion();
	std::string getName() const;
	Socket* getSocket() const;
	int getQueueNumber() const;
	std::queue<std::string>& getPreMoves() {return _premoves;}
	void setName(std::string);
	void setControl(ServerGameControl*);
	void setSocket(Socket*);
	void setQueueNumber(int);
	void setColor(char);
	char getColor() const {return _color;}
	int getReadPipe() const {return _pipe[0];}
	void activateControlRecv();
	void enterRealTime(){_realTime = true;}
	void endRealTime(){_realTime = false;}

	void transferFirstMsg();
	void transferStart();
	void transferUpdate(std::string&);
	void transferCheck();
	void transferCheckmate(std::string&);
	void transferStalemate();
	void transferSurrend();
	void transferTimeout();
	void transferGameMode(std::string&);
	void transferColour(std::string&);
	void transferTurn(unsigned);
	void transferTime(int);
	void transferGoodMove();
	void transferGoodPremove();
	void receiveMove(std::string&);
	void receivePromotion(std::string&);
	void surrend();
	void startGame();
	void endGame();
	void waitEndGame(){startGame();endGame();}
	bool isInGame();
	std::string readControlPipe();
	void writeControlPipe(std::string msg);
};

#endif
