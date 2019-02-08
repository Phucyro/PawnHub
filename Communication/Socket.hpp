#include "config.hpp"

#ifndef  _SOCK_H_
#define  _SOCK_H_

class Socket {
private:
  int file_descriptor;
  sockaddr_in my_addr;

public:
  Socket();
  Socket(std::string ip_addr);
  ~Socket();

  int getFileDescriptor();
  sockaddr_in getAddress();

};

#endif
