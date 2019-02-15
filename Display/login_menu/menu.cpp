#include "menu.hpp"

Menu::Menu():
{
  initscr();
  noecho();
  cbreak();
  curs_set(0);

  init_windows();
}

Menu::~Menu()
{

}
