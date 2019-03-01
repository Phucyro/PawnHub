#include "MenuHandler.cpp"

int main()
{
  MenuHandler* test = new MenuHandler();

  //TEST 1
  test->init_dataw();
  test->get_infos("test");
  test->refresh_board();

  test->print_warning("Attention!");
  test->refresh_board();

  //TEST 2
  test->init_dataw();
  test->print_warning("Attention 2!");
  test->get_infos("Nom");

  test->refresh_board();

  test->clear_windows();

  //TEST 3
  test->init_statsw();
  test->init_statsp("Julien");
  test->update_stats(0,"Horde",2, 3, 4);
  test->init_choicesw();
  std::vector<std::string> vecteur;
  vecteur.push_back("Quitter");

  test->get_choice(vecteur);
  test->refresh_board();
  test->end_windows();
  test->clear_windows();

  //TEST 4
  test->init_statsw();
  test->init_statst("Horde");
  test->update_stats(9,"Joe",4,6,8);
  test->init_choicesw();
  test->get_choice(vecteur);
  test->refresh_board();
  test->end_windows();

  //TEST 5
  std::vector<std::string> friends;

  for (int i=0; i<20; i++)
  {
    friends.push_back("Allan");
  }

  test->init_friendsw(friends);
  test->refresh_board();
  test->init_choicesw();
  test->get_choice(vecteur);
  test->refresh_board();
  test->end_windows();





}