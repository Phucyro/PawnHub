#ifndef _CLIENTHANDLER_H_
#define _CLIENTHANDLER_H_

#include "Socket.hpp"
#include "ClientGameControl.hpp"
#include "../Display/MenuHandler/MenuHandler.hpp"
#include <string>


void signUpHandler(MenuHandler* menu, char msg){
  switch (msg){
    case '0' :
      menu->print_warning("Le nom de compte a deja été pris");
      break;
    case '1' :
      menu->print_warning("Compte créé avec succes");
  }
  menu->refresh_board();
}


void signInHandler(MenuHandler* menu, char msg, bool* connected){ // Fonction bool
  switch (msg){
    case '0' :
      menu->print_warning("Nom de compte inexistant");
      break;
    case '1' :
      menu->print_warning("Connexion réussie");
      *connected = true;
      break;
    case '2' :
      menu->print_warning("Mauvais mot de passe");
  }
  menu->refresh_board();
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
