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
#include <thread>
#include <mutex>
#include <queue>
#include <unistd.h>

#define TIME_BETWEEN_MATCH 10000000u //microseconds

extern Data data;

class Matchmaking {
private:
  std::list<ExecInfoThread*> _games;
  std::map<int, std::vector<Player*>> _queues;
  std::mutex _mutex;
  bool _end;
  std::thread _doMatch;

public:
  Matchmaking(int number_of_queues);
  ~Matchmaking();
  void addPlayer(Player* player, int queue_number);
  void removePlayer(Player* player);

  void check(int queue_number);
  void enter(int gamemode, Player* player1, Player* player2);
};

#endif
