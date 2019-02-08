#include "Socket.hpp"

Socket::Socket() {
  file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (file_descriptor < 0) {
    std::cout << "[Error] Socket" << std::endl;
  }
}

Socket::Socket(int fd) {
  file_descriptor = fd;
}

Socket::~Socket() {
  close(file_descriptor);
}

int Socket::getFileDescriptor() {
  return file_descriptor;
}

void Socket::connectToServer(sockaddr_in serv_addr) {
  if (connect(getFileDescriptor(), (sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    std::cout << "[Error] Connect" << std::endl;
  }
  else std::cout << "Connected to server!" << std::endl;
}
