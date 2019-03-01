#ifndef __CHOICESMENU__HPP
#define __CHOICESMENU__HPP

#include "ncurses.h"
#include <string>
#include <vector>
#include <iostream>
#include <form.h>


class ChoicesMenu
{
protected:
  const std::vector<std::string> mainMenu,playMenu,gameChoices;

  WINDOW* main_win;

public:
  ChoicesMenu();
  ChoicesMenu(const std::vector<std::string> mainMenu,
              const std::vector<std::string> playMenu,
              const std::vector<std::string> gameChoices);
  ~ChoicesMenu();

  void init();
  void login(WINDOW*);
};

#endif
