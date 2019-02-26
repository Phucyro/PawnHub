#include "MenuHandler.cpp"

int main()
{
  MenuHandler* test = new MenuHandler();
  test->init_dataw();
  test->get_infos("test");
  test->refresh_board();

  test->print_warning("Attention!");
  test->refresh_board();

  test->init_dataw();
  test->print_warning("Attention 2!");
  test->get_infos("Nom");

  test->refresh_board();

  test->clear_windows();

  test->init_choicesw();
  std::vector<std::string> vecteur;
  vecteur.push_back("Jouer");
  vecteur.push_back("Stats");
  vecteur.push_back("Quitter");

  test->get_choice(vecteur);
  test->end_windows();

}
