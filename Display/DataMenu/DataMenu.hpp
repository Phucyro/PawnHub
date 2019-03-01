#ifndef _DATA_MENU__HPP
#define _DATA_MENU__HPP

#include <ncurses.h>
#include <string>

class DataMenu
{
private:
  int y_max, x_max;

  WINDOW* menu_win;

public:

  DataMenu();
  ~DataMenu();

  std::string get_infos(std::string type);

};

#endif
