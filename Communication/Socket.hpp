#include "config.hpp"

#ifndef  _SOCK_H_
#define  _SOCK_H_

class Socket {
private:
  int file_descriptor;

public:
  void sendMessage(std::string);
  std::string receiveMessage();

public:
  Socket();
  Socket(int);
  ~Socket();

  int getFileDescriptor();
  void connectToServer(std::string);

  void sendBoard();
  void receiveBoard();

  void sendMove();
  void receiveMove();
};

#endif
