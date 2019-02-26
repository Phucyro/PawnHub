#ifndef __ChoicesMenu__HPP
#define __ChoicesMenu__HPP

//un bouton pour chaque mode
//un pour quitter la file d'attente?
//zone pour le chat
//bouton classement
//bouton statistiques

#include "ncurses.h"
#include <string>
#include <vector>
#include <iostream>

class ChoicesMenu
{
protected:
  const std::vector<std::string> mainMenu,playMenu;

  WINDOW* main_win;

public:
  ChoicesMenu();
  ChoicesMenu(const std::vector<std::string> mainMenu,const std::vector<std::string> playMenu);
  ~ChoicesMenu();

  void init();
};

#endif
