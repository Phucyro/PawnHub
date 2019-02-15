#include "board.hpp"
#include "BoardParsing.hpp"

Board::Board(): infos_win(nullptr), columns(8), lines(8), running(false)
{

}


Board::Board(int line_count, int col_count): infos_win(nullptr), columns(col_count), lines(line_count), running(false)
{

}

Board::~Board()
{

  delwin(infos_win);

  endwin();
}

void Board::init_ncurses()
/**Initialise les parametres pour ncurses**/
{
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE); //utilisation du keypad
  curs_set(1);

  init_windows();

}


void Board::init_windows()
/**Initialise le board**/
{
  int board_height = lines*OFFSET;
  int board_width = columns*OFFSET;

  infos_win = newwin(board_height/2, board_width, 0, board_width+4);
  box(infos_win,0,0);

  for (int i=0; i<24; i+=OFFSET)
    for (int j=0; j<24; j+=OFFSET)
    {
      draw_rectangle(i,j,i+SIDE_LENGTH,j+SIDE_LENGTH);
    }

  draw_pieces();
  draw_coordinates();
  draw_infos();

  refresh_board();
  getch();
  endwin();

}

void Board::draw_infos()
/** Initialise la fenetre des infos **/
{
  int x_win, y_win;
  getmaxyx(infos_win, y_win, x_win);


  mvwprintw(infos_win, 1, 1, "GAME MODE : ...");

  mvwprintw(infos_win , 4, 1, "LAST MOVE : ...");

  mvwprintw(infos_win , 7, 1, "PLAYER'S TURN : ...");

  mvwprintw(infos_win , 10, 1, "PRESS F4 TO QUIT");

}

void Board::draw_coordinates()
/** Initialise les coordonnees X et Y du board **/
{
  for (int i=0; i<lines; i++)
  {
    mvprintw(1+(OFFSET*i), 25 , "%d", i+1);
  }

  for (int i=0; i<columns; i++)
  {
    mvprintw(24, 1+(OFFSET*i), "%c", 'A'+i);
  }

  // mvprintw(24, 1, "A");
  // mvprintw(24, 4, "B");
  // mvprintw(24, 7, "C");
  // mvprintw(24, 10, "C");
  // mvprintw(24, 13, "D");
  // mvprintw(24, 16, "E");
  // mvprintw(24, 19, "F");
  // mvprintw(24, 22, "G");

}

void Board::draw_pieces()
/** Dessine les pions sur le board de depart **/
{
  // Ca maaarche
  // std::string test = boardToString();
  // stringToBoard(test);

  mvprintw(1,1, "T");
  mvprintw(1,4, "K");
  mvprintw(1,7, "B");
  mvprintw(1,10, "Q");
  mvprintw(1,13, "R");
  mvprintw(1,16, "B");
  mvprintw(1,19, "K");
  mvprintw(1,22, "T");

  mvprintw(4,1, "P");
  mvprintw(4,4, "P");
  mvprintw(4,7, "P");
  mvprintw(4,10, "P");
  mvprintw(4,13, "P");
  mvprintw(4,16, "P");
  mvprintw(4,19, "P");
  mvprintw(4,22, "P");

  mvprintw(22,1, "T");
  mvprintw(22,4, "K");
  mvprintw(22,7, "B");
  mvprintw(22,10, "Q");
  mvprintw(22,13, "R");
  mvprintw(22,16, "B");
  mvprintw(22,19, "K");
  mvprintw(22,22, "T");

  mvprintw(19,1, "P");
  mvprintw(19,4, "P");
  mvprintw(19,7, "P");
  mvprintw(19,10, "P");
  mvprintw(19,13, "P");
  mvprintw(19,16, "P");
  mvprintw(19,19, "P");
  mvprintw(19,22, "P");

}

void Board::draw_rectangle(int x1, int y1, int x2, int y2)
/** permet de dessiner des rectangles de (x1,y1) vers (x2, y2) **/
{
  mvhline(y1, x1, 0, x2-x1);
  mvhline(y2, x1, 0, x2-x1);
  mvvline(y1, x1, 0, y2-y1);
  mvvline(y1, x2, 0, y2-y1);
  mvaddch(y1, x1, ACS_ULCORNER);
  mvaddch(y2, x1, ACS_LLCORNER);
  mvaddch(y1, x2, ACS_URCORNER);
  mvaddch(y2, x2, ACS_LRCORNER);
}

void Board::move_pawn(int x1, int y1, int x2, int y2, std::string pawn_type)
/** permet de bouger un pion de la position (x1,y1) vers (x2,y2) **/
{
  mvprintw(1+3*x1, 1+3*y1, " ");

  const char* pawn = pawn_type.c_str();

  mvprintw(1+3*y2, 1+3*x2, pawn);

  refresh_board();
}


void Board::update_board(std::string pawns_list)
{

}

void Board::refresh_board()
/** refresh le board (a faire apres chaque modification) **/
{
  refresh();
  wrefresh(infos_win);
}


bool Board::isRunning()
{
  return running;
}

int Board::get_movement()
{
  int choice = getch();

  //switch des choix a faire?

  return choice;
}

void Board::exit()
{
  delwin(infos_win);

  endwin();
}
