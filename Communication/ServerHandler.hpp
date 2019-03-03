#ifndef _SERVERHANDLER_H_
#define _SERVERHANDLER_H_

#include "Data.hpp"
#include "Socket.hpp"
#include "../Code/Player.hpp"
#include "Matchmaking.hpp"
#include <string>
#include <tuple>

typedef std::map<std::string, Player*> PlayersMap;
typedef std::vector<unsigned int> Stat;
typedef std::tuple<std::string, Stat> UserLadderData;


void inline disconnect(bool* leave){
  *leave = true;
}


void inline signUpHandler(Socket* socket, Data* data, std::string username, std::string pswd){
  if (data->containsAccount(username)){
    socket->printSend("1~0");
  }
  else {
    data->createUserAccount(username, pswd);
    socket->printSend("1~1");
  }
}


void inline signInHandler(Socket* socket, PlayersMap* players_map, Data* data, Player* player, std::string username, std::string pswd){
  if (!(data->containsAccount(username))){
    socket->printSend("2~0"); // Compte inexistant
  }
  else if (data->checkUserPassword(username, pswd)){
    socket->printSend("2~1"); // Identification reussie
    data->loadUserData(username);
    player->setName(username);
    player->setSocket(socket);
    (*players_map)[username] = player;
  }
  else {
    socket->printSend("2~2"); // Mauvais mot de passe
  }
}


void inline chatHandler(PlayersMap* players_map, std::string sender, std::string target, std::string text){
  if (target == "all"){ // Envoie le message a tous ceux connecte
    for (auto elem : *players_map){
      elem.second->getSocket()->printSend(std::string("3~") + sender + "~" + target + "~" + text);
    }
  }
  else {
    if (players_map->find(target) != players_map->end()){ // Utilisateur connecte
      (*players_map)[target]->getSocket()->printSend(std::string("3~") + sender + "~" + text);
    }
    else { // Envoie msg pour dire que la cible est deconnecte
      (*players_map)[sender]->getSocket()->printSend(std::string("3~server~") + target);
    }
  }
}


void inline playGameHandler(Matchmaking* matchmaking, Player* player, std::string game_mode){
  matchmaking->addPlayer(player, atoi(game_mode.c_str()));
}


void inline leaveQueueHandler(Matchmaking* matchmaking, Player* player){
  matchmaking->removePlayer(player);
  player->getSocket()->printSend("5");
}


void inline myStatHandler(Player* player, Data* data){
  std::vector<std::string> mode = {"Classic", "Dark", "Horde", "Alice"};

  for (unsigned int a = 0; a < 4; ++a){
    std::string stat = unsignedIntVectorToStr(data->getUserStat(player->getName(), mode[a]));
    player->getSocket()->printSend(std::string("7~") + std::to_string(a) + "~" + mode[a] + "~" + stat);
  }
}


void inline ladderHandler(Socket* socket, Data* data, std::string mode){
  std::string gamemode;

  switch (mode[0]){
    case '0' :
      gamemode = "Classic";
      break;
    case '1' :
      gamemode = "Dark";
      break;
    case '2' :
      gamemode = "Horde";
      break;
    case '3' :
      gamemode = "Alice";
  }

  std::vector<UserLadderData> ladder = data->getLadder(gamemode);

  unsigned int a = 0;

  while (a < ladder.size()){
    std::string username = std::get<0>(ladder[a]);
    std::string stat = unsignedIntVectorToStr(std::get<1>(ladder[a]));
    socket->sendMessage(std::string("8~") + std::to_string(a) + "~" + username + "~" + stat);
    ++a;
  }

  for (unsigned int b = a; b < 10; ++b){
    socket->sendMessage(std::string("8~") + std::to_string(b) + "~---~0 0 0");
  }
}


void inline viewFriendsHandler(Player* player, Data* data){
  std::vector<std::string> friends = data->getUserFriends(player->getName());

  for (unsigned int a = 0; a < friends.size(); ++a){
    player->getSocket()->sendMessage(std::string("9~") + friends[a]);
  }

  player->getSocket()->sendMessage("9~Guest");
}


void inline viewFriendRequestHandler(Player* player, Data* data){
  std::vector<std::string> requests = data->getUserFriendRequests(player->getName());

  for (unsigned int a = 0; a < requests.size(); ++a){
    player->getSocket()->sendMessage(std::string("10~") + requests[a]);
  }

  player->getSocket()->sendMessage("10~Guest");
}

void inline acceptRefuseRequestHandler(Player* player, Data* data, std::string name, std::string option){
  if (player->getName() == name){
    player->getSocket()->sendMessage("11~0~0");
  }

  if (option == "1"){
    int res = data->accceptFriendRequest(player->getName(), name);
    player->getSocket()->sendMessage(std::string("11~1~") + std::to_string(res));
  }
  else {
    int res = data->refuseFriendRequest(player->getName(), name);
    player->getSocket()->sendMessage(std::string("11~2~") + std::to_string(res));
  }
}

void inline sendFriendRequestHandler(Player* player, Data* data, std::string name){
  if (player->getName() == name){
    player->getSocket()->sendMessage("12~0");
  }
  else {
    int res = data->sendFriendRequest(player->getName(), name);
    player->getSocket()->sendMessage(std::string("12~") + std::to_string(res));
  }
}

void inline removeFriendHandler(Player* player, Data* data, std::string name){
  int res = data->removeFriend(player->getName(), name);
  player->getSocket()->sendMessage(std::string("13~") + std::to_string(res));
}

#endif
