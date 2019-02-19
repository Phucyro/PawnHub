#ifndef __BOARD_HPP
#define __BOARD_HPP

#include <ncurses.h>
#include <iostream>
#include "constants.hpp"

/**
TO DO:
-Tour du joueur
-Envoi mouvement (position debut/fin)
-Parseur positions pions
-Mise a jour du board
**/

class Board
{

protected:
  WINDOW* game_win;
  WINDOW* vcoord_win;
  WINDOW* hcoord_win;
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


private:

  int columns;
  int lines;
};

#endif
