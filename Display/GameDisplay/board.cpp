#include "board.hpp"
#include "BoardParsing.hpp"
#include "MoveParsing.hpp"

Board::Board(): infos_win(nullptr), mode(nullptr), colour(nullptr), columns(BOARD_COLS), lines(BOARD_LINES), running(false) {}

Board::Board(int line_count, int col_count): infos_win(nullptr), mode(nullptr), colour(nullptr), columns(col_count), lines(line_count), running(false) {}

Board::Board(const Board& _other): infos_win(_other.infos_win), mode(_other.mode), colour(_other.colour), columns(_other.columns), lines(_other.lines), running(_other.running) {}

Board& Board::operator=(const Board& _other) {
  infos_win = _other.infos_win;
  mode = _other.mode;
  colour = _other.colour;
  columns = _other.columns;
  lines = _other.lines;
  running = _other.running;
  return *this;
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
  curs_set(0);

  // got this as error-handling, not mine but standard enough - http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/color.html
  if(has_colors() == FALSE)
  {
    endwin();
    printf("Your terminal does not support color\n");
    std::exit(1);
  }
  start_color();
  init_pair(WHITE_PLAYER, COLOR_WHITE, COLOR_BLACK);
  init_pair(BLACK_PLAYER, COLOR_RED, COLOR_BLACK);

  /**
  init_pair(1,COLOR_WHITE, COLOR_BLUE);
  init_pair(2,COLOR_WHITE, COLOR_RED);

  attron(COLOR_PAIR(1));
  mvprintw(1,1,"P");
  attroff(COLOR_PAIR(1));

  attron(COLOR_PAIR(2));
  mvprintw(4,4,"T");
  attroff(COLOR_PAIR(2));
  **/

  init_windows();
}


void Board::init_windows()
/**Initialise le board**/
{
  int board_height = (lines+1)*OFFSET;
  int board_width = (columns+1)*OFFSET;

  infos_win = newwin(board_height/2, board_width, 0, board_width+4);
  box(infos_win,0,0);

  for (int i=0; i<(lines*OFFSET); i+=OFFSET)
    for (int j=0; j<(columns*OFFSET); j+=OFFSET)
    {
      draw_rectangle(i+OFFSET,j+2,i+OFFSET+SIDE_LENGTH,j+2+SIDE_LENGTH);
    }

  draw_coordinates();
  draw_infos();

  refresh_board();
  endwin();

}



void Board::draw_infos()
/** Initialise la fenetre des infos **/
{
  int x_win, y_win;
  getmaxyx(infos_win, y_win, x_win);

  mvwprintw(infos_win, 1, 1, "GAME MODE : %s", mode);

  mvwprintw(infos_win, 4, 1, "YOUR COLOUR : %s", colour);

  mvwprintw(infos_win , 7, 1, "%s", "TURN COUNT : ");

  mvwprintw(infos_win , 10, 1, "PRESS F4 TO QUIT");

  refresh_board();
}

void Board::set_mode(const char* game) {
  mode = game;
  refresh_board();
}

void Board::set_colour(const char* player_colour) {
  colour = player_colour;
  refresh_board();
}

void Board::update_turn(const char* turn) {
  mvwprintw(infos_win, 7, 14, "%s", turn);
  refresh_board();
}

void Board::declare_check() {
  mvprintw(15, 30, "%s", "CHECK");
  refresh_board();
  getch();
}

void Board::endgame(const char* message) {
  mvprintw(15, 30, "%s", message);
  refresh_board();
  getch();
}

void Board::draw_coordinates()
/** Initialise les coordonnees X et Y du board **/
{
  for (int i=0; i<lines; i++)
  {
    mvprintw(OFFSET*(i+1), 1, "%d", i+1);
    mvprintw(OFFSET*(i+1), 25+OFFSET , "%d", i+1);
  }

  for (int i=0; i<columns; i++)
  {
    mvprintw(1, 1+OFFSET*(i+1), "%c", 'A'+i);
    mvprintw(25+1, 1+OFFSET*(i+1), "%c", 'A'+i);
  }
  refresh_board();
}

void Board::draw_pieces(std::string board)
/** Dessine les pions sur le board de depart **/
{
	clear();
	refresh_board();
	//exit();
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


// UNNECESSARY since we have the full board sent over - still here in case of apocalypse
// void Board::move_piece(int x1, int y1, int x2, int y2, std::string piece_type)
// /** permet de bouger un pion de la position (x1,y1) vers (x2,y2) **/
// {
//   mvprintw(1+OFFSET*x1, 1+OFFSET*y1, " ");
//
//   const char* piece = piece_type.c_str();
//
//   mvprintw(1+OFFSET*y2, 1+OFFSET*x2, piece);
//
//   refresh_board();
// }


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

  // echo();    // would have been cool but can't quite get it to work properly
  // nocbreak();
  for (int i = 0; i < 5; ++i) {
    if (i == 0) {
      mvprintw(15, 32, "%s", "State initial piece position: ");
    }
    else if (i == 2) {
      mvprintw(16, 32, "%s", "State moved piece position:  ");
    }
    else if (i == 4) {break;}
    move[i] = getch();
    mvprintw(15 + (i/2), 60 + (i%2), "%c", move[i]);
  }
  // noecho();
  // cbreak();
  refresh_board();

  std::string effective_move = moveToString(move);
  // const char* this_move = effective_move.c_str();
  // mvprintw(18, 30, "%s", this_move);

  return effective_move;
}

std::string Board::get_promotion() {
  mvprintw(15, 30, "%s", "What do you wish to promote your pawn to?");
  mvprintw(16, 30, "%s", "Queen: q   Bishop: b   Knight: h    Rook: r");

  int answer = getch();
  std::string promotion;
  promotion.append(1, char(answer));
  return promotion;
}

void Board::exit()
{
  delwin(infos_win);

  endwin();
}

void Board::change_mode(std::string mode)
{
  mvwprintw(infos_win,1,13,mode.c_str());
  refresh();
  wrefresh(infos_win);
}

void Board::change_last_move(std::string move)
{
  mvwprintw(infos_win,4,13,move.c_str());
  refresh();
  wrefresh(infos_win);
}

void Board::change_turn(std::string turn)
{
  mvwprintw(infos_win,7,8,turn.c_str());
  refresh();
  wrefresh(infos_win);
}
