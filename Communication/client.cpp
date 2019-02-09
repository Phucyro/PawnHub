#include "config.hpp"
#include "Socket.hpp"


int main(){
  // Initialisation socket
  Socket socket;

  // Demande de connexion au serveur
  socket.connectToServer("127.0.0.1");

  // Operations avec le serveur
  bool connected = true;

  // Variable necessaire pour le deroulement de la partie
  bool play_first = atoi(socket.receiveMessage().c_str());
  bool valid_move = false;

  // Recois le plateau de jeu
  socket.receiveBoard();

  while (connected){
    // Recupere le tour
    std::string turn = atoi(socket.receiveMessage().c_str());

    // Verifie s'il peut jouer
    if (turn % 2 == play_first){
      // Set and start timer

      while (true){ // timer < limite && !valid move
        socket.sendMove();
        valid_move = socket.receiveMessage();
      }
    }

    socket.receiveBoard();


  }

  return 0;
}
