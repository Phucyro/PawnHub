#include "config.hpp"
#include "TalkSocket.hpp"

TalkSocket::TalkSocket(int fd): Socket(fd) {}

TalkSocket::~TalkSocket() {
  Socket::~Socket();
}

void TalkSocket::sendMessage() {}

std::string TalkSocket::receiveMessage() {}
