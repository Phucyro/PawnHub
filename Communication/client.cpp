#include "config.hpp"


int main(){
  // Initialisation socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1){
    std::cerr << "[Error] Socket" << std::endl;
    return 1;
  }

  sockaddr_in their_addr;
  their_addr.sin_family = AF_INET;
  their_addr.sin_port = htons(MYPORT);
  their_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Addresse IP a remplacer
  memset(&(their_addr.sin_zero), '\0', 8);

  // Demande de connexion au serveur
  int connectRes = connect(sockfd, (sockaddr*)&their_addr, sizeof(their_addr));

  if (connectRes == -1){
    std::cerr << "[Error] Connect" << std::endl;
    return 1;
  }
  else {
    std::cout << "Connected from " << sockfd << std::endl;
  }

  while (true) {
    sleep(2);
  }
  // Operations avec le serveur

  close(sockfd);

  return 0;
}
