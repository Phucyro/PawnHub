#include "ChoicesMenu.hpp"

ChoicesMenu::ChoicesMenu(const std::vector<std::string> param): main_win(nullptr), choices(param)
{
  initscr(); // initialisation of ncurses
  noecho();
  cbreak();
  curs_set(0); // curseur invisible

  // Initialisation of the window ChoicesMenu
  int y_max, x_max;
  getmaxyx(stdscr, y_max, x_max);

  main_win = newwin(7, x_max - 12, y_max - y_max/3 , 5);
  box(main_win, 0, 0);
  refresh();
  wrefresh(main_win);

  init();
}

ChoicesMenu::~ChoicesMenu()
{
  delwin(main_win);
  endwin();
}

int ChoicesMenu::init()
{

  keypad(main_win, true); // allow use of arrow keys

  int highlight = 0;

  while (1) // loop until user chose a mode
  {
      for (int i = 0; i < choices.size(); i++)
      // displays list of choices
      {

        if (i == highlight) // current choice
            wattron(main_win, A_REVERSE);
        mvwprintw(main_win, i+1, 1, choices[i].c_str() );
        wattroff(main_win, A_REVERSE);
      }

      refresh();
      wrefresh(main_win);

      int user_choice = wgetch(main_win); // get user input

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

  mvprintw(1,1,"Your choice was %s", choices[highlight].c_str());

  getch();
  endwin();

  return highlight;

}
