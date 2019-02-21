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

void playGameHandler(){
  std::cout << "Vous avez rejoins une file d'attente" << std::endl;
}

void leaveQueueHandler(){
  std::cout << "Vous avez quitte une file d'attente" << std::endl;
}

void askMoveHandler(){
  std::cout << "A votre tour de jouer donnez votre move" << std::endl;
}

void askPromotionHandler(){
  std::cout << "[Promotion] Choisissez un pion" << std::endl;
}

void boardHandler(std::string board){
  std::cout << "Board : " << board << std::endl;
}


#endif
