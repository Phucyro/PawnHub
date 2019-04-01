#ifndef _CLIENTHANDLER_H_
#define _CLIENTHANDLER_H_

#include "Socket.hpp"
#include "ClientGameControl.hpp"
#include "../Display/MenuHandler/MenuHandler.hpp"
#include <string>
#include <stdlib.h>
#include "Client.hpp"
#include "ClientFunctions.hpp"

void quitHandler(bool* stop_receive){
  *stop_receive = true;
}


void signUpHandler(Client* client, char msg){
  switch (msg){
    case '0' :
      client->writePipe("Someone already has this account name");
      break;
    case '1' :
      client->writePipe("Successfully created account");
      break;
  }
}


void signInHandler(Client* client, char msg){
  switch (msg){
    case '0' :
      client->writePipe("Account name does not exist");
      break;
    case '1' :
      client->setIdentified(); // Ne sera pas affiche
      client->writePipe("Connected");
      break;
    case '2' :
      client->writePipe("Wrong password");
      break;
    case '3' :
      client->writePipe("Someone is already logged into this account");
      break;
  }
}


void chatHandler(MenuHandler* menu, Client* client, std::string sender, std::string target, std::string msg){
  client->updateConversation(target, sender, msg);

  if (client->isChatting() && client->isChattingWith(target)){
    displayChat(menu, client, target);
  }
}


void playGameHandler(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->end_windows();
  //std::cout << "Vous avez rejoint une file d'attente" << std::endl;
  client->writePipe("StartGame");
}

void leaveQueueHandler(){
  //std::cout << "Vous avez quitte une file d'attente" << std::endl;
}

void myStatHandler(Client* client, std::string pos, std::string mode, std::string stat, std::string elo){
  client->writePipe(pos + " " + mode + " " + stat + " " + elo);
}

void ladderHandler(Client* client, std::string pos, std::string username, std::string stat, std::string elo){
  client->writePipe(pos + " " + username + " " + stat + " " + elo);
}

void viewFriendsHandler(Client* client, std::string friend_name){
  client->addFriend(friend_name);
}

void viewFriendRequestHandler(Client* client, std::string username){
  client->addRecvRequest(username);
}

void acceptRefuseRequestHandler(Client* client, std::string option, std::string res){
  if (option == "0") // Impossible normalement car gere lors du sendRequest
    client->writePipe("0You can't be friends with yourself");
  else if (option == "1"){
    if (res == "0") // Est gere par le cote client actuellement
      client->writePipe("1You haven't got a friend request");
    else
      client->writePipe("2You are already befriended to that person");
  }
  else {
    if (res == "0") // Est gere par le cote client actuellement
      client->writePipe("1You haven't any request from that user");
    else
      client->writePipe("3This user has been removed from your list");
  }
}

void sendFriendRequestHandler(Client* client, std::string res){
  switch (res[0]){
    case '0' :
      client->writePipe("0User not found");
      break;
    case '1' : // Gere du cote client actuellement
      client->writePipe("1Already in your friend list");
      break;
    case '2' : // Gere du cote client actuellement
      client->writePipe("2You already sent a request to this person");
      break;
    case '3' :
      client->writePipe("3Both of you are friends now");
      break;
    case '4' :
      client->writePipe("4Request sent");
      break;
  }
}

void removeFriendHandler(Client* client, std::string res){
  switch (res[0]){
    case '0' : // Gere actuellement du cote client
      client->writePipe("0This person is not in your friend list");
      break;
    case '1' :
      client->writePipe("1Removed from your friend list");
      break;
  }
}

void viewSentRequestHandler(Client* client, std::string username){
  client->addSentRequest(username);
}

void cancelRequestHandler(Client* client, std::string res){
  if (res == "0") // Gere actuellement du cote client
    client->writePipe("0You didn't send a request to this player");
  else
    client->writePipe("1Outgoing request cancelled");
}

void updateFriendsListHandler(Client* client, std::string friend_name, std::string option){
  if (option == "0"){ // Retire l'ami
    client->removeFriend(friend_name);
  }
  else if (option == "1"){ // Ajoute l'ami
    client->removeSentRequest(friend_name);
    client->addFriend(friend_name);
  }
}

void updateRecvRequestHandler(Client* client, std::string friend_name, std::string option){
  if (option == "0"){ // Retire l'ami
    client->removeRecvRequest(friend_name);
  }
  else if (option == "1"){ // Ajoute l'ami
    client->addRecvRequest(friend_name);
  }
}

void updateSentRequestHandler(Client* client, std::string friend_name, std::string option){
  if (option == "0"){ // Retire l'ami
    client->removeSentRequest(friend_name);
  }
  else if (option == "1"){ // Ajoute l'ami
    client->addSentRequest(friend_name);
  }
}

#endif
