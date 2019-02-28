#ifndef __MENU__HPP
#define __MENU__HPP

//un bouton pour chaque mode
//un pour quitter la file d'attente?
//zone pour le chat
//bouton classement
//bouton statistiques

#include "ncurses.h"
#include <string>
#include <vector>
#include <iostream>

class Menu
{
protected:
  const std::vector<std::string> choices;

  WINDOW* main_win;

public:
  Menu();
  Menu(const std::vector<std::string> param);
  ~Menu();

  int init();
};

#endif
