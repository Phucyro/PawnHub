#ifndef _CLIENTHANDLER_H_
#define _CLIENTHANDLER_H_

#include "Socket.hpp"
#include "ClientGameControl.hpp"
#include <string>


void signUpHandler(MenuHandler* menu, char msg, int pipe_fd[]){
  switch (msg){
    case '0' :
      std::cout << "Nom de compte indisponible" << std::endl;
      write(pipe_fd[1], "0", 10); // [0] Nom de compte indisponible
      break;
    case '1' :
      write(pipe_fd[1], "1", 10); // [1] Creation du compte succes
      std::cout << "Creation du compte succes" << std::endl;
  }
}


void signInHandler(MenuHandler* menu, char msg, int pipe_fd[]){ // Fonction bool
  switch (msg){
    case '0' :
      write(pipe_fd[1], "2", 10); // Compte inexistant
      break;
    case '1' :
      write(pipe_fd[1], "3", 10); // Identification reussie
      break;
    case '2' :
      write(pipe_fd[1], "4", 10); // Mauvais mot de passe
      break;
  }
}

void chatHandler(std::string sender, std::string target, std::string text){
  if (target == "all"){
    std::cout << "[" << sender << "->all] " << text << std::endl;
  }
  else if (sender == "server"){
    std::cout << target << " est deconnecte" << std::endl;
  }
  else {
    std::cout << "[" << sender << "->me] " << text << std::endl;
  }
}

void playGameHandler(Socket* socket){
  std::cout << "Vous avez rejoint une file d'attente" << std::endl;
  ClientGameControl control(*socket);
}

void leaveQueueHandler(){
  std::cout << "Vous avez quitte une file d'attente" << std::endl;
}


#endif
