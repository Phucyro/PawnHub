#include "MenuHandler.hpp"

MenuHandler::MenuHandler(): data_menu(nullptr), choices_menu(nullptr), stats_w(nullptr)
{
  initscr();
  start_color();
}

MenuHandler::~MenuHandler()
{
  delwin(data_menu);
  delwin(choices_menu);
  delwin(stats_w);
  endwin();
}

void MenuHandler::init_dataw()
/** Initialise les parametres windows du data menu **/
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
/** permet d'obtenir l'input du joueur **/
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
/** print le message d'erreur **/
{
  mvprintw(1,1,warning.c_str());
  refresh();
}

void MenuHandler::init_choicesw()
/** Initialise les parametres windows du choices menu **/
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

  return highlight;
}

void MenuHandler::init_statsw()
/** initialise les parametres windows du stat menu **/
{
  int y_max, x_max;
  getmaxyx(stdscr, y_max, x_max);
  stats_w = newwin(y_max-8, x_max-12, 0 , 5);
  box(stats_w, 0, 0);



  /**   // A titre d'information pour les positions
  for (int i=0; i<10 ; i++)
  {
    mvwprintw(stats_w, 5+i, 5, "1");
    mvwprintw(stats_w, 5+i, 5+x_split, "1");
    mvwprintw(stats_w, 5+i, 5+2*x_split, "1");
    mvwprintw(stats_w, 5+i, 5+3*x_split, "1");
  }
  **/

}

void MenuHandler::init_statst(std::string mode)
/** print la fenetre de top10 **/
{
  int y_max, x_max;
  getmaxyx(stdscr, y_max, x_max);

  int x_title = x_max / 4;

  int y_box , x_box;
  getmaxyx(stats_w, y_box, x_box);

  int x_split = (x_box/4) + 2;
  int y_split = (y_box/10);

  mvwprintw(stats_w, 1, x_title + x_title/2, "%s : Top 10 ", mode.c_str());

  mvwprintw(stats_w, 3, 5, "Username");
  mvwprintw(stats_w, 3, 5+1*x_split,"Wins");
  mvwprintw(stats_w, 3, 5+2*x_split, "Loses");
  mvwprintw(stats_w, 3, 5+3*x_split, "Draws");

  for (int k=0; k<10 ; k++)
  {
    mvwprintw(stats_w, 5+k, 1,"%d", k+1);
  }

  refresh_board();
}

void MenuHandler::init_statsp(std::string name)
/** print la fenetre personnelle du joueur **/
{
  int y_max, x_max;
  getmaxyx(stdscr, y_max, x_max);

  int x_title = x_max / 4;

  int y_box, x_box;
  getmaxyx(stats_w, y_box, x_box);

  int x_split = (x_box/4) + 2;
  int y_split = (y_box/10);

  mvwprintw(stats_w,1,x_title+x_title/2, "%s's stats", name.c_str());
  mvwprintw(stats_w, 3, 5, "Mode");
  mvwprintw(stats_w, 3, 5+1*x_split,"Wins");
  mvwprintw(stats_w, 3, 5+2*x_split, "Loses");
  mvwprintw(stats_w, 3, 5+3*x_split, "Draws");

  refresh_board();

}

void MenuHandler::update_stats(int number, std::string name, int wins, int loses, int draws)
/** update ligne joueur du menu stats (number commence en 0) **/
{
  int y_box, x_box;
  int x_split;

  getmaxyx(stats_w, y_box, x_box);
  x_split = (x_box/4)+2;

  mvwprintw(stats_w, 5+number, 5, name.c_str());
  mvwprintw(stats_w, 5+number, 5+x_split, "%d", wins);
  mvwprintw(stats_w, 5+number, 5+2*x_split, "%d", loses);
  mvwprintw(stats_w, 5+number, 5+3*x_split, "%d", draws);

  refresh_board();
}



void MenuHandler::refresh_board()
{
  wrefresh(data_menu);
  wrefresh(choices_menu);
  wrefresh(stats_w);
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
