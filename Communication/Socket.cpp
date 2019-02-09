#include "Socket.hpp"

Socket::Socket() : file_descriptor(0) {
  file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (file_descriptor < 0) {
    std::cout << "[Error] Socket" << std::endl;
  }
}

Socket::Socket(int fd) : file_descriptor(fd) {}

Socket::~Socket() {
  close(file_descriptor);
}

int Socket::getFileDescriptor() {
  return file_descriptor;
}

void Socket::connectToServer(std::string ip_addr) {
  const char* converted_addr = ip_addr.c_str();
  sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(MYPORT);
  serv_addr.sin_addr.s_addr = inet_addr(converted_addr); // Addresse IP a remplacer
  memset(&(serv_addr.sin_zero), '\0', 8);

  if (connect(getFileDescriptor(), (sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    std::cout << "[Error] Connect" << std::endl;
  }
  else std::cout << "Connected to server!" << std::endl;
}

void Socket::sendMessage(std::string message) {
  if (message.length() < MSG_LENGTH) {
    const char* buffer = message.c_str();
    if (send(getFileDescriptor(), buffer, MSG_LENGTH, 0) < 0) {
      std::cout << "[Error] Send" << std::endl;
    }
  }
  else std::cout << "Send: message too long" << std::endl;
}

std::string Socket::receiveMessage() {
  char receiving_buffer[MSG_LENGTH];
  ssize_t bytes_received = recv(getFileDescriptor(), receiving_buffer, MSG_LENGTH, 0);
  if (bytes_received < 0) {
    std::cout << "[Error] Recv" << std::endl;
  }
  std::string message = receiving_buffer;
  return message;
}

void Socket::sendBoard() {
  /*
  board sent as list of piece and position, white then black
  each piece 3 characters: representation symbol + position in two characters
  separation for white and black by !
  padding with #
  */

  // should be able to send matrix and converted to format here
  std::string msg = "pa2ka4r5dqc9Ke1bf8!";
  sendMessage(msg);
}
// void Socket::receiveBoard() {
//   std::string msg = receiveMessage();
//
//   unsigned int a = 0;
//   while (msg[a] != '!'){
//     std::cout << "Piece : " << pieceName[msg[a]];
//     std::cout << ", Position : " << msg[a+1] << msg[a+2];
//     std::cout << ", is white." << std::endl;
//     a += 3;
//   }
//   a += 1;
//   while (msg[a] != '#'){
//     std::cout << "Piece : " << pieceName[msg[a]];
//     std::cout << ", Position : " << msg[a+1] << msg[a+2];
//     std::cout << ", is black." << std::endl;
//     a += 3;
//   }
// }

void Socket::sendMove() {}
void Socket::receiveMove() {}
