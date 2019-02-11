#include "config.hpp"

#ifndef  _SOCK_H_
#define  _SOCK_H_

class Socket {
private:
  int file_descriptor;

public:
  Socket();
  Socket(int);
  ~Socket();

  int getFileDescriptor();
  void connectToServer(std::string);

  void sendMessage(std::string);
  std::string receiveMessage();
};

#endif
