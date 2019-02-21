#include "board.hpp"
#include "BoardParsing.hpp"
#include "MoveParsing.hpp"

Board::Board(): infos_win(nullptr), columns(BOARD_COLS), lines(BOARD_LINES), running(false)
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

  draw_coordinates();
  draw_infos();

  refresh_board();
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
    mvprintw(1+(OFFSET*i), 25 , "%d", lines-i);
  }

  for (int i=0; i<columns; i++)
  {
    mvprintw(24, 1+(OFFSET*i), "%c", 'A'+i);
  }

}

void Board::draw_pieces(std::string board)
/** Dessine les pions sur le board de depart **/
{
	clear();
	refresh_board();
	exit();
	init_windows();
  stringToBoard(board);
  refresh_board();
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

void Board::move_piece(int x1, int y1, int x2, int y2, std::string piece_type)
/** permet de bouger un pion de la position (x1,y1) vers (x2,y2) **/
{
  mvprintw(1+OFFSET*x1, 1+OFFSET*y1, " ");

  const char* piece = piece_type.c_str();

  mvprintw(1+OFFSET*y2, 1+OFFSET*x2, piece);

  refresh_board();
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

std::string Board::get_movement()
{
  int move[4];

  for (int i = 0; i < 4; ++i) {
    if (i == 0) {
      mvprintw(15, 30, "%s", "State initial piece position: ");
    }
    else if (i == 2) {
      mvprintw(16, 30, "%s", "State moved piece position: ");
    }
    mvprintw(18, 30, "%d", i);
    move[i] = getch();
    mvprintw(18, 32, "%d", i);
    mvprintw(15 + (i/2), 60 + (i%2), "%c", move[i]);
  }

  std::string effective_move = moveToString(move);
  const char* this_move = effective_move.c_str();
  mvprintw(18, 30, "%s", this_move);
  // switch des choix a faire?
  std::cout << "Returning" << effective_move << std::endl;
  return effective_move;
}

void Board::exit()
{
  delwin(infos_win);

  endwin();
}
