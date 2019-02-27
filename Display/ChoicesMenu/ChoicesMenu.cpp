#ifndef __CHOICESMENU__CPP
#define __CHOICESMENU__CPP
#include "ChoicesMenu.hpp"
#include <form.h>


ChoicesMenu::ChoicesMenu(const std::vector<std::string> mainMenu,
  const std::vector<std::string> playMenu,
  const std::vector<std::string> gameChoices): main_win(nullptr),
  mainMenu(mainMenu),playMenu(playMenu),gameChoices(gameChoices)
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

void ChoicesMenu::init()
{
  int y_max, x_max, user_choice;
  getmaxyx(stdscr, y_max, x_max);
  box(main_win, 0, 0);
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

  //LOGIN SCREEEN
  if(highlight == 0){
    login(main_win);
    erase();
    refresh();
    //init();

  }else if(highlight == 1){
    mvprintw(1, 1,"Quit");
    delwin(main_win);
    endwin();

  }else if (highlight == 2){
    erase();
    refresh();

    mvprintw(x_max/2 , y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 2, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 4, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 6, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 8, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 10, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 12, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 14, y_max - (y_max / 4),"Author");
    mvprintw(x_max/2 - 20, y_max - (y_max / 4),"Authors :");

    getch();
    endwin();
  }

  delwin(main_win);
  endwin();
}

void ChoicesMenu::login(WINDOW* loginWindow)
{
  FIELD *field[2]; //number of fields
  FORM  *my_form;
  int y_max, x_max,user_choice,highlight;
  getmaxyx(stdscr, y_max, x_max);
  keypad(main_win, true); // allow use of arrow keys


  /* Initialize few color pairs */
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);

  /* Initialize the fields */
  field[0] = new_field(1, 10, x_max/2 - 2, y_max - (y_max / 4), 0, 0);
  field[1] = new_field(1, 10, x_max/2 - 4, y_max - (y_max / 4), 0, 0);

  /* Set field options */
  set_field_fore(field[0], COLOR_PAIR(1));/* Put the field with black background */
  set_field_back(field[0], COLOR_PAIR(2));
  set_field_back(field[0], A_UNDERLINE); 	/* Print a line for the option 	*/
  field_opts_on(field[0], O_ACTIVE);
  field_opts_on(field[0], O_PUBLIC);
  field_opts_on(field[0], O_EDIT);
  field_opts_on(field[0], O_BLANK);
  field_opts_on(field[0], O_VISIBLE);



  set_field_fore(field[1], COLOR_PAIR(1));/* Put the field with black background */
  set_field_back(field[1], COLOR_PAIR(2));
  set_field_back(field[1], A_UNDERLINE); 	/* Print a line for the option 	*/
  field_opts_off(field[1], O_PUBLIC);
  field_opts_on(field[1], O_EDIT);
  field_opts_on(field[1], O_BLANK);
  field_opts_on(field[1], O_VISIBLE);

  /* Create the form and show it */ //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<CRASH HERE
  my_form = new_form(field);
  post_form(my_form);
  refresh();

  set_current_field(my_form, field[0]); /* Set focus to the colored field */
  mvprintw(x_max/2 - 1, y_max - (y_max / 4), "Username:");
  mvprintw(x_max/2 - 3, y_max - (y_max / 4), "Password:");
  mvprintw(LINES - 2, 0, "Use UP, DOWN arrow keys to switch between fields");
  refresh();

  user_choice = 0; //reset user_choice

  bool loggedIn = false;
  /* Loop through to get user requests */
  while(loggedIn==true )
  {	switch(user_choice)
    {	case KEY_DOWN:
        /* Go to next field */
        form_driver(my_form, REQ_NEXT_FIELD);
        /* Go to the end of the present buffer */
        /* Leaves nicely at the last character */
        form_driver(my_form, REQ_END_LINE);
        break;
      case KEY_UP:
        /* Go to previous field */
        form_driver(my_form, REQ_PREV_FIELD);
        form_driver(my_form, REQ_END_LINE);
        break;
      case 10:
        //do here the server connection

      default:
        /* If this is a normal character, it gets */
        /* Printed				  */
        form_driver(my_form, user_choice);
        break;
    }
  }

  /* Un post form and free the memory */
  unpost_form(my_form);
  free_form(my_form);
  free_field(field[0]);
  free_field(field[1]);

  erase();
  refresh();

}

#endif
