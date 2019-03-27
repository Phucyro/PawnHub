#ifndef CLIENTFUNCTIONS_H
#define CLIENTFUNCTIONS_H

#include <string>
#include "../../Communication/Socket.hpp"
#include "../../Communication/Client.hpp"
#include "chat.h"

typedef std::vector<std::tuple<std::string, std::string>> Conversation;


inline void signUp(Socket* socket, std::string username, std::string pswd){
  socket->sendMessage(std::string("1") + "~" + username + "~" + pswd);
}

inline void signIn(Socket* socket, std::string username, std::string pswd){
  socket->sendMessage(std::string("2") + "~" + username + "~" + pswd);
}

inline void chat(Socket *socket, std::string target, std::string text){
  socket->sendMessage(std::string("3") + "~" + target + "~" + text);
}

inline void playGame(Socket* socket, std::string game_mode){
  socket->sendMessage(std::string("4") + "~" + game_mode);
}

inline void leaveQueue(Socket* socket){
  socket->sendMessage("5~leaveQueue");
}

inline void checkMyStat(Socket* socket){
  socket->sendMessage("7~myStat");
}

inline void viewLadder(Socket* socket, std::string mode){
  socket->sendMessage(std::string("8~") + mode);
}

inline void viewFriendsList(Socket* socket){
  socket->sendMessage("9~viewFriends");
}

inline void viewTheirfriendRequest(Socket* socket){
  socket->sendMessage("10~viewRequest");
}

inline void acceptRefuseRequest(Socket* socket, std::string name, std::string option){
  socket->sendMessage(std::string("11~") + name + "~" + option);
}

inline void sendFriendRequest(Socket* socket, std::string name){
  socket->sendMessage(std::string("12~") + name);
}

inline void removeFriend(Socket* socket, std::string name){
  socket->sendMessage(std::string("13~") + name);
}

inline void viewSentRequest(Socket* socket){
  socket->sendMessage("14~viewSentRequest");
}

inline void cancelRequest(Socket* socket, std::string name){
  socket->sendMessage(std::string("15~") + name);
}

inline void initClientData(Client* client){
  viewFriendsList(client->getSocket()); // Charge liste d'amis
  viewTheirfriendRequest(client->getSocket()); // Charge liste demandes recues
  viewSentRequest(client->getSocket()); // Charge liste demandes envoyees
}

inline void quit(Client* client){
  client->getSocket()->sendMessage("0~Quit");
//  menu->end_windows();
}

inline void displayChat(Client* client, std::string target,Chat *chat){
  Conversation conv = client->getConversation(target);
  chat->displayChat(client,client->getIsChattingWith());
}
#endif
