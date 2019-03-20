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

std::vector<std::string> Client::getFriends(){
  return _friendsList;
}

std::vector<std::string> Client::getSentRequest(){
  return _sentRequest;
}

std::vector<std::string> Client::getRecvRequest(){
  return _recvRequest;
}

void Client::addFriend(std::string name){
  _friendsList.push_back(name);
}

void Client::removeFriend(std::string name){
  _friendsList.erase(std::remove(_friendsList.begin(), _friendsList.end(), name), _friendsList.end());
}

void Client::addRecvRequest(std::string name){
  _recvRequest.push_back(name);
}

void Client::addSentRequest(std::string name){
  _sentRequest.push_back(name);
}

bool Client::hasRequestFrom(std::string name){
  for (unsigned int a = 0; a < _recvRequest.size(); ++a){
    if (_recvRequest[a] == name) return true;
  }
  return false;
}

void Client::removeRecvRequest(std::string name){
  _recvRequest.erase(std::remove(_recvRequest.begin(), _recvRequest.end(), name), _recvRequest.end());
}

bool Client::isFriendWith(std::string name){
  for (unsigned int a = 0; a < _friendsList.size(); ++a){
    if (_friendsList[a] == name) return true;
  }
  return false;
}

bool Client::hasSentTo(std::string name){
  for (unsigned int a = 0; a < _sentRequest.size(); ++a){
    if (_sentRequest[a] == name) return true;
  }
  return false;
}

void Client::removeSentRequest(std::string name){
  _sentRequest.erase(std::remove(_sentRequest.begin(), _sentRequest.end(), name), _sentRequest.end());
}
