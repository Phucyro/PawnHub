#include "config.hpp"

#ifndef  _SOCK_H_
#define  _SOCK_H_

class Socket {
private:
  int file_descriptor;
  char recv_buffer[MSG_LENGTH];

public:
  Socket();
  Socket(int);
  ~Socket();

  int getFileDescriptor();
  bool connectToServer(std::string);
  bool isConnected();
  // void closeSocket();

  void printSend(std::string);
  void sendMessage(std::string);
  bool parseBuffer(std::string&);
  std::string receiveMessage();
};

#endif
