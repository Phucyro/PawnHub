#ifndef _CLIENTFUNCTIONS_H_
#define _CLIENTFUNCTIONS_H_

#include <string>
#include "Socket.hpp"
#include "../Display/MenuHandler/MenuHandler.hpp"


void quit(MenuHandler* menu, Socket* socket){
  socket->sendMessage("0~oirf");
  menu->end_windows();
}


void signUp(Socket* socket, std::string username, std::string pswd1, std::string pswd2){
  if (pswd1 != pswd2){
    std::cout << "Les mots de passes ne correspondent pas" << std::endl;
  }
  else {
    // Envoie message pour s'inscrire (1)
    socket->sendMessage(std::string("1") + "~" + username + "~" + pswd1);
  }
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

#endif
