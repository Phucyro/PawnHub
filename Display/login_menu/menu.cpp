#include "menu.hpp"

Menu::Menu(): y_max(0), x_max(0), menu_win(0)
{
  initscr();
  noecho();
  cbreak();
  curs_set(0);

}

Menu::~Menu()
{

}

std::string Menu::get_user_input()
{
  getmaxyx(stdscr,y_max,x_max);
  menu_win = newwin(5, x_max-12, y_max - y_max/3, 5);
  box(menu_win,0,0);
  refresh();
  wrefresh(menu_win);

  keypad(menu_win,true);
  curs_set(1);

  mvwprintw(menu_win,1,1,"Entrez votre login et mdp");
  wrefresh(menu_win);

  std::string user_input;
  char* tmp = new char[160];
  getstr(tmp);
  delete tmp;
  user_input = tmp;

  getch();
  endwin();

  return user_input;
}
