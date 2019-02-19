#include "Matchmaking.hpp"

Matchmaking::Matchmaking(unsigned int number_of_queues) : _queues({}) {
  for (unsigned int a = 0; a < number_of_queues; ++a){
    _queues[a] = std::vector<Player*>();
  }
}


void Matchmaking::addPlayer(Player* player, unsigned int queue_number){
  _queues[queue_number].push_back(player); // 0 : Classic, 1 : Horde, 2 : Dark, 3 : Alice
  player->setQueueNumber(queue_number);
  check(queue_number);
}

void Matchmaking::removePlayer(Player* player){
  std::vector<Player*> *queue = &(_queues[player->getQueueNumber()]);
  queue->erase(std::remove(queue->begin(), queue->end(), player), queue->end());
  player->setQueueNumber(-1);
}

void Matchmaking::check(unsigned int queue_number){
  if (_queues[queue_number].size() >= 2){
    Player* player1 = _queues[queue_number][0];
    player1->setQueueNumber(-1);
    _queues[queue_number].erase(_queues[queue_number].begin());

    Player* player2 = _queues[queue_number][0];
    player2->setQueueNumber(-1);
    _queues[queue_number].erase(_queues[queue_number].begin());

    createGame(player1, player2, queue_number);
  }
}

void Matchmaking::createGame(Player* player1, Player* player2, unsigned int game_mode){
  // Lance le jeu avec le bon mode de jeu
  std::cout << "Une partie se lance : " << player1->getName() << " vs " <<
  player2->getName() << " dans le mode de jeu numero " << game_mode << std::endl;
}
