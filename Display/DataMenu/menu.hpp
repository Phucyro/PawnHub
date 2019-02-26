#ifndef __MENU__HPP
#define __MENU__HPP

#include <ncurses.h>
#include <string>

class LoginMenu
{
private:
  int y_max, x_max;

  WINDOW* menu_win;

public:

  LoginMenu();
  ~LoginMenu();

  void init();

  std::string get_infos(std::string type);

};

#endif
