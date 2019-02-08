#include "Socket.hpp"

Socket::Socket() {
  file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
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
