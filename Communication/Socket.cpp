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

void Socket::connectToServer(char* ip_addr) {
  sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(MYPORT);
  serv_addr.sin_addr.s_addr = inet_addr(ip_addr); // Addresse IP a remplacer
  memset(&(serv_addr.sin_zero), '\0', 8);

  if (connect(getFileDescriptor(), (sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    std::cout << "[Error] Connect" << std::endl;
  }
  else std::cout << "Connected to server!" << std::endl;
}
