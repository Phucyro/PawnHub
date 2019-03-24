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
  std::string mode;
  std::string colour;

  void init_windows();

  void draw_rectangle(int x1, int y1, int x2, int y2);
  void draw_coordinates();

  void draw_alice_coordinates();

  void test_game();


public:
  Board();
  Board(int lines, int cols);
  ~Board();
  void exit();

  void init_ncurses();

  void draw_pieces(std::string);

  void draw_alice_board();
  void draw_alice_pieces(std::string);

  void draw_infos();
  void clear_board();
  void clear_get_movement();
  void clear_premove();

  // void move_piece(int, int, int, int, std::string);

  void refresh_board();

  void set_mode(const std::string&);
  void set_colour(const std::string&);
  void update_turn(const char*);
  void declare_check();
  void endgame(const char*);

  std::string get_movement();
  std::string get_promotion();

  bool isRunning();

  //change infos win
  void change_mode(const std::string&);
  void change_last_move(const std::string&);
  void change_turn(const std::string&);
  void show_time_left(const std::string&);
  
  void ask_ipos();
  void print_ipos(int, int);
  void ask_epos();
  void print_epos(int, int);
  void print_premove();
  char getchar();


private:

  int columns;
  int lines;

  bool running;

};

#endif
