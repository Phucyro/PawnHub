#include "Matchmaking.hpp"
#include "ServerGameControl.hpp"
#include "../Code/Classic.hpp"
#include "../Code/Alice.hpp"
#include "../Code/Horde.hpp"
#include "../Code/Dark.hpp"
#include "../Code/RealTimeClassic.hpp"
#include "../Code/RealTimeHorde.hpp"
#include "../Code/RealTimeDark.hpp"
#include "cleanThread.hpp"

void delFinishedThread(std::list<ExecInfoThread*>&);

void startGame(Game* game, Player* player1, Player* player2, ExecInfoThread* infoThread){
  // Lance le jeu avec le bon mode de jeu
  std::cout << "Une partie se lance : " << player1->getName() << " vs " <<
  player2->getName() << std::endl;

  ServerGameControl control(player1, player2, game, infoThread);
  
  std::cout << "Une partie s'est termine entre : " << player1->getName() << " vs " <<
  player2->getName() << std::endl;
}


Matchmaking::Matchmaking(int number_of_queues) : _queues({}), _games() {
  for (int a = 0; a < number_of_queues; ++a){
    _queues[a] = std::vector<Player*>();
  }
}

Matchmaking::~Matchmaking(){
  std::list<ExecInfoThread*>::iterator it;
  for (it = _games.begin(); it != _games.end(); ++it){
    (*it)->getThread()->join();
    delete (*it)->getThread();
    delete *it;
  }
}

void Matchmaking::addPlayer(Player* player, int queue_number){
  _queues[queue_number].push_back(player); // 0 : Classic, 1 : Horde, 2 : Dark, 3 : Alice, 4 : RealTimeClassic
  player->setQueueNumber(queue_number);
  check(queue_number);
}

void Matchmaking::removePlayer(Player* player){
  std::vector<Player*> *queue = &(_queues[int(player->getQueueNumber())]);
  queue->erase(std::remove(queue->begin(), queue->end(), player), queue->end());
  player->setQueueNumber(-1);
}

void Matchmaking::check(int queue_number){
  if (_queues[queue_number].size() >= 2){
    Game* game;

    Player* player1 = _queues[queue_number][0];
    player1->setQueueNumber(-1);
    _queues[queue_number].erase(_queues[queue_number].begin());
    player1->getSocket()->sendMessage("4");

    Player* player2 = _queues[queue_number][0];
    player2->setQueueNumber(-1);
    _queues[queue_number].erase(_queues[queue_number].begin());
    player2->getSocket()->sendMessage("4");


  // Cherche le mode de jeu
    switch(queue_number){
      case 0 :
        game = new Classic(player1, player2);
        break;
      case 1 :
        game = new Dark(player1,player2);
        break;
      case 2 :
        game = new Horde(player1,player2);
        break;
      case 3 :
        game = new Alice(player1,player2);
        break;
      case 4 :
        game = new RealTimeClassic(player1,player2);
        break;
     case 5 :
        game = new RealTimeHorde(player1,player2);
        break;
     case 6 :
        game = new RealTimeDark(player1,player2);
        break;
    }
    ExecInfoThread *infoThread = new ExecInfoThread();
    std::thread *game_thread = new std::thread(startGame, game, player1, player2, infoThread);
    infoThread->setThread(game_thread);
    _games.push_back(infoThread);
  }
  delFinishedThread(_games);
}
