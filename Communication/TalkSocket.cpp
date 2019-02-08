#include "config.hpp"
#include "TalkSocket.hpp"

TalkSocket::TalkSocket(int fd): Socket(fd) {}

TalkSocket::~TalkSocket() {}

void TalkSocket::sendMessage() {}

std::string TalkSocket::receiveMessage() {}
