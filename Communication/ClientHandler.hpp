#ifndef _CLIENTHANDLER_H_
#define _CLIENTHANDLER_H_

#include "Socket.hpp"
#include <string>


void signUpHandler(char msg){ // Fonction bool
  switch (msg){
    case '0' :
      std::cout << "Compte existant" << std::endl;
      break;
    case '1' :
      std::cout << "Compte cree avec succes" << std::endl;
  }
}


void signInHandler(char msg){ // Fonction bool
  switch (msg){
    case '0' :
      std::cout << "Compte inexistant" << std::endl;
      break;
    case '1' :
      std::cout << "Identification reussie" << std::endl;
      break;
    case '2' :
      std::cout << "Mauvais mot de passe" << std::endl;
  }
}


void chatHandler(std::string sender, std::string text){
  if (sender == "all"){
    std::cout << "[All->Me] " << text << std::endl;
  }
  else if (sender != "0"){
    std::cout << "[?->Me] " << text << std::endl;
  }
  else {
    std::cout << "Cette personne n'est pas en ligne" << std::endl;
  }
}


#endif
