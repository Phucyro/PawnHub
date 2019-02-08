#include "config.hpp"
#include <cstring>

using namespace std;

int main(){
  // Initialisation socket serveur
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1){
    cerr << "[Error] Socket" << std::endl;
    return 1;
  }

  sockaddr_in my_addr;
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(MYPORT);
  my_addr.sin_addr.s_addr = INADDR_ANY;
  memset(&(my_addr.sin_zero), '\0', 8);

  // Permet a plusieurs socket de bind() sur le meme port
  int yes = 1;

  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
  	perror("[Error] Setsockopt");
    exit(1);
  }

  // Lier socket au port et a l'adresse
  if (bind(sockfd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) == -1){
    cerr << "[Error] Bind" << std::endl;
    return 1;
  }

  // Met le socket serveur en attente de connexions
  if (listen(sockfd, BACKLOG) == -1){
    cerr << "[Error] Listen" << std::endl;
  }

  while (true){
    // Initialisation socket client
    sockaddr_in their_addr;
    socklen_t their_size = sizeof(their_addr);

    // Recupere file descriptor du socket client connecte
    int new_fd = accept(sockfd, (struct sockaddr*)&their_addr, &their_size);

    if (new_fd == -1){
      cerr << "[Error] Accept" << std::endl;
      continue;
    }
    else {
      cout << "Successfully connected" << endl;
    }

    // Fork et traite la demande du client
    if (!fork()){
      std::cout << "Connexion de " << inet_ntoa(their_addr.sin_addr) << std::endl;
      cout << "Connected to " << new_fd << endl;
      // Operation serveur
    }
    close(new_fd);
  }

  close(sockfd);
  return 0;
}
