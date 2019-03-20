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

}

void Board::draw_alice_coordinates()
{

  for (int i=0; i<lines; i++)
  {
    mvprintw(OFFSET*(i+1), 63, "%d", i+1);
    mvprintw(OFFSET*(i+1), 63+25+OFFSET , "%d", i+1);//54
  }

  for (int i=0; i<columns; i++)
  {
    mvprintw(26, 66+(OFFSET*i), "%c", 'A'+i);//57
    mvprintw(1, 66+(OFFSET*i), "%c", 'A'+i);
  }


  refresh_board();
}

void Board::draw_alice_board()
/**initialise le deuxieme board **/
{
  int board_height = lines*OFFSET;
  int board_width = columns*OFFSET;

  for (int i=65; i<89; i+=OFFSET)//56->80
    for (int j=2; j<25; j+=OFFSET)
    {
      draw_rectangle(i, j, i+SIDE_LENGTH, j+SIDE_LENGTH);
    }

  draw_alice_coordinates();

  refresh_board();


}


void Board::draw_infos()
/** Initialise la fenetre des infos **/
{
  int x_win, y_win;
  getmaxyx(infos_win, y_win, x_win);

  mvwprintw(infos_win, 1, 1, "GAME MODE : %s", mode);

  mvwprintw(infos_win, 4, 1, "YOUR COLOUR : %s", colour);

  mvwprintw(infos_win , 7, 1, "%s", "TURN COUNT : ");

  mvwprintw(infos_win , 10, 1, "PRESS Ctrl+C TO QUIT");

  //refresh_board();
}

void Board::set_mode(const char* game) {
  mode = game;
  //refresh_board();
}

void Board::set_colour(const char* player_colour) {
  colour = player_colour;
  //refresh_board();
}

void Board::update_turn(const char* turn) {
  mvwprintw(infos_win, 7, 14, "%s", turn);
  //refresh_board();
}

void Board::declare_check() {
  mvprintw(14, 30, "%s", "CHECK");
  refresh_board();
}

void Board::endgame(const char* message) {
  clear_get_movement();
  mvprintw(15, 30, "%s", message);
  refresh_board();
  getch();
}

void Board::draw_coordinates()
/** Initialise les coordonnees X et Y du board **/
{
  for (int i=0; i<lines; i++)
  {
    mvprintw(OFFSET*(i+1), 1 , "%d", i+1);
    mvprintw(OFFSET*(i+1), 25+OFFSET , "%d", i+1);
  }

  for (int i=0; i<columns; i++)
  {
    mvprintw(1, 1+OFFSET*(i+1), "%c", 'A'+i);
    mvprintw(26, 1+OFFSET*(i+1), "%c", 'A'+i);
  }
  refresh_board();
}

void Board::draw_pieces(std::string board)
/** Dessine les pions sur le board de depart **/
{
  clear_board();
  //init_windows();
  box(infos_win,0,0);
  draw_infos();
  stringToBoard(board);
  refresh_board();
}

void Board::draw_alice_pieces(std::string board)
{
  //refresh_board();
  draw_alice_board();
  aliceToBoard(board);
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

void Board::clear_board(){
	for (int line = 0; line < 8; line++){
		for (int column = 0; column < 8; column++){
    			mvprintw((line+1)*OFFSET, 1+((column+1)*OFFSET), "%c", ' ');
		}
	}
	for (int line = 0; line < 8; line++){
		for (int column = 0; column < 8; column++){
    			mvprintw((1+line)*OFFSET, 63+((column+1)*OFFSET), "%c", ' ');
		}
	}
	//refresh_board();
}

void Board::refresh_board()
/** refresh le board (a faire apres chaque modification) **/
{
  wnoutrefresh(stdscr);
  wnoutrefresh(infos_win);
  doupdate();
}


bool Board::isRunning()
{
  return running;
}

std::string Board::get_movement()
{
  int move[4];
  // echo();    // would have been cool but can't clear it without brute force
  for (int i = 0; i < 5; ++i) {
    if (i == 0) {
      mvprintw(15, 30, "%s", "State initial piece position: ");
    }
    else if (i == 2) {
      mvprintw(16, 30, "%s", "State moved piece position: ");
    }
    else if (i == 4) break;
    move[i] = getch();
    mvprintw(15 + (i/2), 60 + (i%2), "%c", move[i]);
  }
  // noecho();
  refresh_board();

  std::string effective_move = moveToString(move);
  // const char* this_move = effective_move.c_str();
  // mvprintw(18, 30, "%s", this_move);
  clear_get_movement();
  return effective_move;
}

void Board::clear_get_movement(){
  mvprintw(15, 30, "%s", "                                ");
  mvprintw(16, 30, "%s", "                                ");
}

std::string Board::get_promotion() {
  mvprintw(15, 30, "%s", "What do you wish to promote your pawn to?");
  mvprintw(16, 30, "%s", "Queen: q   Bishop: b   Knight: h    Rook: r");

  int answer = getch();
  std::string promotion;
  promotion.append(1, answer);
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


void Board::ask_ipos(){
	mvprintw(15, 30, "%s", "State initial piece position: ");
	refresh_board();
}

void Board::print_ipos(int ch, int offset){
	mvprintw(15, 60+offset, "%c", ch);
	refresh_board();
}

void Board::ask_epos(){
	mvprintw(16, 30, "%s", "State moved piece position: ");
	refresh_board();
}

void Board::print_epos(int ch, int offset){
	mvprintw(16, 60+offset, "%c", ch);
	refresh_board();
}

char Board::getchar(){
	return getch();
}


