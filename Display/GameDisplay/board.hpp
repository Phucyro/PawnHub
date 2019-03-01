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
  const char* mode;
  const char* colour;

  void init_windows();

  void draw_rectangle(int x1, int y1, int x2, int y2);
  void draw_coordinates();

  void test_game();
  void exit();


public:
  Board();
  Board(int lines, int cols);
  ~Board();

  void init_ncurses();

  void draw_pieces(std::string);

  void draw_infos();

  // void move_piece(int, int, int, int, std::string);

  void refresh_board();

  void set_mode(const char*);
  void set_colour(const char*);
  void update_turn(const char*);
  void declare_check();
  void endgame(const char*);

  std::string get_movement();
  std::string get_promotion();

  bool isRunning();

  //change infos win
  void change_mode(std::string);
  void change_last_move(std::string);
  void change_turn(std::string);


private:

  int columns;
  int lines;

  bool running;

};

#endif
