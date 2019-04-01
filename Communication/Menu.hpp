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
#include "Client.hpp"
#include "config.hpp"

void authentificationMenu(MenuHandler* menu, Client* client){
  std::string username, password, confirmation;
  int format = -1;

  while (!client->isIdentified()){
    switch (format){
      case 0 :
        menu->print_warning("Guest and all are forbidden names");
        break;
      case 1 :
        menu->print_warning("The passwords are not the same");
        break;
      case 2 :
        menu->print_warning("The size of name and password can't extend ove 10 characters");
        break;
      case 3 :
        menu->print_warning("Your name can't be composed with letters or numbers");
        break;
      case 4 :
        menu->print_warning("The caracters | and ~ are forbidden");
    }

    menu->refresh_board();
    menu->init_choicesw();
    int choice = menu->get_choice({"Sign In", "Sign Up"});
    menu->clear_windows();

    menu->init_dataw();
    username = menu->get_infos("Username :");
    menu->init_dataw();
    password = menu->get_infos("Password :");

    if (choice == 1){
      menu->init_dataw();
      confirmation = menu->get_infos("Confirmation of password :");
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

      std::string msg = client->readPipe();
      menu->print_warning(msg);
      menu->refresh_board();

      if (msg == "Compte créé avec succes"){ // Direct connection
        signIn(client->getSocket(), username, password);
        client->readPipe();
      }
    }
  }
  client->setName(username);
}

////////////////////////////////////////////////////////////////////////////////

void normalGameMenu(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->init_choicesw();
  bool play = true;
  int choice = menu->get_choice({"Classic", "Dark", "Horde", "Alice", "Return"});
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

  if (play) {
  	client->readPipe();
  	ClientGameControl control(*client);
  }
}

void realTimeMenu(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->init_choicesw();
  bool play = true;
  int choice = menu->get_choice({"Classic", "Dark", "Horde", "Alice", "Return"});
  menu->refresh_board();

  switch (choice){
    case 0 :
      playGame(client->getSocket(), "4");
      break;
    case 1 :
      playGame(client->getSocket(), "6");
      break;
    case 2 :
      playGame(client->getSocket(), "5");
      break;
    case 3 :
      playGame(client->getSocket(), "7");
      break;
    case 4 :
      play = false;
      break;
  }
  if (play) {
  	client->readPipe();
  	ClientGameControl control(*client);
  }
}



void gamemodeMenu(MenuHandler* menu, Client* client){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({"Normal", "Real-Time", "Return"});
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
    menu->update_stats(atoi(msg[0].c_str()), msg[1], msg[2], msg[3], msg[4], msg[5]);
  }

  menu->refresh_board();
  menu->init_choicesw();
  menu->get_choice({"Return"});
}


void normalLadderMenu(MenuHandler* menu, Client* client){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({"Classic", "Dark", "Horde", "Alice", "Return"});

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


void realTimeLadderMenu(MenuHandler* menu, Client* client){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({"Classic", "Dark", "Horde", "Alice", "Return"});

    switch (choice){
      case 0 :
        viewLadder(client->getSocket(), "4");
        leaveLadderMenu(menu, client, "Classic");
        break;
      case 1 :
        viewLadder(client->getSocket(), "5");
        leaveLadderMenu(menu, client, "Dark");
        break;
      case 2 :
        viewLadder(client->getSocket(), "6");
        leaveLadderMenu(menu, client, "Horde");
        break;
      case 3 :
        viewLadder(client->getSocket(), "7");
        leaveLadderMenu(menu, client, "Alice");
        break;
      case 4 :
        leave = true;
    }
  }
}


void ladderMenu(MenuHandler* menu, Client* client){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({"Normal", "Real-Time", "Return"});
    menu->refresh_board();

    switch (choice){
      case 0 :
        normalLadderMenu(menu, client);
        break;
      case 1 :
        realTimeLadderMenu(menu, client);
        break;
      case 2 :
        leave = true;
        break;
    }
  }
}


void myStatMenu(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->init_statsw();
  menu->init_statsp(client->getName());

  std::vector<std::string> msg;

  checkMyStat(client->getSocket());

  // 8 pour les 8 modes
  for (unsigned int a = 0; a < 8; ++a){
    msg = splitString(client->readPipe(), ' ');
    menu->update_stats(atoi(msg[0].c_str()), msg[1], msg[2], msg[3], msg[4], msg[5]);
  }

  menu->refresh_board();
  menu->init_choicesw();
  menu->get_choice({"Return"});
  menu->refresh_board();
}

void statMenu(MenuHandler* menu, Client* client){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({"My statistics", "General Ranking", "Return"});

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
  menu->print_warning3("Your friend request");
  menu->init_choicesw();
  menu->get_choice({"Return"});
  menu->refresh_board();
}

void theirFriendRequestMenu(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->print_warning2("Quit : /quit   Accept : /accept [name]   Refuse : /refuse [name]");
  menu->refresh_board();

  std::string command = "";

  while (command != "/quit"){
    menu->init_friendsw(client->getRecvRequest());
    menu->print_warning3("Your friend requests");
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
      menu->print_warning("You haven't got a friend request");
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
  menu->print_warning2("Quit : /quit   Send : /send [name]");
  menu->refresh_board();

  std::string command = "";

  while (command != "/quit"){
    menu->init_friendsw(client->getSentRequest());
    menu->print_warning3("Friend request sended");
    menu->refresh_board();
    menu->init_dataw();
    command = menu->get_infos("commande");
    menu->refresh_board();

    std::vector<std::string> split = splitString(command, ' ');

    // Verifie si format respecte
    if (!checkFriendInputFormat(menu, split)){
      continue;
    }
    else if (split[1] == "all" || split[1] == "Guest"){
      menu->print_warning("You cant sent a friend request to Guest or all");
      menu->refresh_board();
      continue;
    }
    else if (client->isFriendWith(split[1])){
      menu->print_warning("You are already befriended to that person");
      menu->refresh_board();
      continue;
    }
    else if (client->hasSentTo(split[1])){
      menu->print_warning("You already send a friend request to that person");
      menu->refresh_board();
      continue;
    }
    else if (split[1] == client->getName()){
      menu->print_warning("You cant send a friend request to youself");
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
  menu->print_warning2("Quit : /quit   Delete : /remove [name]");
  menu->refresh_board();

  std::string command = "";

  while (command != "/quit"){
    menu->init_friendsw(client->getFriends());
    menu->print_warning3("Your friend list");
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
      menu->print_warning("You are not befriended to that person");
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
    menu->print_warning3("Friend request sended");
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
      menu->print_warning("No request has been sent to that person");
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
      "Lookup friend list",
      "Accept ou refuse a friend request",
      "Send a friend request",
      "Delete a friend from friend list.",
      "Cancel a friend request",
      "Return"
    });

    switch (choice){
      case 0 :
        viewFriendsMenu(menu, client);
        break;
      case 1 :
        theirFriendRequestMenu(menu, client);
        break;
      case 2 :
        sendFriendRequestMenu(menu, client);
        break;
      case 3 :
        removeFriendMenu(menu, client);
        break;
      case 4 :
        cancelRequestMenu(menu, client);
        break;
      case 5 :
        leave = true;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////

void chatMenu(MenuHandler* menu, Client* client){
  menu->clear_windows();
  menu->print_warning2("Quit : /quit   Change conversation : /change [name]");
  menu->refresh_board();

  std::string target_name = client->getIsChattingWith();
  std::string command = "";

  client->setIsChatting(true);
  displayChat(menu, client, target_name);

  while (command != "/quit"){
    menu->init_dataw();
    command = menu->get_infos("message");
    menu->refresh_board();

    if (command.size() == 0) continue;

    if (!checkInputFormat(command)){
      menu->print_warning("Les caractères | et ~ sont interdits");
      continue;
    }

    std::vector<std::string> split = splitString(command, ' ');

    if (split[0] == "/change"){
      if (split.size() != 2){
        menu->print_warning("Command invalid");
        menu->refresh_board();
      }
      else if (split[1].length() > 10){
        menu->print_warning("The size of the names is limited to 10 caracters.");
        menu->refresh_board();
      }
      else if (split[1] == target_name){
        menu->print_warning("You are already in that channel.");
        menu->refresh_board();
      }
      else if (split[1] == client->getName()){
        menu->print_warning("You can't talk to youself.");
        menu->refresh_board();
      }
      else if (!client->isFriendWith(split[1]) && split[1] != "all"){
        menu->print_warning("You are not befriended to that person!");
        menu->refresh_board();
      }
      else {
        // Change de conversation
        target_name = split[1];
        client->setIsChattingWith(target_name);
        displayChat(menu, client, target_name);
        menu->refresh_board();
      }
    }
    else {
      if (command == "/quit") continue;
      // Envoi du message (command = msg)
      if (command.length() > MSG_LENGTH-24){ // Raccourci le msg si trop long
        command = command.substr(0,MSG_LENGTH-24);
      }
      chat(client->getSocket(), target_name, command);
    }
  }

  client->setIsChatting(false);
}

////////////////////////////////////////////////////////////////////////////////

void mainMenu(MenuHandler* menu, Client* client){
  bool leave = false;

  while (!leave){
    menu->clear_windows();
    menu->init_choicesw();
    int choice = menu->get_choice({"Play", "Friend List", "Chat", "Statistics", "Quit"});
    menu->refresh_board();

    switch (choice){
      case 0 :
        gamemodeMenu(menu, client);
        break;
      case 1 :
        friendMenu(menu, client);
        break;
      case 2 :
        chatMenu(menu, client);
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
