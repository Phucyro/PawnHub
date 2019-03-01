#include "ChoicesMenu.cpp"
#include <string>
#include <vector>

int main()
{
  std::vector<std::string> mainMenu,playMenu,gameChoices;
  mainMenu.push_back("Login");
  mainMenu.push_back("Quitter");
  mainMenu.push_back("Credits");

  playMenu.push_back("Jouer");
  playMenu.push_back("Chat");
  playMenu.push_back("Stats");
  playMenu.push_back("Quitter");

  gameChoices.push_back("Classical");
  gameChoices.push_back("Alice");
  gameChoices.push_back("Dark");
  gameChoices.push_back("Horde");

  ChoicesMenu* menu = new ChoicesMenu(mainMenu,playMenu,gameChoices);
}
