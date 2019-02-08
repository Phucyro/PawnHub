#include "TalkSocket.hpp"

#ifndef  _BINDSOCK_H_
#define  _BINDSOCK_H_

class BindSocket : public Socket {
public:
  BindSocket(sockaddr_in this_addr);
  ~BindSocket();

  void activate();
  TalkSocket createTalkSocket(sockaddr_in their_addr);
};

#endif
