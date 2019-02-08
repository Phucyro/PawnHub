#include "Socket.hpp"

#ifndef  _TALKSOCK_H_
#define  _TALKSOCK_H_

class TalkSocket : public Socket {
public:
  TalkSocket(int fd);
  ~TalkSocket();

  void sendMessage();
  std::string receiveMessage();
};

#endif
