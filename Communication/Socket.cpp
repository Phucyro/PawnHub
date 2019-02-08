#include "config.hpp"
#include "Socket.hpp"

Socket::Socket() {
  file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
}

Socket::~Socket() {
  close(file_descriptor);
}
