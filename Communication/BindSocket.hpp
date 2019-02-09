#include "Socket.hpp"

#ifndef  _BINDSOCK_H_
#define  _BINDSOCK_H_

class BindSocket : public Socket {
public:
  BindSocket(sockaddr_in this_addr);
  ~BindSocket();

  void activate();
  Socket createSocket(sockaddr_in their_addr);
};

#endif
