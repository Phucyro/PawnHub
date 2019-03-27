#include <iostream>
#include <cstring>

#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


#define PORT 9797
#define BACKLOG 20
#define MSG_LENGTH 300
#define PADDING '|'
