#ifndef _MATCHMAKING_H_
#define _MATCHMAKING_H_

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "../Code/Player.hpp"

class Matchmaking {
private:
  std::map<unsigned int, std::vector<Player*>> _queues;

public:
  Matchmaking(unsigned int number_of_queues);
  void addPlayer(Player* player, unsigned int queue_number);
  void removePlayer(Player* player);

protected:
  void check(unsigned int queue_number);
  void createGame(Player* player1, Player* player2, unsigned int game_mode);
};

#endif
