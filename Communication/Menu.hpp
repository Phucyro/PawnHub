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

void authentificationMenu(MenuHandler* menu, Socket* socket){
  std::string username, password, confirmation;
  bool connected = false;
  std::vector<std::string> temp_v;
  int format;

  while (!connected || format != 5){
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

    if (format == 5 && choice == 0)
      signIn(socket, username, password);
    else if (format == 5 && choice == 1)
      signUp(socket, username, password, confirmation);

    if (format == 5)
      receiveMessageHandler(menu, socket, &connected, &temp_v);
  }
}

////////////////////////////////////////////////////////////////////////////////

void gamemodeMenu(MenuHandler* menu, Socket* socket){
  menu->clear_windows();
  menu->init_choicesw();
  int choice = menu->get_choice({"Classic", "Dark", "Horde", "Alice", "Real-Time Classic", "Retour"});
  bool temp_b = true;
  std::vector<std::string> temp_v;

  switch (choice){
    case 0 :
      playGame(socket, "0");
      receiveMessageHandler(menu, socket, &temp_b, &temp_v);
      break;
     case 1 :
       playGame(socket, "1");
       receiveMessageHandler(menu, socket, &temp_b, &temp_v);
       break;
     case 2 :
      playGame(socket, "2");
      receiveMessageHandler(menu, socket, &temp_b, &temp_v);
      break;

    case 3 :
      playGame(socket, "3");
      receiveMessageHandler(menu, socket, &temp_b, &temp_v);
      break;
    case 4 :
      playGame(socket, "4");
      receiveMessageHandler(menu, socket, &temp_b, &temp_v);
      break;
    case 5 :
      break;
  }
}

////////////////////////////////////////////////////////////////////////////////

void leaveLadderMenu(MenuHandler* menu, Socket* socket, std::string mode){
  bool temp_b = true;
  std::vector<std::string> temp_v;
  menu->clear_windows();
  menu->init_statsw();
  menu->init_statst(mode);

  for (unsigned int a = 0; a < 10; ++a){
    receiveMessageHandler(menu, socket, &temp_b, &temp_v);
  }

  menu->refresh_board();
  menu->init_choicesw();
  menu->get_choice({"Retour"});
}

void ladderMenu(MenuHandler* menu, Socket* socket){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({"Classic", "Dark", "Horde", "Alice", "Retour"});

    switch (choice){
      case 0 :
        viewLadder(socket, "0");
        leaveLadderMenu(menu, socket, "Classic");
        break;
      case 1 :
        viewLadder(socket, "1");
        leaveLadderMenu(menu, socket, "Dark");
        break;
      case 2 :
        viewLadder(socket, "2");
        leaveLadderMenu(menu, socket, "Horde");
        break;
      case 3 :
        viewLadder(socket, "3");
        leaveLadderMenu(menu, socket, "Alice");
        break;
      case 4 :
        leave = true;
    }
  }
}


void myStatMenu(MenuHandler* menu, Socket* socket){
  bool temp_b = true;
  std::vector<std::string> temp_v;
  menu->clear_windows();

  menu->init_statsw();
  menu->init_statsp("User");

  checkMyStat(socket);

  for (unsigned int a = 0; a < 4; ++a){
    receiveMessageHandler(menu, socket, &temp_b, &temp_v);
  }

  menu->refresh_board();
  menu->init_choicesw();
  menu->get_choice({"Retour"});
  menu->refresh_board();
}


void statMenu(MenuHandler* menu, Socket* socket){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({"Mes statistiques", "Classement général", "Retour"});

    switch (choice){
      case 0 :
        myStatMenu(menu, socket);
        break;
      case 1 :
        ladderMenu(menu, socket);
        break;
      case 2 :
        leave = true;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////

void viewFriendsMenu(MenuHandler* menu, Socket* socket){
  bool stop_receive = false;
  std::vector<std::string> friends_list = {};
  menu->clear_windows();
  viewFriendsList(socket);

  while (!stop_receive){
    receiveMessageHandler(menu, socket, &stop_receive, &friends_list);
  }

  menu->refresh_board();
  menu->init_choicesw();
  menu->get_choice({"Retour"});
  menu->refresh_board();
}


void theirFriendRequestMenu(MenuHandler* menu, Socket* socket){
  bool stop_receive = false;
  std::vector<std::string> friends_request = {};
  menu->clear_windows();
  viewTheirfriendRequest(socket);

  while (!stop_receive){
    receiveMessageHandler(menu, socket, &stop_receive, &friends_request);
  }

  std::string command = "";
  menu->print_warning2("Quiter : /quit   Accepter : /accept [name]   Refuser : /refuse [name]");
  menu->refresh_board();


  while (command != "/quit"){
    menu->init_dataw();
    command = menu->get_infos("commande");
    menu->refresh_board();

    if (!checkInputFormat(command)) continue;

    std::vector<std::string> split = splitString(command, ' ');

    if (split.size() == 2){
      if (split[0] == "/accept"){
        acceptRefuseRequest(socket, split[1], "1");
      }
      else if (split[0] == "/refuse"){
        acceptRefuseRequest(socket, split[1], "2");
      }
      receiveMessageHandler(menu, socket, &stop_receive, &friends_request);
    }
  }
}


void sendFriendRequestMenu(MenuHandler* menu, Socket* socket){
  bool temp_b = false;
  std::vector<std::string> temp_v = {};
  menu->clear_windows();

  menu->print_warning2("Quitter : /quit   Envoyer : /send [name]");
  menu->refresh_board();

  std::string command = "";

  while (command != "/quit"){
    menu->init_dataw();
    command = menu->get_infos("commande");
    menu->refresh_board();

    if (!checkInputFormat(command)) continue;

    std::vector<std::string> split = splitString(command, ' ');

    if (split[0] == "/send" && split.size() == 2){
      sendFriendRequest(socket, split[1]);
      receiveMessageHandler(menu, socket, &temp_b, &temp_v);
    }
  }
}


void removeFriendMenu(MenuHandler* menu, Socket* socket){
  bool temp_b = false;
  std::vector<std::string> temp_v = {};
  menu->clear_windows();
  menu->print_warning2("Quitter : /quit   Supprimer : /remove [name]");
  menu->refresh_board();

  std::string command = "";

  while (command != "/quit"){
    menu->init_dataw();
    command = menu->get_infos("commande");
    menu->refresh_board();

    if (!checkInputFormat(command)) continue;

    std::vector<std::string> split = splitString(command, ' ');

    if (split[0] == "/remove" && split.size() == 2){
      removeFriend(socket, split[1]);
      receiveMessageHandler(menu, socket, &temp_b, &temp_v);
    }
  }
}

void cancelRequestMenu(MenuHandler* menu, Socket* socket){
  bool stop_receive = false;
  std::vector<std::string> sent_request = {};
  menu->clear_windows();
  viewSentRequest(socket);

  while (!stop_receive){
    receiveMessageHandler(menu, socket, &stop_receive, &sent_request);
  }

  std::string command = "";
  menu->print_warning2("Quiter : /quit   Annuler : /cancel [name]");
  menu->refresh_board();


  while (command != "/quit"){
    menu->init_dataw();
    command = menu->get_infos("commande");
    menu->refresh_board();

    if (!checkInputFormat(command)) continue;

    std::vector<std::string> split = splitString(command, ' ');

    if (split.size() == 2 && split[0] == "/cancel"){
      cancelRequest(socket, split[1]);
      receiveMessageHandler(menu, socket, &stop_receive, &sent_request);
    }
  }
}


void friendMenu(MenuHandler* menu, Socket* socket){
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
        viewFriendsMenu(menu, socket);
        break;
      case 1 :
        theirFriendRequestMenu(menu, socket);
        break;
      case 2 :
        sendFriendRequestMenu(menu, socket);
        break;
      case 3 :
        removeFriendMenu(menu, socket);
        break;
      case 4 :
        cancelRequestMenu(menu, socket);
        break;
      case 5 :
        leave = true;
    }
  }
}

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

void mainMenu(MenuHandler* menu, Socket* socket){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({"Jouer", "Ami", "Chat", "Statistique", "Quitter"});

    switch (choice){
      case 0 :
        gamemodeMenu(menu, socket);
        break;
      case 1 :
        friendMenu(menu, socket);
        break;
      case 2 :
        chatMenu(menu, socket);
        break;
      case 3 :
        statMenu(menu, socket);
        break;
      case 4 :
        leave = true;
    }
  }
}



#endif
