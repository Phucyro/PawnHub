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

class Player{

	private :
	Socket *_sock;
	int *_pipe;
	std::string _name = "Guess";
	int _queueNumber = -1; // Numero de file inexistante


	public :
	Player(Socket* socket): _sock(socket), _pipe(nullptr) {
		_pipe = new int[2];
		if ((pipe(_pipe)) == -1) throw std::runtime_error("Fail while constructing a pipe for an object of type 'Player': ");
	}
	Player(const Player&) = delete;
	Player(Player&& original): _sock(original._sock), _pipe(original._pipe), _name(original._name) {original._pipe = nullptr;}

	~Player(){
		delete[] _pipe;
		_sock = nullptr;
		close(_pipe[0]);
		close(_pipe[1]);
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
	void setSocket(Socket*);
	void setQueueNumber(int);
	void reciveMove(std::string&);
	void recivePromotion(std::string&);
};

#endif
