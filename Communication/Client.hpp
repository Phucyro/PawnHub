#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_

#include "Socket.hpp"
#include "config.hpp"
#include <unistd.h>
#include <string>
#include <mutex>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

typedef std::vector<std::tuple<std::string, std::string>> Conversation;

class Client {
private:
  Socket* _socket;
  int* _pipeControl, *_pipeGameMessage;
  bool _identified;
  std::string _nickname;
  std::map<std::string, Conversation> _conversations;
  bool _isChatting;
  std::string _chatTarget;
  std::vector<std::string> _friendsList;
  std::vector<std::string> _sentRequest; // Demande d'ami envoyee
  std::vector<std::string> _recvRequest; // Demande d'ami recue

public:
  Client(Socket* socket) :
    _socket(socket),
    _pipeControl(nullptr),
    _pipeGameMessage(nullptr),
    _identified(false),
    _nickname("Guest"),
    _conversations({}),
    _isChatting(false),
    _chatTarget("all"),
    _friendsList({}),
    _sentRequest({}),
    _recvRequest({})
  {
    _pipeControl = new int[2];
    _pipeGameMessage = new int[2];

    if ((pipe(_pipeControl)) == -1){
      throw std::runtime_error("Fail while constructing a pipe for an object of type 'Client'");
    }
    if ((pipe(_pipeGameMessage)) == -1){
      throw std::runtime_error("Fail while constructing a pipe for an object of type 'Client'");
    }
  }

  ~Client(){
    delete _socket;
    close(_pipeControl[0]);
    close(_pipeControl[1]);
    delete[] _pipeControl;
    close(_pipeGameMessage[0]);
    close(_pipeGameMessage[1]);
    delete[] _pipeGameMessage;
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
  std::string readGame();
  void writeGame(std::string);
  int getReadGamePipe();
  void setIsChatting(bool chatting);
  bool isChatting();
  void setIsChattingWith(std::string name);
  std::string getIsChattingWith();
  bool isChattingWith(std::string name);
  Conversation getConversation(std::string name);
  void updateConversation(std::string target, std::string sender, std::string msg);

};

#endif
