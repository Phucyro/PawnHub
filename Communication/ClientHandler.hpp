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
      break;
    case '3' :
      menu->print_warning("Ce compte est déjà utilisé par quelqu'un");
      break;
  }
  menu->refresh_board();
}


void chatHandler(MenuHandler* menu, std::string sender, std::string target, std::string text, std::vector<std::string>* messages){
  std::string msg_to_print;

  if (target == "all"){
    msg_to_print = std::string("[") + sender + "->" + target + "] " + text;
  }
  else if (sender == "Guest"){
    msg_to_print =  target + " est deconnecté ou n'existe pas";
  }
  else {
    msg_to_print =  std::string("[") + sender + "->me] " + text;
  }

  if (messages->size() == 30){
    messages->erase(messages->begin());
    messages->push_back(msg_to_print);
  }
  else {
    messages->push_back(msg_to_print);
  }

  menu->init_chatw();

  for (unsigned int a = 0; a < messages->size(); ++a){
    menu->update_chatw(a, "", (*messages)[a]);
  }
  menu->refresh_board();

}


void playGameHandler(MenuHandler* menu, Socket* socket){
  menu->clear_windows();
  menu->end_windows();
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

void viewFriendsHandler(MenuHandler* menu, std::string friend_name, bool* stop, std::vector<std::string>* friends_list){
  if (friend_name != "Guest"){
    friends_list->push_back(friend_name);
  }
  else {
    menu->init_friendsw(*friends_list);
    *stop = true;
  }
}

void viewFriendRequestHandler(MenuHandler* menu, std::string request, bool* stop, std::vector<std::string>* request_list){
  if (request != "Guest"){
    request_list->push_back(request);
  }
  else {
    menu->init_friendsw(*request_list);
    *stop = true;
  }
}

void acceptRefuseRequestHandler(MenuHandler* menu, std::string option, std::string res){
  if (option == "0")
    menu->print_warning("Vous ne pouvez pas être amis avec vous même");
  else if (option == "1"){
    if (res == "0")
      menu->print_warning("Vous n'avez pas recu de demande de cet utilisateur");
    else
      menu->print_warning("Cet utilisateur a été ajouté à vos amis");
  }
  else {
    if (res == "0")
      menu->print_warning("Vous n'avez pas recu de demande cet utilisateur");
    else
      menu->print_warning("Cet utilisateur a été retiré de la liste");
  }
  menu->refresh_board();
}

void sendFriendRequestHandler(MenuHandler* menu, std::string res){
  switch (res[0]){
    case '0' :
      menu->print_warning("Utilisateur inexistant");
      break;
    case '1' :
      menu->print_warning("Utilisateur déjà dans la liste d'amis");
      break;
    case '2' :
      menu->print_warning("Demande d'ami déjà envoyé");
      break;
    case '3' :
      menu->print_warning("Vous êtes tout les deux devenus amis");
      break;
    case '4' :
      menu->print_warning("Demande d'ami envoyé");
  }
  menu->refresh_board();
}

void removeFriendHandler(MenuHandler* menu, std::string res){
  switch (res[0]){
    case '0' :
      menu->print_warning("Cet utilisateur ne fait pas partie de vos amis");
      break;
    case '1' :
      menu->print_warning("Utilisateur retiré de votre liste d'amis");
  }
  menu->refresh_board();
}

void viewSentRequestHandler(MenuHandler* menu, std::string request, bool* stop, std::vector<std::string>* request_list){
  if (request != "Guest"){
    request_list->push_back(request);
  }
  else {
    menu->init_friendsw(*request_list);
    *stop = true;
  }
}

void cancelRequestHandler(MenuHandler* menu, std::string res){
  if (res == "0")
    menu->print_warning("Aucune requete n'a été envoyé à ce joueur");
  else
    menu->print_warning("La demande d'ami a été annulée");
}


#endif
