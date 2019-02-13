#ifndef _TREATCONNECTION_H_
#define _TREATCONNECTION_H_

#include "LoginServer.hpp"
#include <thread>

void treatConnection(Socket* client_socket){
  // Demande a l'utilisatuer de s'identifier
  try {
    treatAuthentification(client_socket);

    /*
    TODO :
    Initialiser chat
    Boucle attendre demande client (jouer, checker statistique, classement, ...)
    Bouton quitter
    Bouton chercher une partie
    */

  }
  catch (std::string const& error){
    std::cout << error << std::endl;
    std::cout << "Fin du thread" << std::endl;
  }
}

#endif
