#include "Matchmaking.hpp"
#include "Data.hpp"
#include "ServerGameControl.hpp"
#include "../Code/Classic.hpp"
#include "../Code/Alice.hpp"
#include "../Code/Horde.hpp"
#include "../Code/Dark.hpp"
#include "../Code/RealTimeClassic.hpp"
#include "../Code/RealTimeHorde.hpp"
#include "../Code/RealTimeDark.hpp"
#include "../Code/RealTimeAlice.hpp"
#include "cleanThread.hpp"
#include <cmath>
#include <queue>

// extern Data data;

void delFinishedThread(std::list<ExecInfoThread*>&);

void matchScheduling(const bool& end, Matchmaking* mm){
  int gamemode = 0;
  while (!end){
    _mutex.lock();
    mm->check(gamemode);
    _mutex.unlock();
    usleep(TIME_BETWEEN_MATCH/8);
    if (gamemode >= 7) gamemode = 0;
    else gamemode++;
  }
}

void startGame(Game* game, Player* player1, Player* player2, ExecInfoThread* infoThread){
  // Lance le jeu avec le bon mode de jeu
  std::cout << "Une partie se lance : " << player1->getName() << " vs " <<
  player2->getName() << std::endl;

  ServerGameControl control(player1, player2, game, infoThread);

  std::cout << "Une partie s'est termine entre : " << player1->getName() << " vs " <<
  player2->getName() << std::endl;
}


Matchmaking::Matchmaking(int gamemodes) : _queues({}), _games(), _mutex(), _end(false), _doMatch(matchScheduling, _end, this) {
  for (int a = 0; a < gamemodes; ++a){
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
  _end = true;
  _doMatch.join();
}

void Matchmaking::addPlayer(Player* player, int gamemode){
  _mutex.lock();
  _queues[gamemode].push_back(player); // 0 : Classic, 1 : Horde, 2 : Dark, 3 : Alice, 4 : RealTimeClassic
  _mutex.unlock();
  player->setQueueNumber(gamemode);
}

void Matchmaking::removePlayer(Player* player){
  std::vector<Player*> *queue = &(_queues[int(player->getQueueNumber())]);
  _mutex.lock();
  queue->erase(std::remove(queue->begin(), queue->end(), player), queue->end());
  _mutex.unlock();
  player->setQueueNumber(-1);
}
/*
void Matchmaking::check(int gamemode){
  bool empty = false;
  Player* player1,player2;
  int delta = 0;
  _mutex.lock();
  if (_queues[gamemode].size() < 2) return;

  while(!found){
    if (_queues[gamemode].size() < 2) return;
    delta+=10;


    for (unsigned int i = 0; j < _queues[gamemode].size(); ++i) {
      Player* player1temp = _queues[gamemode][i];
      for (unsigned int j = i+1; j < _queues[gamemode].size(); ++j){
        Player* player2temp = _queues[gamemode][j];
        double eloDiff = abs(data->getEloRating(player1->getName(), gamemode) - data->getEloRating(player2->getName(), gamemode));
        if (eloDiff < delta){
          player1 = player1temp;
          player2 = player2temp;
          enter(gamemode,player1,player2);
          break;
        }
      }
    }
    if(_queues[gamemode].size()==0){
      empty == true;
    }
  }
  _mutex.unlock();
}
*/

void Matchmaking::check(int gamemode){
  Player *player1, *player2;
  std::queue<Player*> currentRankPlayers;
  int currentRank = 0;
  int i;

  _mutex.lock();
  int nbrPlayer = _queues[gamemode].size();
  if(nbrPlayer % 2) nbrPlayer--;// to avoid looping if odd numbers of player

  while(nbrPlayer){
    i=0;
    while(i < nbrPlayer){
      player1 = _queues[gamemode][i];
      if (data.getRank(player1->getName(), gamemode) == currentRank){
        currentRankPlayers.push(player1);
        _queues[gamemode].erase(std::remove(_queues[gamemode].begin(), _queues[gamemode].end(), player1), _queues[gamemode].end());
        nbrPlayer--;
      }
      else i++;
    }
    while(currentRankPlayers.size() > 1){
      player1 = currentRankPlayers.front();
      currentRankPlayers.pop();
      player2 = currentRankPlayers.front();
      currentRankPlayers.pop();
      enter(gamemode,player1,player2);
    }
    currentRank++;
  }
  _mutex.unlock();
}



void Matchmaking::enter(int gamemode,Player* player1, Player* player2){
  Game* game;

  player1->setQueueNumber(-1);
  player1->getSocket()->sendMessage("4");

  player2->setQueueNumber(-1);
  player2->getSocket()->sendMessage("4");

  //_queues[gamemode].erase(std::remove(_queues[gamemode].begin(), _queues[gamemode].end(), player1), _queues[gamemode].end());
  //_queues[gamemode].erase(std::remove(_queues[gamemode].begin(), _queues[gamemode].end(), player2), _queues[gamemode].end());

// Cherche le mode de jeu
  switch(gamemode){
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
   case 7 :
      game = new RealTimeAlice(player1,player2);
      break;
  }

  ExecInfoThread *infoThread = new ExecInfoThread();
  std::thread *game_thread = new std::thread(startGame, game, player1, player2, infoThread);
  infoThread->setThread(game_thread);
  _games.push_back(infoThread);
  delFinishedThread(_games);
}
