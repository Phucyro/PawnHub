#ifndef _LOGINCLIENT_H_
#define _LOGINCLIENT_H_

#include <string>
#include "Socket.hpp"


void login(Socket* socket, std::string username, std::string pswd){
  /*
  Identification du joueur pour lui permettre de joueur
  Socket socket : socket du joueur qui veut se connecter
  string username : nom de compte du joueur
  string pswd : mot de passe du compte du joueur
  */

  // Envoie le nom et le mot de passe de l'utilisateur
  socket->sendMessage(username);
  socket->sendMessage(pswd);

  // Envoie du type de service 0 : Identification
  socket->sendMessage("0");

  // Recois la reponse du serveur
  char answer = socket->receiveMessage()[0];

  switch (answer){
    case '0' :
      std::cout << "Vous venez de vous connecter" << std::endl;
      break;
    case '1' :
      std::cout << "Compte utilisateur inexistant" << std::endl;
      break;
    case '2' :
      std::cout << "Mauvais mot de passe" << std::endl;
  }
}


void createAccount(Socket* socket, std::string username, std::string pswd1, std::string pswd2){
  /*
  Permet de joueur au joueur de s'inscrire et donc d'avoir un compte
  Socket socket : socket du joueur qui veut se connecter
  string username : nom de compte du joueur
  string pswd1 : mot de passe du compte du joueur
  string pswd2 : mot de passe du compte du joueur (confirmation)
  */

  if (pswd1 != pswd2){
    std::cout << "Les mots de passes ne correspondent pas" << std::endl;
  }
  else {
    // Envoie du type de service 1 : inscription
    socket->sendMessage("1");

    // Envoie le nom et le mot de passe de l'utilisateur
    socket->sendMessage(username);
    socket->sendMessage(pswd1);

    char answer = socket->receiveMessage()[0];

    switch (answer){
      case '0' :
        std::cout << "Compte cree avec succes" <<  std::endl;
        login(socket, username, pswd1);
        break;
      case '1' :
        std::cout << "Nom de compte existant" << std::endl;
        break;
    }
  }
}

void connectRegister(Socket* socket){
  bool connected = false;
  int service;
  std::string username;
  std::string password1;
  std::string password2;


  //while (!connected){
    std::cout << "[Option] 0 : Connexion |1 : Inscription" << std::endl;
    std::cin >> service;

    switch (service){
      case 0 : // Demande de connection
        std::cout << "Username :" << std::endl;
        std::cin >> username;
        std::cout << "Password :" << std::endl;
        std::cin >> password1;
        login(socket, username, password1);
        break;

      case 1 : // Demande de creation d'un compte
        std::cout << "Username :" << std::endl;
        std::cin >> username;
        std::cout << "Password :" << std::endl;
        std::cin >> password1;
        std::cout << "Password (confirmation):" << std::endl;
        std::cin >> password2;
        createAccount(socket, username, password1, password2);
        break;
    }
  //}
}















#endif
