#ifndef _MENU_H_
#define _MENU_H_

#include "../Display/MenuHandler/MenuHandler.hpp"
#include "CheckFormat.hpp"
#include "Socket.hpp"
#include "ClientFunctions.hpp"
#include "ClientMessageHandler.hpp"
#include <string>
#include <vector>
#include "SplitString.hpp"
#include <thread>
#include "Client.hpp"

void authentificationMenu(MenuHandler* menu, Client* client){
  std::string username, password, confirmation;
  int format;

  while (!client->isIdentified()){
    switch (format){
      case 0 :
        menu->print_warning("Guest et all sont des noms interdits");
        break;
      case 1 :
        menu->print_warning("Les mots de passe ne correspondent pas");
        break;
      case 2 :
        menu->print_warning("La longueur du nom et mot de passe doivent être comprise entre 1 et 10");
        break;
      case 3 :
        menu->print_warning("Votre nom ne peut être composé que de chiffres et lettres");
        break;
      case 4 :
        menu->print_warning("Les caractères | et ~ sont interdits");
    }

    menu->refresh_board();
    menu->init_choicesw();
    int choice = menu->get_choice({"Connexion", "Inscription"});
    menu->clear_windows();

    menu->init_dataw();
    username = menu->get_infos("Nom d'utilisateur :");
    menu->init_dataw();
    password = menu->get_infos("Mot de passe :");

    if (choice == 1){
      menu->init_dataw();
      confirmation = menu->get_infos("Confirmation mot de passe :");
    }

    if (choice == 0)
      format = checkFormat(username, password, password);
    else
      format = checkFormat(username, password, confirmation);


    if (format == 5){
      if (choice == 0)
        signIn(client->getSocket(), username, password);
      else
        signUp(client->getSocket(), username, password);

      menu->print_warning(client->readPipe());
      menu->refresh_board();
    }
  }
  client->setName(username);
}

////////////////////////////////////////////////////////////////////////////////

void normalGameMenu(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->init_choicesw();
  bool play = true;
  int choice = menu->get_choice({"Classic", "Dark", "Horde", "Alice", "Retour"});
  menu->refresh_board();

  switch (choice){
    case 0 :
      playGame(client->getSocket(), "0");
      break;
    case 1 :
      playGame(client->getSocket(), "1");
      break;
    case 2 :
      playGame(client->getSocket(), "2");
      break;
    case 3 :
      playGame(client->getSocket(), "3");
      break;
    case 4 :
      play = false;
      break;
  }

  if (play) client->readPipe();
}

void realTimeMenu(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->init_choicesw();
  bool play = true;
  int choice = menu->get_choice({"Real-Time Classic", "Retour"});
  menu->refresh_board();

  switch (choice){
    case 0 :
      playGame(client->getSocket(), "4");
      break;
    case 1 :
      play = false;
      break;
  }
  if (play) client->readPipe();
}



void gamemodeMenu(MenuHandler* menu, Client* client){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({"Normal", "Real-Time", "Retour"});
    menu->refresh_board();

    switch (choice){
      case 0 :
        normalGameMenu(menu, client);
        break;
      case 1 :
        realTimeMenu(menu, client);
        break;
      case 2 :
        leave = true;
        break;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////

void leaveLadderMenu(MenuHandler* menu, Client* client, std::string mode){
  menu->clear_windows();
  menu->init_statsw();
  menu->init_statst(mode);

  std::vector<std::string> msg;

  for (unsigned int a = 0; a < 10; ++a){
    msg = splitString(client->readPipe(), ' ');
    menu->update_stats(atoi(msg[0].c_str()), msg[1], atoi(msg[2].c_str()), atoi(msg[3].c_str()), atoi(msg[4].c_str()));
  }

  menu->refresh_board();
  menu->init_choicesw();
  menu->get_choice({"Retour"});
}

void ladderMenu(MenuHandler* menu, Client* client){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({"Classic", "Dark", "Horde", "Alice", "Retour"});

    switch (choice){
      case 0 :
        viewLadder(client->getSocket(), "0");
        leaveLadderMenu(menu, client, "Classic");
        break;
      case 1 :
        viewLadder(client->getSocket(), "1");
        leaveLadderMenu(menu, client, "Dark");
        break;
      case 2 :
        viewLadder(client->getSocket(), "2");
        leaveLadderMenu(menu, client, "Horde");
        break;
      case 3 :
        viewLadder(client->getSocket(), "3");
        leaveLadderMenu(menu, client, "Alice");
        break;
      case 4 :
        leave = true;
    }
  }
}

void myStatMenu(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->init_statsw();
  menu->init_statsp(client->getName());

  std::vector<std::string> msg;

  checkMyStat(client->getSocket());

  for (unsigned int a = 0; a < 4; ++a){
    msg = splitString(client->readPipe(), ' ');
    menu->update_stats(atoi(msg[0].c_str()), msg[1], atoi(msg[2].c_str()), atoi(msg[3].c_str()), atoi(msg[4].c_str()));
  }

  menu->refresh_board();
  menu->init_choicesw();
  menu->get_choice({"Retour"});
  menu->refresh_board();
}

void statMenu(MenuHandler* menu, Client* client){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({"Mes statistiques", "Classement général", "Retour"});

    switch (choice){
      case 0 :
        myStatMenu(menu, client);
        break;
      case 1 :
        ladderMenu(menu, client);
        break;
      case 2 :
        leave = true;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////

void viewFriendsMenu(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->init_friendsw(client->getFriends());
  menu->init_choicesw();
  menu->get_choice({"Retour"});
  menu->refresh_board();
}

void theirFriendRequestMenu(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->print_warning2("Quiter : /quit   Accepter : /accept [name]   Refuser : /refuse [name]");
  menu->refresh_board();

  std::string command = "";

  while (command != "/quit"){
    menu->init_friendsw(client->getRecvRequest());
    menu->refresh_board();
    menu->init_dataw();
    command = menu->get_infos("commande");
    menu->refresh_board();

    // [0] Commande [1] Nom
    std::vector<std::string> split = splitString(command, ' ');

    // Verifie si format respecte
    if (!checkFriendInputFormat(menu, split)){
      continue;
    }
    else if (!client->hasRequestFrom(split[1])){
      menu->print_warning("Vous n'avez pas recu de demande de cette personne");
      menu->refresh_board();
      continue;
    }

    if (split[0] == "/accept"){
      acceptRefuseRequest(client->getSocket(), split[1], "1");
    }
    else if (split[0] == "/refuse"){
      acceptRefuseRequest(client->getSocket(), split[1], "2");
    }

    if (split[0] == "/accept" || split[0] == "/refuse"){
      // Recois les resultats de la requete
      std::string res = client->readPipe();
      char header = res[0];

      switch (header){
        case '2':
          client->addFriend(split[1]);
          client->removeRecvRequest(split[1]);
          menu->print_warning(res.substr(1));
          break;
        case '3':
          client->removeRecvRequest(split[1]);
          menu->print_warning(res.substr(1));
          break;

        menu->refresh_board();
      }
    }
  }
}

void sendFriendRequestMenu(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->print_warning2("Quitter : /quit   Envoyer : /send [name]");
  menu->refresh_board();

  std::string command = "";

  while (command != "/quit"){
    menu->init_friendsw(client->getFriends());
    menu->refresh_board();
    menu->init_dataw();
    command = menu->get_infos("commande");
    menu->refresh_board();

    std::vector<std::string> split = splitString(command, ' ');

    // Verifie si format respecte
    if (!checkFriendInputFormat(menu, split)){
      continue;
    }
    else if (client->isFriendWith(split[1])){
      menu->print_warning("Vous êtes déjà ami avec cette personne");
      menu->refresh_board();
      continue;
    }
    else if (client->hasSentTo(split[1])){
      menu->print_warning("Vous avez déjà envoyé une demande à cette personne");
      menu->refresh_board();
      continue;
    }
    else if (split[1] == client->getName()){
      menu->print_warning("Vous ne pouvez pas envoyer une demande à vous même");
      menu->refresh_board();
      continue;
    }

    if (split[0] == "/send"){
      sendFriendRequest(client->getSocket(), split[1]);

      // Recois les resultats de la requete
      std::string res = client->readPipe();
      char header = res[0];

      switch (header){
        case '0':
          menu->print_warning(res.substr(1));
          break;
        case '3':
          client->addFriend(split[1]);
          menu->print_warning(res.substr(1));
          break;
        case '4':
          client->addSentRequest(split[1]);
          menu->print_warning(res.substr(1));
          break;

        menu->refresh_board();
      }
    }
  }
}

void removeFriendMenu(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->print_warning2("Quitter : /quit   Supprimer : /remove [name]");
  menu->refresh_board();

  std::string command = "";

  while (command != "/quit"){
    menu->init_friendsw(client->getFriends());
    menu->refresh_board();
    menu->init_dataw();
    command = menu->get_infos("commande");
    menu->refresh_board();

    std::vector<std::string> split = splitString(command, ' ');

    // Verifie si format respecte
    if (!checkFriendInputFormat(menu, split)){
      continue;
    }
    else if (!client->isFriendWith(split[1])){
      menu->print_warning("Vous n'êtes pas ami avec cette personne");
      menu->refresh_board();
      continue;
    }

    if (split[0] == "/remove"){
      removeFriend(client->getSocket(), split[1]);

      // Recois les resultats de la requete
      std::string res = client->readPipe();
      char header = res[0];

      switch (header){
        case '1':
          client->removeFriend(split[1]);
          menu->print_warning(res.substr(1));
          break;

        menu->refresh_board();
      }
    }
  }
}

void cancelRequestMenu(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->print_warning2("Quitter : /quit   Annuler : /cancel [name]");
  menu->refresh_board();

  std::string command = "";

  while (command != "/quit"){
    menu->init_friendsw(client->getSentRequest());
    menu->refresh_board();
    menu->init_dataw();
    command = menu->get_infos("commande");
    menu->refresh_board();

    std::vector<std::string> split = splitString(command, ' ');

    // Verifie si format respecte
    if (!checkFriendInputFormat(menu, split)){
      continue;
    }
    else if (!client->hasSentTo(split[1])){
      menu->print_warning("Aucune demande n'a été envoyée à cette personne");
      menu->refresh_board();
      continue;
    }

    if (split[0] == "/cancel"){
      cancelRequest(client->getSocket(), split[1]);

      // Recois les resultats de la requete
      std::string res = client->readPipe();
      char header = res[0];

      switch (header){
        case '1':
          client->removeSentRequest(split[1]);
          menu->print_warning(res.substr(1));
          break;

        menu->refresh_board();
      }
    }
  }
}

void friendMenu(MenuHandler* menu, Client* client){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({
      "Consulter sa liste d'amis",
      "Accepter ou refuser une demande d'ami",
      "Envoyer une demande d'ami",
      "Retirer un ami de sa liste d'amis",
      "Annuler une demande d'ami",
      "Retour"
    });

    switch (choice){
      case 0 :
        viewFriendsMenu(menu, client);
        break;
      case 1 : // Y
        theirFriendRequestMenu(menu, client);
        break;
      case 2 : // Y
        sendFriendRequestMenu(menu, client);
        break;
      case 3 : // Y
        removeFriendMenu(menu, client);
        break;
      case 4 : // Y
        cancelRequestMenu(menu, client);
        break;
      case 5 :
        leave = true;
    }
  }
}
/*
////////////////////////////////////////////////////////////////////////////////

void chatThread(MenuHandler* menu,Socket* socket, bool* stop, std::vector<std::string>* messages){
  while (!(*stop)){
    receiveMessageHandler(menu, socket, stop, messages);
  }
}


void chatMenu(MenuHandler* menu, Socket* socket){
  bool stop = false;
  std::vector<std::string> messages = {};
  menu->clear_windows();
  menu->print_warning2("Quitter : /quit   Chat : /msg [destinaire] [message]");
  menu->refresh_board();

  std::thread thread(chatThread, menu, socket, &stop, &messages);
  thread.detach();

  std::string command = "";

  while (command != "/quit"){
    menu->init_dataw();
    command = menu->get_infos("commande");
    menu->refresh_board();

    if (!checkInputFormat(command)) continue;

    std::vector<std::string> split = splitString(command, ' ');

    if (split[0] == "/msg" && split.size() >= 3){
      chat(socket, split[1], command.substr(6+split[1].size()));
    }
  }

  stop = true;
  socket->sendMessage("20~StopChat");
}

////////////////////////////////////////////////////////////////////////////////
*/
void mainMenu(MenuHandler* menu, Client* client){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({"Jouer", "Ami", "Chat", "Statistique", "Quitter"});
    menu->refresh_board();

    switch (choice){
      case 0 :
        gamemodeMenu(menu, client);
        break;
      case 1 :
        friendMenu(menu, client);
        break;
      case 2 :
        //chatMenu(menu, socket);
        break;
      case 3 :
        statMenu(menu, client);
        break;
      case 4 :
        leave = true;
        break;
    }
  }
}



#endif
