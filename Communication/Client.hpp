#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#include "Socket.hpp"
#include "config.hpp"
#include <unistd.h>
#include <string>
#include <mutex>
#include <vector>
#include <algorithm>


class Client {
private:
  Socket* _socket;
  int* _pipeControl;
  bool _identified;
  std::string _nickname;
  std::vector<std::string> _friendsList;
  std::vector<std::string> _sentRequest; // Demande d'ami envoyee
  std::vector<std::string> _recvRequest; // Demande d'ami recue

public:
  Client(Socket* socket) : _socket(socket), _pipeControl(nullptr), _nickname("Guest"), _identified(false), _friendsList({}), _sentRequest({}), _recvRequest({}) {
    _pipeControl = new int[2];

    if ((pipe(_pipeControl)) == -1){
      throw std::runtime_error("Fail while constructing a pipe for an object of type 'Client': ");
    }
  }

  ~Client(){
    delete _socket;
    close(_pipeControl[0]);
    close(_pipeControl[1]);
    delete[] _pipeControl;
  }

  Socket* getSocket();
  bool isIdentified();
  void setIdentified();
  std::string getName();
  void setName(std::string name);
  std::vector<std::string> getFriends();
  std::vector<std::string> getSentRequest();
  std::vector<std::string> getRecvRequest();
  void addFriend(std::string name);
  void removeFriend(std::string name);
  void addRecvRequest(std::string name);
  void addSentRequest(std::string name);
  bool hasRequestFrom(std::string name);
  void removeRecvRequest(std::string name);
  bool isFriendWith(std::string name);
  bool hasSentTo(std::string name);
  void removeSentRequest(std::string name);
  std::string readPipe();
	void writePipe(std::string msg);
};

#endif