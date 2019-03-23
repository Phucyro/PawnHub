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
  MenuHandler(const MenuHandler&);
  MenuHandler& operator=(const MenuHandler&);
  ~MenuHandler();

  //data menus
  void init_dataw();
  std::string get_infos(std::string);
  void print_warning(std::string);
  void print_warning2(std::string);


  //choices menus
  void init_choicesw();
  int get_choice(const std::vector<std::string> param);

  // init carre au dessus d'un menu choice
  void init_statsw();

  // stats menu
  void init_statst(std::string mode); //stats top 10
  void init_statsp(std::string name); //stats personelles

  void update_stats(int number, std::string first_column, std::string wins, std::string loses, std::string draws);

  //friends list / invites menu
  void init_friendsw(const std::vector<std::string> friends);

  //chat
  void init_chatw();
  void update_chatw(int, std::string, std::string);

  //windows utilites
  void refresh_board();
  void clear_windows();
  void end_windows();


};


#endif
