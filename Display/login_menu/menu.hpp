#ifndef __MENU__HPP
#define __MENU__HPP

#include <ncurses.h>
#include <string>

<<<<<<< HEAD
class LoginMenu
=======
class Menu
>>>>>>> prototype
{
private:
  int y_max, x_max;

  WINDOW* menu_win;

public:
<<<<<<< HEAD

  LoginMenu();
  ~LoginMenu();

  void init();

  std::string get_infos(std::string type);

=======
  Menu();
  ~Menu();

  std::string get_user_input();
>>>>>>> prototype
};

#endif
