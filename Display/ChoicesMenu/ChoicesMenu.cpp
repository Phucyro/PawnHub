#include "ChoicesMenu.hpp"

ChoicesMenu::ChoicesMenu(const std::vector<std::string> mainMenu,const std::vector<std::string> playMenu): main_win(nullptr), mainMenu(mainMenu),playMenu(playMenu)
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

bool login(){
  return true;
}

void ChoicesMenu::init()
{
  int y_max, x_max, user_choice;
  getmaxyx(stdscr, y_max, x_max);

  keypad(main_win, true); // allow use of arrow keys

  int highlight = 0;

  while (1) // loop until user chose a mode
  {
      for (int i = 0; i < mainMenu.size(); i++)
      // displays list of mainMenu
      {

        if (i == highlight) // current choice
            wattron(main_win, A_REVERSE);
        mvwprintw(main_win, i+1, 1, mainMenu[i].c_str() );
        wattroff(main_win, A_REVERSE);
      }

      refresh();
      wrefresh(main_win);

      user_choice = wgetch(main_win); // get user input

      switch (user_choice) // buttons
      {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
                highlight = mainMenu.size() - 1;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == mainMenu.size() )
                highlight = 0;
            break;
        default:
            break;
      }

      if (user_choice == 10) // ENTER
          break;
  }


  if(highlight == 0){
    mvprintw(1, 1,"Login");

    //put here login screen //TODO

    if(login()==true){
      //open playMenu (gonna code that 27/02) -Andre
    }

  }else if(highlight == 1){
    mvprintw(1, 1,"Quit");
    delwin(main_win);
    endwin();

  }else if (highlight == 2){
    erase();
    refresh();


    mvprintw(x_max/2 , y_max - (y_max / 4),"Author");
    /*
    mvprintw(x_max/2 - 2, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 4, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 6, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 8, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 10, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 12, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 14, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 20, y_max - (y_max / 4),"Authors :");
    */



    getch();
    endwin();

  }




}
