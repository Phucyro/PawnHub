#include "Socket.hpp"

#ifndef  _BINDSOCK_H_
#define  _BINDSOCK_H_

class BindSocket : public Socket {
public:
  BindSocket();
  ~BindSocket();

  void activate();
  Socket createSocket();
};

#endif
