#include "ChoicesMenu.cpp"
#include <string>
#include <vector>

int main()
{
  std::vector<std::string> mainMenu,playMenu,type;
  mainMenu.push_back("Login");
  mainMenu.push_back("Quitter");
  mainMenu.push_back("Credits");

  playMenu.push_back("Jouer");
  playMenu.push_back("Chat");
  playMenu.push_back("Stats");
  playMenu.push_back("Quitter");


  ChoicesMenu* menu = new ChoicesMenu(mainMenu,playMenu);
}
