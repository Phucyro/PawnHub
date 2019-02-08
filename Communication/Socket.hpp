#include "config.hpp"

#ifndef  _SOCK_H_
#define  _SOCK_H_

class Socket {
private:
  int file_descriptor;

public:
  Socket();
  Socket(int fd);
  ~Socket();

  int getFileDescriptor();

};

#endif
