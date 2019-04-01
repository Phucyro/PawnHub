#ifndef _CLIENTFUNCTIONS_H_
#define _CLIENTFUNCTIONS_H_

#include <string>
#include "Socket.hpp"
#include "../Display/MenuHandler/MenuHandler.hpp"
#include "Client.hpp"

typedef std::vector<std::tuple<std::string, std::string>> Conversation;


void signUp(Socket* socket, std::string username, std::string pswd){
  socket->sendMessage(std::string("1") + "~" + username + "~" + pswd);
}

void signIn(Socket* socket, std::string username, std::string pswd){
  socket->sendMessage(std::string("2") + "~" + username + "~" + pswd);
}

void chat(Socket *socket, std::string target, std::string text){
  socket->sendMessage(std::string("3") + "~" + target + "~" + text);
}

void playGame(Socket* socket, std::string game_mode){
  socket->sendMessage(std::string("4") + "~" + game_mode);
}

void leaveQueue(Socket* socket){
  socket->sendMessage("5~leaveQueue");
}

void checkMyStat(Socket* socket){
  socket->sendMessage("7~myStat");
}

void viewLadder(Socket* socket, std::string mode){
  socket->sendMessage(std::string("8~") + mode);
}

void viewFriendsList(Socket* socket){
  socket->sendMessage("9~viewFriends");
}

void viewTheirfriendRequest(Socket* socket){
  socket->sendMessage("10~viewRequest");
}

void acceptRefuseRequest(Socket* socket, std::string name, std::string option){
  socket->sendMessage(std::string("11~") + name + "~" + option);
}

void sendFriendRequest(Socket* socket, std::string name){
  socket->sendMessage(std::string("12~") + name);
}

void removeFriend(Socket* socket, std::string name){
  socket->sendMessage(std::string("13~") + name);
}

void viewSentRequest(Socket* socket){
  socket->sendMessage("14~viewSentRequest");
}

void cancelRequest(Socket* socket, std::string name){
  socket->sendMessage(std::string("15~") + name);
}

void initClientData(Client* client){
  client->setReceivedInfo(true);
  viewFriendsList(client->getSocket()); // Charge liste d'amis
  viewTheirfriendRequest(client->getSocket()); // Charge liste demandes recues
  viewSentRequest(client->getSocket()); // Charge liste demandes envoyees
}

void quit(MenuHandler* menu, Client* client){
  client->getSocket()->sendMessage("0~Quit");
  menu->end_windows();
}

void displayChat(MenuHandler* menu, Client* client, std::string target){
  Conversation conv = client->getConversation(target);

  menu->print_top(std::string("Channel : ") + target);

  // Rempli le chat avec la conversation
  for (unsigned int a = 0; a < conv.size(); ++a)
  {
    menu->update_chatw(a, std::get<0>(conv[a]), std::get<1>(conv[a]));
  }

  // Comble avec des lignes vides
  for (unsigned int a = 0; a < 30-conv.size(); ++a)
  {
    menu->update_chatw(a,"","");
  }

  menu->refresh_board();
}

#endif
