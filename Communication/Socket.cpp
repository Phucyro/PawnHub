#include "Socket.hpp"
#include <execinfo.h>
#include <csignal>
#include <iostream>
#include <unistd.h>

void handleSignal(int signum){
	std::cout<<"signal handling: "<<signum<<std::endl;
}

Socket::Socket() : file_descriptor(0), monMutex() {
  file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (file_descriptor < 0) {
    throw std::runtime_error("Instantiation failed");
  }
}

Socket::Socket(int fd) : file_descriptor(fd), monMutex() {}

Socket::~Socket() {
  std::cout << "Closing Socket" << std::endl;
  close(getFileDescriptor());
}

int Socket::getFileDescriptor() {
  return file_descriptor;
}

bool Socket::connectToServer(std::string hostname) {
  // const char* converted_name = hostname.c_str();
  hostent* host_addr;
  if((host_addr = gethostbyname(hostname.c_str())) == nullptr){
    std::cout << "Hostname not found" << std::endl;
    return false;
  }

  sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  serv_addr.sin_addr.s_addr = *((in_addr_t*) host_addr->h_addr); // Addresse IP a remplacer
  memset(&(serv_addr.sin_zero), '\0', 8);

  if (connect(getFileDescriptor(), (sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    throw std::runtime_error("Connect failed");
  }
  else std::cout << "Connected to server!" << std::endl;
  return true;
}

// void Socket::closeSocket() {
//   close(getFileDescriptor());
// }


void Socket::printSend(std::string message) {
  std::cout<< "Message sent: " << message <<std::endl;
  sendMessage(message);
}

// Might break but my balmer peak state says it's perfect
void Socket::sendMessage(std::string message) {
  // if (message[0] == 'B') throw std::string("Sent board too early");
  //std::cout<<"message send: "<<message<<std::endl;
  signal(SIGPIPE, handleSignal);
	
  size_t message_size = message.length();
  if ((message_size % MSG_LENGTH) == 0) {
    message = message.append(std::string(MSG_LENGTH, PADDING));
  }
  else message = message.append(std::string(MSG_LENGTH - (message_size % MSG_LENGTH), PADDING));
  const char* str_ptr = message.c_str();
	
	ssize_t bytes_sent = 0;
  size_t total_sent = 0;
  if (message.length() == MSG_LENGTH) {
    while (total_sent < MSG_LENGTH){
      str_ptr += bytes_sent;
   	  bytes_sent = send(getFileDescriptor(), str_ptr, (MSG_LENGTH - total_sent), 0);
      if (bytes_sent < 0) {
        throw std::runtime_error("Send failed");
      }
      total_sent += bytes_sent;
    }
  }
  else {

    while (total_sent <= message_size) {
      str_ptr += bytes_sent;
      bytes_sent = send(getFileDescriptor(), str_ptr, (message_size - total_sent), 0);
      if (bytes_sent < 0) {
        throw std::runtime_error("Send failed");
      }
      total_sent += bytes_sent;
    }
  }
}

bool Socket::parseBuffer(std::string& message) {
  for (int i = 0; i < MSG_LENGTH; ++i) {
    if (recv_buffer[i] == PADDING) {
      return true;
    }
    else message += recv_buffer[i];
  }
  return false;
}

std::string Socket::receiveMessage() {
  signal(SIGPIPE, handleSignal);
  std::string message;

  bool message_done = false;
  while (!message_done) {
    ssize_t bytes_received = recv(getFileDescriptor(), recv_buffer, MSG_LENGTH, 0);
    usleep(10);    
    if (bytes_received < 0) {
      throw std::runtime_error("Receive failed");
    }
    else if (bytes_received == 0) { // L'utilisateur s'est deconnecte
      throw std::runtime_error("Socket shutdown");
      // closeSocket();
    }
    else {
      message_done = parseBuffer(message);
    }
  }
  return message;
}

void Socket::lockMutex(){
  monMutex.lock();
}

void Socket::unlockMutex(){
  monMutex.unlock();
}
