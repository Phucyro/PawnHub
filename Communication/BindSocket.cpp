#include "config.hpp"
#include "BindSocket.hpp"

BindSocket::BindSocket(sockaddr_in this_addr): Socket() {
  // Permet a plusieurs socket de bind() sur le meme port
  int yes = 1;
  if (setsockopt(getFileDescriptor(), SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) < 0) {
    std::cout << "[Error] Setsockopt" << std::endl;
  }

  // Lier socket au port et a l'adresse
  if (bind(getFileDescriptor(), (struct sockaddr*)&this_addr, sizeof(struct sockaddr)) < 0) {
    std::cout << "[Error] Bind" << std::endl;
  }
}

BindSocket::~BindSocket() {}

void BindSocket::activate() {
  if (listen(getFileDescriptor(), BACKLOG) < 0) {
    std::cout << "[Error] Listen" << std::endl;
  }
}

TalkSocket BindSocket::createTalkSocket(sockaddr_in their_addr) {
  socklen_t their_size = sizeof(their_addr);
  int new_fd = accept(getFileDescriptor(), (struct sockaddr*)&their_addr, &their_size);
  if (new_fd < 0) {
    std::cout << "[Error] Accept" << std::endl;
  }
  return TalkSocket(new_fd);
}
