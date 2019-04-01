#ifndef _SERVERHANDLER_H_
#define _SERVERHANDLER_H_

#include "Data.hpp"
#include "Socket.hpp"
#include "../Code/Player.hpp"
#include "Matchmaking.hpp"
#include <string>
#include <tuple>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <mutex>
#include <cstdlib>

typedef std::map<std::string, Player*> PlayersMap;
typedef std::vector<unsigned int> Stat;
typedef std::tuple<std::string, Stat, double> UserLadderData;


void inline disconnect(Socket* socket, bool* leave){
  socket->sendMessage("0~Quit");
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


void inline signInHandler(Socket* socket, PlayersMap* players_map, std::mutex* playerMapMutex, Data* data, Player* player, std::string username, std::string pswd){
  if (!(data->containsAccount(username))){
    socket->printSend("2~0"); // Compte inexistant
  }
  else if (data->isConnected(username)){
    socket->printSend("2~3"); // Joueur deja connecte
  }
  else if (data->checkUserPassword(username, pswd)){
    socket->printSend("2~1"); // Identification reussie
    data->lockMutex(username);
    data->loadUserData(username);
    data->unlockMutex(username);
    player->setName(username);
    player->setSocket(socket);
    playerMapMutex->lock();
    (*players_map)[username] = player;
    playerMapMutex->unlock();
  }
  else {
    socket->printSend("2~2"); // Mauvais mot de passe
  }
}


void inline chatHandler(PlayersMap* players_map, std::mutex* playerMapMutex, Player* player, std::string target, std::string text){
  if (target == "all"){ // Envoie le message a tous ceux connecte
    playerMapMutex->lock();
    for (auto elem : *players_map){
      elem.second->getSocket()->sendMessage(std::string("3~") + player->getName() + "~" + target + "~" + text);
    }
    playerMapMutex->unlock();
    return;
  }
  // Envoit le message au sender (confirmation)
  player->getSocket()->sendMessage(std::string("3~") + player->getName() + "~" + target + "~" + text);

  // Si target est connecte alors lui envoit le message de sender
  playerMapMutex->lock();
  if (players_map->find(target) != players_map->end()){
    (*players_map)[target]->getSocket()->sendMessage(std::string("3~") + player->getName() + "~" + player->getName() + "~" + text);
  }
  else { // Si target est deconnecte alors previens sender
    player->getSocket()->sendMessage(std::string("3~[Server]~") + target + "~" + target + " est deconnecte actuellement");
  }
  playerMapMutex->unlock();
}


void inline playGameHandler(Matchmaking* matchmaking, Player* player, std::string game_mode){
  matchmaking->addPlayer(player, atoi(game_mode.c_str()));
}


void inline leaveQueueHandler(Matchmaking* matchmaking, Player* player){
  matchmaking->removePlayer(player);
  player->getSocket()->printSend("5");
}


void inline myStatHandler(Player* player, Data* data){
  std::stringstream elo;
  std::vector<std::string> mode = {"Classic", "Dark", "Horde", "Alice",
    "RealTimeClassic", "RealTimeDark", "RealTimeHorde", "RealTimeAlice"};

  for (unsigned int a = 0; a < mode.size(); ++a){
    std::string stat = unsignedIntVectorToStr(data->getUserStat(player->getName(), mode[a]));
    elo << std::fixed << std::setprecision(2) << data->getEloRating(player->getName(), a);
    player->getSocket()->printSend(std::string("7~") + std::to_string(a) + "~" + mode[a] + "~" + stat + "~" + elo.str());
    elo.str("");
  }
}


void inline ladderHandler(Socket* socket, Data* data, std::string mode){
  std::vector<std::string> modes = {"Classic", "Dark", "Horde", "Alice",
    "RealTimeClassic", "RealTimeDark", "RealTimeHorde", "RealTimeAlice"};

  std::string gamemode = modes[std::atoi(mode.c_str())];

  std::vector<UserLadderData> ladder = data->getLadder(gamemode);
  std::reverse(ladder.begin(), ladder.end());

  std::stringstream elo;
  unsigned int a = 0;

  while (a < ladder.size()){
    std::string username = std::get<0>(ladder[a]);
    std::string stat = unsignedIntVectorToStr(std::get<1>(ladder[a]));
    elo << std::fixed << std::setprecision(2) << std::get<2>(ladder[a]);
    socket->sendMessage(std::string("8~") + std::to_string(a) + "~" + username + "~" + stat + "~" + elo.str());
    elo.str("");
    ++a;
  }

  for (unsigned int b = a; b < 10; ++b){
    socket->sendMessage(std::string("8~") + std::to_string(b) + "~---~- - -~-");
  }
}


void inline viewFriendsHandler(Player* player, Data* data){
  std::vector<std::string> friends = data->getUserFriends(player->getName());

  for (unsigned int a = 0; a < friends.size(); ++a){
    player->getSocket()->sendMessage(std::string("9~") + friends[a]);
  }
}


void inline viewFriendRequestHandler(Player* player, Data* data){
  std::vector<std::string> requests = data->getUserFriendRequests(player->getName());

  for (unsigned int a = 0; a < requests.size(); ++a){
    player->getSocket()->sendMessage(std::string("10~") + requests[a]);
  }
}

void inline acceptRefuseRequestHandler(Player* player, PlayersMap* players_map, std::mutex* playerMapMutex, Data* data, std::string name, std::string option){
  if (player->getName() == name){ // Gere du cote client actuellement
    player->getSocket()->sendMessage("11~0~0");
  }

  if (option == "1"){
    int res = data->accceptFriendRequest(player->getName(), name);
    player->getSocket()->sendMessage(std::string("11~1~") + std::to_string(res));

    playerMapMutex->lock();
    if (players_map->find(name) != players_map->end()){ // Si le joueur est connecte
      (*players_map)[name]->getSocket()->sendMessage(std::string("16~") + player->getName() + "~1"); // Ajoute ami
      (*players_map)[name]->getSocket()->sendMessage(std::string("18~") + player->getName() + "~0"); // Supprime requete envoyee
    }
    playerMapMutex->unlock();
  }
  else {
    int res = data->refuseFriendRequest(player->getName(), name);
    player->getSocket()->sendMessage(std::string("11~2~") + std::to_string(res));

    playerMapMutex->lock();
    if (players_map->find(name) != players_map->end()){ // Si le joueur est connecte
      (*players_map)[name]->getSocket()->sendMessage(std::string("18~") + player->getName() + "~0"); // Supprime requete envoyee
    }
    playerMapMutex->unlock();
  }
}

void inline sendFriendRequestHandler(Player* player, PlayersMap* players_map, std::mutex* playerMapMutex, Data* data, std::string name){
  if (player->getName() == name){ // Gere actuellement du cote client
    player->getSocket()->sendMessage("12~0");
  }
  else {
    int res = data->sendFriendRequest(player->getName(), name);
    player->getSocket()->sendMessage(std::string("12~") + std::to_string(res));

    playerMapMutex->lock();
    if (players_map->find(name) != players_map->end()){ // Si le joueur est connecte
      switch (res){
        case 3 :
          (*players_map)[name]->getSocket()->sendMessage(std::string("16~") + player->getName() + "~1"); // Ajoute ami
          (*players_map)[name]->getSocket()->sendMessage(std::string("18~") + player->getName() + "~0"); // Ajoute ami
          break;
        case 4 :
          (*players_map)[name]->getSocket()->sendMessage(std::string("17~") + player->getName() + "~1"); // Ajoute demande recue
          break;
      }
    }
    playerMapMutex->unlock();
  }
}

void inline removeFriendHandler(Player* player, PlayersMap* players_map, std::mutex* playerMapMutex, Data* data, std::string name){
  int res = data->removeFriend(player->getName(), name);
  player->getSocket()->sendMessage(std::string("13~") + std::to_string(res));

  playerMapMutex->lock();
  if (players_map->find(name) != players_map->end()){ // Si le joueur est connecte
    (*players_map)[name]->getSocket()->sendMessage(std::string("16~") + player->getName() + "~0"); // Supprime ami
  }
  playerMapMutex->unlock();
}

void inline viewSentRequestHandler(Player* player, Data* data){
  std::vector<std::string> sent_request = data->getUserSentRequests(player->getName());

  for (unsigned int a = 0; a < sent_request.size(); ++a){
    player->getSocket()->sendMessage(std::string("14~") + sent_request[a]);
  }
}

void inline cancelRequestHandler(Player* player, PlayersMap* players_map, std::mutex* playerMapMutex, Data* data, std::string name){
  int res = data->cancelSentRequest(player->getName(), name);
  player->getSocket()->sendMessage(std::string("15~" + std::to_string(res)));

  playerMapMutex->lock();
  if (players_map->find(name) != players_map->end()){ // Si le joueur est connecte
    (*players_map)[name]->getSocket()->sendMessage(std::string("17~") + player->getName() + "~0"); // Supprime requete envoyee
  }
  playerMapMutex->unlock();
}

#endif
