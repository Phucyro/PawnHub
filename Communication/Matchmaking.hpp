#ifndef _MATCHMAKING_H_
#define _MATCHMAKING_H_

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "../Code/Player.hpp"
#include <thread>
#include "../Code/Classic.hpp"

class Matchmaking {
private:
  std::map<int, std::vector<Player*>> _queues;

public:
  Matchmaking(unsigned int number_of_queues);
  void addPlayer(Player* player, unsigned int queue_number);
  void removePlayer(Player* player);

  void check(unsigned int queue_number);
};

#endif
