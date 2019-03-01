#ifndef _MENU_H_
#define _MENU_H_

#include "../Display/MenuHandler/MenuHandler.hpp"
#include "CheckFormat.hpp"
#include "Socket.hpp"
#include "ClientFunctions.hpp"
#include "ClientMessageHandler.hpp"

void authentificationMenu(MenuHandler* menu, Socket* socket){
  std::string username, password, confirmation;
  bool connected = false;
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
        menu->print_warning("La longueur du nom et mot de passe doivent être compris entre 1 et 10");
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
      receiveMessageHandler(menu, socket, &connected);
  }
}


void gamemodeMenu(MenuHandler* menu, Socket* socket){
  menu->clear_windows();
  menu->init_choicesw();
  int choice = menu->get_choice({"Classic", "Dark", "Horde", "Alice", "Retourner au menu principal"});
  bool temp = true;

  switch (choice){
    case 0 :
      playGame(socket, "0");
      receiveMessageHandler(menu, socket, &temp);
      break;
    // case 1 :
    //   playGame(socket, 1);
    //   break;
    // case 2 :
    //   playGame(socket, 2);
    //   break;
    // case 3 :
    //   playGame(socket, 3);
    //   break;
    case 4 :
      break;
  }
}



void mainMenu(MenuHandler* menu, Socket* socket){
  bool leave = false;

  while (!leave){
    menu->init_choicesw();
    int choice = menu->get_choice({"Jouer", "Ami", "Statistique", "Chat", "Quitter"});

    switch (choice){
      case 0 :
        gamemodeMenu(menu, socket);
        break;
      case 1 :
        break;
      case 2 :
        break;
      case 3 :
        break;
      case 4 :
        leave = true;
    }
  }
}



#endif
