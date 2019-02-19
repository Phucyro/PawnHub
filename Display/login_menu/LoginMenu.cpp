#include "LoginMenu.hpp"

LoginMenu::LoginMenu(): y_max(0), x_max(0), menu_win(0)
{
  initscr();
  nocbreak();
  echo();
  curs_set(1);

  getmaxyx(stdscr,y_max,x_max);
  menu_win = newwin(5, x_max-12, y_max - y_max/3, 5);
  box(menu_win,0,0);
  refresh();
  wrefresh(menu_win);

  keypad(menu_win,true);
  curs_set(1);

  init();
}

LoginMenu::~LoginMenu()
{

}

void LoginMenu::init()
{
  std::string name, password, confirmation;

  name = get_infos("nom");
  password = get_infos("password");
  confirmation = get_infos("confirmation");

  const char* nom = name.c_str();
  const char* pass = password.c_str();
  const char* confirm = confirmation.c_str();

  werase(menu_win);
  mvwprintw(menu_win,1,1,nom);
  refresh();
  wrefresh(menu_win);
  getch();

  werase(menu_win);
  mvwprintw(menu_win,1,1,pass);
  refresh();
  wrefresh(menu_win);
  getch();

  werase(menu_win);
  mvwprintw(menu_win,1,1,confirm);
  refresh();
  wrefresh(menu_win);
  getch();

  endwin();
}

std::string LoginMenu::get_infos(std::string type)
{
  mvwprintw(menu_win,1,1,"Entrez votre %s", type.c_str());

  std::string input;

  // let the terminal do the line editing
  nocbreak();
  echo();

  // this reads from buffer after <ENTER>, not "raw"
  // so any backspacing etc. has already been taken care of
  int ch = mvwgetch(menu_win,2,1);

  while ( ch != '\n' )
  {
      input.push_back( ch );
      ch = mvwgetch(menu_win,2,1);
  }

  wmove(menu_win,2,1);
  wclrtoeol(menu_win);

  // restore your cbreak / echo settings here
  return input;

}
