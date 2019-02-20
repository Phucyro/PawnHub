#ifndef __MENU__HPP
#define __MENU__HPP

#include <ncurses.h>
#include <string>

class Menu
{
private:
  int y_max, x_max;

  WINDOW* menu_win;

public:
  Menu();
  ~Menu();

  std::string get_user_input();
};

#endif
