#include "MenuHandler.hpp"

MenuHandler::MenuHandler(): data_menu(nullptr), choices_menu(nullptr)
{
  initscr();
  start_color();
}

MenuHandler::~MenuHandler()
{
  delwin(data_menu);
  delwin(choices_menu);
}

void MenuHandler::init_dataw()
{
  nocbreak();
  echo();
  curs_set(1);
  keypad(data_menu,true);

  int y_max, x_max;

  getmaxyx(stdscr, y_max, x_max);
  data_menu = newwin(5, x_max-12, y_max - y_max/3, 5);
  box(data_menu,0,0);

  refresh();
  wrefresh(data_menu);
}

std::string MenuHandler::get_infos(std::string type)
{
  mvwprintw(data_menu,1,1,"Entrez votre %s", type.c_str());

  std::string input;

  int ch = mvwgetch(data_menu, 2, 1);

  while ( ch != '\n' )
  {
      input.push_back( ch );
      ch = mvwgetch(data_menu,2,1);
  }

  wmove(data_menu,2,1);
  wclrtoeol(data_menu);

  // restore your cbreak / echo settings here
  return input;
}

void MenuHandler::print_warning(std::string warning)
{
  mvprintw(1,1,warning.c_str());
  refresh();
}

void MenuHandler::init_choicesw()
{
  noecho();
  cbreak();
  curs_set(0);

  int y_max, x_max;
  getmaxyx(stdscr,y_max,x_max);

  choices_menu = newwin(7, x_max - 12, y_max - y_max/3 , 5);
  box(choices_menu, 0, 0);
  refresh();
  wrefresh(choices_menu);
}

int MenuHandler::get_choice(const std::vector<std::string> choices)
/** retourne le numero choisi correspondant dans le vecteur **/
{
  keypad(choices_menu,true);

  int highlight = 0;

  while (1) // loop until user chose a mode
  {
      for (int i = 0; i < choices.size(); i++)
      // displays list of choices
      {

        if (i == highlight) // current choice
            wattron(choices_menu, A_REVERSE);
        mvwprintw(choices_menu, i+1, 1, choices[i].c_str() );
        wattroff(choices_menu, A_REVERSE);
      }

      refresh();
      wrefresh(choices_menu);

      int user_choice = wgetch(choices_menu); // get user input

      switch (user_choice) // buttons
      {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
                highlight = choices.size() - 1;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == choices.size() )
                highlight = 0;
            break;
        default:
            break;
      }

      if (user_choice == 10) // ENTER
          break;
  }

  mvprintw(1,1, choices[highlight].c_str());

  return highlight;
}

void MenuHandler::refresh_board()
{
  wrefresh(data_menu);
  wrefresh(choices_menu);
  refresh();
}

void MenuHandler::clear_windows()
{
  erase();
  refresh_board();
}

void MenuHandler::end_windows()
{
  endwin();
}
