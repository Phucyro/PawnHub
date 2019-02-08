#include "config.hpp"
#include "BindSocket.hpp"

BindSocket::BindSocket(sockaddr_in this_addr): Socket() {
  int yes = 1;
  setsockopt(getFileDescriptor(), SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int))
  bind(getFileDescriptor(), (struct sockaddr*)&this_addr, sizeof(struct sockaddr))
}

BindSocket::~BindSocket() {
  Socket::~Socket();
}

void BindSocket::activate() {
  listen(getFileDescriptor(), BACKLOG)
}

TalkSocket* BindSocket::createTalkSocket() {
  sockaddr_in their_addr;
  socklen_t their_size = sizeof(their_addr);
  int new_fd = accept(getFileDescriptor(), (struct sockaddr*)&their_addr, &their_size);
  return new TalkSocket(new_fd);
}
