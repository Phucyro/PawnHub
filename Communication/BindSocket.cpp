#include "config.hpp"
#include "BindSocket.hpp"

BindSocket::BindSocket(): Socket() {
  sockaddr_in my_addr;
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(PORT);
  my_addr.sin_addr.s_addr = INADDR_ANY;
  memset(&(my_addr.sin_zero), '\0', 8);

  // Permet a plusieurs socket de bind() sur le meme port
  int yes = 1;
  if (setsockopt(getFileDescriptor(), SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) < 0) {
    throw std::string("[Error] Setsockopt failed");
  }

  // Lier socket au port et a l'adresse
  if (bind(getFileDescriptor(), (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) < 0) {
    throw std::string("[Error] Bind failed");
  }
}

BindSocket::~BindSocket() {}

void BindSocket::activate() {
  if (listen(getFileDescriptor(), BACKLOG) < 0) {
    throw std::string("[Error] Listen failed");
  }
}

Socket* BindSocket::createSocket() {
  sockaddr_in their_addr;
  socklen_t their_size = sizeof(their_addr);
  int new_fd = accept(getFileDescriptor(), (struct sockaddr*)&their_addr, &their_size);
  if (new_fd < 0) {
    throw std::string("[Error] Accept failed");
  }
  std::cout << "Connexion de " << inet_ntoa(their_addr.sin_addr) << std::endl;
  return new Socket(new_fd);
}
