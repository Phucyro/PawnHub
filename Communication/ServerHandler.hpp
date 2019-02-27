#ifndef _SERVERHANDLER_H_
#define _SERVERHANDLER_H_

#include "Data.hpp"
#include "Socket.hpp"
#include "../Code/Player.hpp"
#include "Matchmaking.hpp"

typedef std::map<std::string, Player*> PlayersMap;


void inline disconnect(bool* leave){
  *leave = true;
}

void inline signUpHandler(Socket* socket, Data* data, std::string username, std::string pswd){
  if (data->containsAccount(username)){
    socket->sendMessage("1 0");
  }
  else {
    data->createUserAccount(username, pswd);
    socket->sendMessage("1 1");
  }
}

void inline signInHandler(Socket* socket, PlayersMap* players_map, Data* data, Player* player, std::string username, std::string pswd){
  if (!(data->containsAccount(username))){
    socket->sendMessage("2 0"); // Compte inexistant
  }
  else if (data->checkUserPassword(username, pswd)){
    socket->sendMessage("2 1"); // Identification reussie
    player->setName(username);
    player->setSocket(socket);
    (*players_map)[username] = player;
  }
  else {
    socket->sendMessage("2 2"); // Mauvais mot de passe
  }
}

void inline chatHandler(PlayersMap* players_map, std::string sender, std::string target, std::string text){
  if (target == "all"){ // Envoie le message a tous ceux connecte
    for (auto elem : *players_map){
      elem.second->getSocket()->sendMessage(std::string("3 ") + sender + " " + target + " " + text);
    }
  }
  else {
    if (players_map->find(target) != players_map->end()){ // Utilisateur connecte
      (*players_map)[target]->getSocket()->sendMessage(std::string("3 ") + sender + " " + text);
    }
    else { // Envoie msg pour dire que la cible est deconnecte
      (*players_map)[sender]->getSocket()->sendMessage(std::string("3 server ") + target);
    }
  }
}

void inline playGameHandler(Matchmaking* matchmaking, Player* player, std::string game_mode){
  matchmaking->addPlayer(player, static_cast<unsigned int>(atoi(game_mode.c_str())));
  player->getSocket()->sendMessage("4");
}

void inline leaveQueueHandler(Matchmaking* matchmaking, Player* player){
  matchmaking->removePlayer(player);
  player->getSocket()->sendMessage("5");
}


#endif
