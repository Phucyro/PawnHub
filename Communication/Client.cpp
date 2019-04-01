#include "Client.hpp"

Socket* Client::getSocket(){
  return _socket;
}

std::string Client::getName(){
  return _nickname;
}

void Client::setName(std::string name){
  _nickname = name;
}

bool Client::isIdentified(){
  return _identified;
}

void Client::setIdentified(){
  _identified = true;
}

std::string Client::readPipe(){
	char buffer[MSG_LENGTH+1];

	read(_pipeControl[0], buffer, sizeof(buffer));
	std::string msg = buffer;
	return msg;
}

void Client::writePipe(std::string msg){
	char buffer[MSG_LENGTH+1];

	std::strcpy(buffer, msg.c_str());
	write(_pipeControl[1], buffer, sizeof(buffer));
}

std::string Client::readGame(){
	char buffer[MSG_LENGTH+1];

	read(_pipeGameMessage[0], buffer, sizeof(buffer));
	std::string msg = buffer;
	return msg;
}

void Client::writeGame(std::string msg){
	char buffer[MSG_LENGTH+1];

	std::strcpy(buffer, msg.c_str());
	write(_pipeGameMessage[1], buffer, sizeof(buffer));
}

int Client::getReadGamePipe(){
	return _pipeGameMessage[0];
}

std::vector<std::string> Client::getFriends(){
  _friendsMutex.lock();
  std::vector<std::string> friends = _friendsList;
  _friendsMutex.unlock();
  return friends;
}

std::vector<std::string> Client::getSentRequest(){
  _sentMutex.lock();
  std::vector<std::string> sent = _sentRequest;
  _sentMutex.unlock();
  return sent;
}

std::vector<std::string> Client::getRecvRequest(){
  _recvMutex.lock();
  std::vector<std::string> received = _recvRequest;
  _recvMutex.unlock();
  return received;
}

void Client::addFriend(std::string name){
  _friendsMutex.lock();
  if (_receivedInfo)
    _friendsList.push_back(name);
  _friendsMutex.unlock();
}

void Client::removeFriend(std::string name){
  _friendsMutex.lock();
  if (_receivedInfo)
    _friendsList.erase(std::remove(_friendsList.begin(), _friendsList.end(), name), _friendsList.end());
  _friendsMutex.unlock();
}

void Client::addRecvRequest(std::string name){
  _recvMutex.lock();
  if (_receivedInfo)
    _recvRequest.push_back(name);
  _recvMutex.unlock();
}

void Client::addSentRequest(std::string name){
  _sentMutex.lock();
  if (_receivedInfo)
    _sentRequest.push_back(name);
  _sentMutex.unlock();
}

bool Client::hasRequestFrom(std::string name){
  bool found = false;
  unsigned int a = 0;

  _recvMutex.lock();
  while (a < _recvRequest.size() && !found){
    if (_recvRequest[a] == name) found = true;
    ++a;
  }
  _recvMutex.unlock();

  return found;
}

void Client::removeRecvRequest(std::string name){
  _recvMutex.lock();
  if (_receivedInfo)
    _recvRequest.erase(std::remove(_recvRequest.begin(), _recvRequest.end(), name), _recvRequest.end());
  _recvMutex.unlock();
}

bool Client::isFriendWith(std::string name){
  bool found = false;
  unsigned int a = 0;

  _friendsMutex.lock();
  while (a < _friendsList.size() && !found){
    if (_friendsList[a] == name) found = true;
    ++a;
  }
  _friendsMutex.unlock();

  return found;
}

bool Client::hasSentTo(std::string name){
  bool found = false;
  unsigned int a = 0;

  _sentMutex.lock();
  while (a < _sentRequest.size() && !found){
    if (_sentRequest[a] == name) found = true;
    ++a;
  }
  _sentMutex.unlock();

  return found;
}

void Client::removeSentRequest(std::string name){
  _sentMutex.lock();
  if (_receivedInfo)
    _sentRequest.erase(std::remove(_sentRequest.begin(), _sentRequest.end(), name), _sentRequest.end());
  _sentMutex.unlock();
}

void Client::setIsChatting(bool chatting){
  _isChatting = chatting;
}

bool Client::isChatting(){
  return _isChatting;
}

void Client::setIsChattingWith(std::string name){
  _chatTarget = name;
}

std::string Client::getIsChattingWith(){
  return _chatTarget;
}

bool Client::isChattingWith(std::string name){
  if (_chatTarget == name){
    return true;
  }
  return false;
}

Conversation Client::getConversation(std::string name){
  Conversation conv;

  _convMutex.lock();
  if (_conversations.find(name) == _conversations.end()){
    conv = {};
  }
  else {
    conv = _conversations[name];
  }
  _convMutex.unlock();

  return conv;
}

void Client::updateConversation(std::string target, std::string sender, std::string msg){
  _convMutex.lock();
  _conversations[target].push_back({sender, msg});

  if (_conversations[target].size() > 30){
    _conversations[target].erase(_conversations[target].begin());
  }
  _convMutex.unlock();
}

bool Client::getReceivedInfo(){
  return _receivedInfo;
}

void Client::setReceivedInfo(bool received){
  _receivedInfo = received;
}
