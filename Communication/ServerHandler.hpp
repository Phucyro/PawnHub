#ifndef _SERVERHANDLER_H_
#define _SERVERHANDLER_H_

#include "Data.hpp"
#include "Socket.hpp"

typedef std::map<std::string, Socket*> SocketsMap;


void disconnect(bool* leave){
  *leave = true;
}

void signUpHandler(Socket* socket, Data* data, std::string username, std::string pswd){
  if (data->containsAccount(username)){
    socket->sendMessage("1 0");
  }
  else {
    data->addAccount(username, pswd);
    data->write();
    socket->sendMessage("1 1");
  }
}

void signInHandler(Socket* socket, SocketsMap*sockets_map, Data* data, std::string username, std::string pswd){
  if (!(data->containsAccount(username))){
    socket->sendMessage("2 0"); // Compte inexistant
  }
  else if (data->checkPassword(username, pswd)){
    socket->sendMessage("2 1"); // Identification reussie
    (*sockets_map)[username] = socket;
  }
  else {
    socket->sendMessage("2 2"); // Mauvais mot de passe
  }
}

void chatHandler(SocketsMap* sockets_map, std::string sender, std::string target, std::string text){
  if (target == "all"){ // Envoie le message a tous ceux connecte
    for (auto elem : *sockets_map){
      elem.second->sendMessage(std::string("3 ") + sender + " " + target + " " + text);
    }
  }
  else {
    if (sockets_map->find(target) != sockets_map->end()){ // Utilisateur connecte
      (*sockets_map)[target]->sendMessage(std::string("3 ") + sender + " " + text);
    }
    else { // Envoie msg pour dire que la cible est deconnecte
      (*sockets_map)[sender]->sendMessage(std::string("3 server ") + target);
    }
  }
}


#endif
