#ifndef __BOARD_HPP
#define __BOARD_HPP

#include <ncurses.h>
#include <iostream>
#include "constants.hpp"
#include <string>

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

  void init_windows();

  void draw_rectangle(int x1, int y1, int x2, int y2);
  void draw_coordinates();
  void draw_infos();


  void test_game();
  void exit();


public:
  Board();
  Board(int lines, int cols);
  ~Board();

  void init_ncurses();

  void draw_pieces(std::string);

  void move_piece(int, int, int, int, std::string);

  void refresh_board();

  std::string get_movement();

  bool isRunning();


private:

  int columns;
  int lines;

  bool running;

};

#endif
