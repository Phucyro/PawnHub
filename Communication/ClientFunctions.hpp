#ifndef _CLIENTFUNCTIONS_H_
#define _CLIENTFUNCTIONS_H_

#include <string>
#include "Socket.hpp"


void quit(Socket* socket, bool* quit){
  socket->sendMessage("0");
  *quit = true;
}


void signUp(Socket* socket, std::string username, std::string pswd1, std::string pswd2){
  if (pswd1 != pswd2){
    std::cout << "Les mots de passes ne correspondent pas" << std::endl;
  }
  else {
    // Envoie message pour s'inscrire (1)
    socket->sendMessage(std::string("1") + " " + username + " " + pswd1);
  }
}


void signIn(Socket* socket, std::string username, std::string pswd, std::string* client_username){
  socket->sendMessage(std::string("2") + " " + username + " " + pswd);
  *client_username = username;
}


void chat(Socket *socket, std::string sender, std::string target, std::string text){
  socket->sendMessage(std::string("3") + " " + sender + " " + target + " " + text);
}

void playGame(Socket* socket, std::string game_mode){
  socket->sendMessage(std::string("4") + " " + game_mode);
}

void leaveQueue(Socket* socket){
  socket->sendMessage("5");
}


#endif
