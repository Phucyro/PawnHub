#ifndef _MATCHMAKING_H_
#define _MATCHMAKING_H_

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <thread>
#include <list> 
#include <iterator>
#include "../Code/Player.hpp"
#include "ExecInfoThread.hpp"

class Matchmaking {
private:
  std::list<ExecInfoThread*> _games;
  std::map<int, std::vector<Player*>> _queues;

public:
  Matchmaking(int number_of_queues);
  ~Matchmaking();
  void addPlayer(Player* player, int queue_number);
  void removePlayer(Player* player);

  void check(int queue_number);
};

#endif
