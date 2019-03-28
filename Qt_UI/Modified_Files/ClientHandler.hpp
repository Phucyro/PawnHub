#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include "../../Communication/Socket.hpp"
//#include "../../Communication/ClientGameControl.hpp"
#include "../../Communication/Client.hpp"
#include "chat.h"


#include <string>
#include <stdlib.h>


void signUpHandler(Client* client, char msg){
  switch (msg){
    case '0' :
      client->writePipe("Le nom de compte a deja été pris");
      break;
    case '1' :
      client->writePipe("Compte créé avec succes");
      break;
  }
}


void signInHandler(Client* client, char msg){
  switch (msg){
    case '0' :
      client->writePipe("Nom de compte inexistant");
      break;
    case '1' :
      client->setIdentified(); // Ne sera pas affiche
      client->writePipe("Connexion réussie");
      break;
    case '2' :
      client->writePipe("Mauvais mot de passe");
      break;
    case '3' :
      client->writePipe("Ce compte est déjà utilisé par quelqu'un");
      break;
  }
}


void chatHandler(Client* client, std::string sender, std::string target, std::string msg,Chat *chat){
  client->updateConversation(target, sender, msg);

  if (client->isChatting() && client->isChattingWith(target)){
        chat->displayChat(client, target);
  }
}


void playGameHandler(Client* client){
//  menu->clear_windows();
//  menu->end_windows();
//  std::cout << "Vous avez rejoint une file d'attente" << std::endl;
//  ClientGameControl control(*(client->getSocket()));
  client->writePipe("EndGame");
}

void leaveQueueHandler(){
  //std::cout << "Vous avez quitte une file d'attente" << std::endl;
}

void myStatHandler(Client* client, std::string pos, std::string mode, std::string stat){
  client->writePipe(pos + " " + mode + " " + stat);
}

void ladderHandler(Client* client, std::string pos, std::string username, std::string stat){
  client->writePipe(pos + " " + username + " " + stat);
}

void viewFriendsHandler(Client* client, std::string friend_name){
  client->addFriend(friend_name);
}

void viewFriendRequestHandler(Client* client, std::string username){
  client->addRecvRequest(username);
}

void acceptRefuseRequestHandler(Client* client, std::string option, std::string res){
  if (option == "0") // Impossible normalement car gere lors du sendRequest
    client->writePipe("0Vous ne pouvez pas être amis avec vous même");
  else if (option == "1"){
    if (res == "0") // Est gere par le cote client actuellement
      client->writePipe("1Vous n'avez pas recu de demande de cet utilisateur");
    else
      client->writePipe("2Cet utilisateur a été ajouté à vos amis");
  }
  else {
    if (res == "0") // Est gere par le cote client actuellement
      client->writePipe("1Vous n'avez pas recu de demande cet utilisateur");
    else
      client->writePipe("3Cet utilisateur a été retiré de la liste");
  }
}

void sendFriendRequestHandler(Client* client, std::string res){
  switch (res[0]){
    case '0' :
      client->writePipe("0Utilisateur inexistant");
      break;
    case '1' : // Gere du cote client actuellement
      client->writePipe("1Utilisateur déjà dans la liste d'amis");
      break;
    case '2' : // Gere du cote client actuellement
      client->writePipe("2Demande d'ami déjà envoyé");
      break;
    case '3' :
      client->writePipe("3Vous êtes tout les deux devenus amis");
      break;
    case '4' :
      client->writePipe("4Demande d'ami envoyé");
      break;
  }
}

void removeFriendHandler(Client* client, std::string res){
  switch (res[0]){
    case '0' : // Gere actuellement du cote client
      client->writePipe("0Cet utilisateur ne fait pas partie de vos amis");
      break;
    case '1' :
      client->writePipe("1Utilisateur retiré de votre liste d'amis");
      break;
  }
}

void viewSentRequestHandler(Client* client, std::string username){
  client->addSentRequest(username);
}

void cancelRequestHandler(Client* client, std::string res){
  if (res == "0") // Gere actuellement du cote client
    client->writePipe("0Aucune requete n'a été envoyé à ce joueur");
  else
    client->writePipe("1La demande d'ami a été annulée");
}

void updateFriendsListHandler(Client* client, std::string friend_name, std::string option){
  if (option == "0"){ // Retire l'ami
    client->removeFriend(friend_name);
  }
  else if (option == "1"){ // Ajoute l'ami
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
