#include "Socket.hpp"

Socket::Socket() {
  file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(MYPORT);
  my_addr.sin_addr.s_addr = INADDR_ANY;
  memset(&(my_addr.sin_zero), '\0', 8);
}

Socket::Socket(std::string ip_addr) {
  Socket();
  my_addr.sin_addr.s_addr = inet_addr(ip_addr);
}

Socket::~Socket() {
  close(file_descriptor);
}

int Socket::getFileDescriptor() {
  return file_descriptor;
}

sockaddr_in Socket::getAddress() {
  return my_addr;
}
