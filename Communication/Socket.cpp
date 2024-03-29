#include "Socket.hpp"

#include <execinfo.h>
#include <csignal>
#include <iostream>
#include <unistd.h>

Socket::Socket() : file_descriptor(0) {
  file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (file_descriptor < 0) {
    throw std::runtime_error("Instantiation failed");
  }
}

Socket::Socket(int fd) : file_descriptor(fd) {}

Socket::~Socket() {
  std::cout << "Closing Socket" << std::endl;
  close(getFileDescriptor());
}

int Socket::getFileDescriptor() {
  return file_descriptor;
}

bool Socket::connectToServer(std::string hostname) {
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

void Socket::printSend(std::string message) {
  std::cout<< "Message sent: " << message <<std::endl;
  sendMessage(message);
}

void Socket::sendMessage(std::string message) {
  size_t message_size = message.length();
  if ((message_size % MSG_LENGTH) == 0) {
    message.append(MSG_LENGTH, PADDING);
  }
  else{
		message.append(MSG_LENGTH - (message_size % MSG_LENGTH), PADDING);
	}
	const char* str_ptr = message.c_str();

	ssize_t bytes_sent = 0;
  size_t total_sent = 0;
    while (total_sent < message.length()) {
    str_ptr += bytes_sent;
    bytes_sent = send(getFileDescriptor(), str_ptr, (message.length() - total_sent), MSG_NOSIGNAL);
    if (bytes_sent < 0) {
      throw std::runtime_error("Send failed");
    }
    total_sent += bytes_sent;
  }
}

bool Socket::parseBuffer(std::string& message) {
  for (int i = 0; i < MSG_LENGTH; ++i) {
    if (recv_buffer[i] == PADDING) {
      return true;
    }
		else {
	    message += recv_buffer[i];
		}
  }
  return false;
}

std::string Socket::receiveMessage() {
  std::string message;

  bool message_done = false;
  while (!message_done) {
    ssize_t bytes_received = recv(getFileDescriptor(), recv_buffer, MSG_LENGTH, 0);
    usleep(10); // it just make it work
    if (bytes_received < 0) {
      throw std::runtime_error("Receive failed");
    }
    else if (bytes_received == 0) { // L'utilisateur s'est deconnecte
      throw std::runtime_error("Socket shutdown");
    }
    else {
      message_done = parseBuffer(message);
    }
  }
  return message;
}
