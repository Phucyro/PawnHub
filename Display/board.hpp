#ifndef __BOARD_HPP
#define __BOARD_HPP

#include <ncurses.h>
#include <iostream>
#include "constants.hpp"
#include <string>

// permet de pas faire +3 tout le temps
// bonus: plus facile a changer si on veut modifier la taille
#define SIDE_LENGTH 2   //seule utilisation: dans init_windows, appel de draw_rectangle
#define OFFSET (SIDE_LENGTH+1)

/**
TO DO:
-Tour du joueur
-Parseur positions pions
-Mise a jour du board
**/

class Board
{

protected:
  WINDOW* infos_win;

  void draw_rectangle(int x1, int y1, int x2, int y2);
  void draw_pieces();
  void draw_coordinates();
  void draw_infos();


public:
  Board();
  Board(int lines, int cols);
  ~Board();

  void init_ncurses();
  void init_windows();

  void move(int x1, int y1, int x2, int y2, std::string pawn_type);
  void update_board(std::string pawns_list);

  void refresh_board();


private:

  int columns;
  int lines;
};

#endif
