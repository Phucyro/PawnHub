#ifndef _MENU_HANDLER_HPP
#define _MENU_HANDLER_HPP

#include <string>
#include "ncurses.h"
#include <vector>
#include <iostream>

class MenuHandler
{
protected:
  WINDOW* data_menu;
  WINDOW* choices_menu;
  WINDOW* stats_w;

public:
  MenuHandler();
  ~MenuHandler();

  //data menus
  void init_dataw();
  std::string get_infos(std::string);
  void print_warning(std::string);

  //choices menus
  void init_choicesw();
  int get_choice(const std::vector<std::string> param);

  //stats menu
  void init_statsw();
  void update_stats(int, std::string, int, int, int);

  //windows utilites
  void refresh_board();
  void clear_windows();
  void end_windows();


};


#endif
