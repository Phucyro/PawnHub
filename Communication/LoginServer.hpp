#ifndef _LOGINSERVER_H_
#define _LOGINSERVER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "SplitString.hpp"
#include "Socket.hpp"

std::map<std::string, std::string> readData(const std::string file_path){
  /*
  Lit le fichier qui se trouve a la position donnee par file_path et renvoie
  un dictionnaire contenant les informations des utilisateurs qui possedent
  deja un compte
  map <string nomUtilisateur, string motDePasse>
  */

  std::ifstream filestream(file_path.c_str());
  std::map<std::string, std::string> users_data;

  if (filestream){
    std::string text_line;

    // Lecture du fichier ligne par ligne et stock info dans dictionnaire
    while (getline(filestream, text_line)){
      std::vector<std::string> data = splitString(text_line, ' ');
      users_data[data[0]] = data[1];
    }
  }
  else {
    std::cerr << "[Error] Ouverture fichier en mode lecture" << std::endl;
  }

  return users_data;
}

void addData(const std::string file_path, std::string username, std::string pswd){
  std::ofstream filestream(file_path.c_str(), std::ios::app);

  if (filestream){
    filestream << username + " " << pswd << std::endl;
  }
  else {
    std::cerr << "[Error] Ecriture fichier" << std::endl;
  }
}


void treatConnection(Socket* socket){
  bool connected = false;

  while (!connected){
    std::map<std::string, std::string> users_data = readData("database.txt");
    // Reception du type de service
    char service = socket->receiveMessage()[0];
    std::string username = socket->receiveMessage();
    std::string password = socket->receiveMessage();

    std::cout << "Le serveur a recu la demande" << service << std::endl;
    std::cout << "Nom recu : " << username << std::endl;
    std::cout << "Mot de passe recu : " << password << std::endl;

    switch (service){
      case '0' : // L'utilisateur veut se connecter
        if (users_data.find("username") == users_data.end()){
          socket->sendMessage("1"); // Compte inexistant
          break;
        }
        if (users_data[username] == password){
          socket->sendMessage("0"); // Le joueur se connecte
          connected = true;
          break;
        }
        else {
          socket->sendMessage("2"); // Mauvais mot de passe
        }
      case '1' : // L'utilisateur veut s'inscrire
        if (users_data.find("username") == users_data.end()){
          // Si le nom de compte est disponible, cree le compte
          users_data[username] = password;
          socket->sendMessage("0");
        }
        else {
          // Le nom de compte existe deja
          socket->sendMessage("1");
        }
    }
  }
}

#endif