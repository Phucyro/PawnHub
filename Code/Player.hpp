#ifndef __PLAYER__HPP__
#define __PLAYER__HPP__

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include "Game.hpp"
#include "Board.hpp"
#include "../Communication/Socket.hpp"
#include "../Communication/ServerGameControl.hpp"

class Player{

	private :
	Socket *_sock;
	ServerGameControl* _control;
	int *_pipe;
	std::string _name = "Guest";
	int _queueNumber = -1; // Numero de file inexistante
	bool _recvActive;


	public :
	Player(Socket* socket): _sock(socket), _control(nullptr), _pipe(nullptr), _recvActive(false) {
		_pipe = new int[2];
		if ((pipe(_pipe)) == -1) throw std::runtime_error("Fail while constructing a pipe for an object of type 'Player': ");
	}
	Player(const Player&) = delete;
	Player(Player&& original): _sock(original._sock), _control(original._control), _pipe(original._pipe), _name(original._name), _recvActive(original._recvActive) {original._pipe = nullptr;}

	~Player(){
		delete _sock;
		close(_pipe[0]);
		close(_pipe[1]);
		delete[] _pipe;
	}

	Player& operator= (const Player&) = delete;
	Player& operator= (Player&& original);

	std::string askMove();
	void showBoard(std::string);
	char askPromotion();
	std::string getName() const;
	Socket* getSocket() const;
	unsigned int getQueueNumber() const;
	void setName(std::string);
	void setControl(ServerGameControl*);
	void setSocket(Socket*);
	void setQueueNumber(int);

	void transferStart();
	void transferCheck();
	void transferCheckmate(std::string&);
	void transferStalemate();
	void transferGameMode(std::string&);
	void transferColour(std::string&);
	void transferTurn(unsigned);
	void receiveMove(std::string&);
	void receivePromotion(std::string&);
};

#endif
