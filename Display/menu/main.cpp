#include "Menu.cpp"
#include <string>
#include <vector>

int main()
{
  std::vector<std::string> test;
  test.push_back("Jouer");
  test.push_back("Chat");
  test.push_back("Stats");
  test.push_back("Quitter");

  Menu* menu = new Menu(test);
}
