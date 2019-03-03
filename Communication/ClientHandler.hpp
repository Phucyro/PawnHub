#ifndef _CLIENTHANDLER_H_
#define _CLIENTHANDLER_H_

#include "Socket.hpp"
#include "ClientGameControl.hpp"
#include "../Display/MenuHandler/MenuHandler.hpp"
#include <string>
#include <stdlib.h>


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
      *connected = true; // Connexion réussie
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

void myStatHandler(MenuHandler* menu, std::string pos, std::string mode, std::string stat){
  std::vector<std::string> stat_v = splitString(stat, ' ');
  menu->update_stats(atoi(pos.c_str()), mode, atoi(stat_v[0].c_str()), atoi(stat_v[1].c_str()), atoi(stat_v[2].c_str()));
}

void ladderHandler(MenuHandler* menu, std::string pos, std::string username, std::string stat){
  std::vector<std::string> stat_v = splitString(stat, ' ');
  menu->update_stats(atoi(pos.c_str()), username, atoi(stat_v[0].c_str()), atoi(stat_v[1].c_str()), atoi(stat_v[2].c_str()));
}

#endif
