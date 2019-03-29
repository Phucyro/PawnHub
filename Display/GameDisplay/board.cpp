#include "board.hpp"
#include "BoardParsing.hpp"
#include "MoveParsing.hpp"

Board::Board(): infos_win(nullptr), columns(BOARD_COLS), lines(BOARD_LINES), running(false), mode(), colour()
{

}


Board::Board(int line_count, int col_count): infos_win(nullptr), columns(col_count), lines(line_count), running(false), mode(), colour()
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
  init_pair(BLACK_PLAYER, COLOR_CYAN, COLOR_BLACK);

  init_windows();
}


void Board::init_windows()
/**Initialise le board**/
{
  int board_height = (lines+1)*OFFSET;
  int board_width = (columns+1)*OFFSET;

  infos_win = newwin(board_height/2 + 3, board_width+2, 0, board_width+5);
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

    if (colour == "black")
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
    }

    else if (colour == "white")
    {
        for (int i=0; i<lines; i++)
        {
            mvprintw(OFFSET*(i+1), 63, "%d", 8-i);
            mvprintw(OFFSET*(i+1), 63+25+OFFSET , "%d", 8-i);//54
        }

        for (int i=0; i<columns; i++)
        {
            mvprintw(26, 66+(OFFSET*i), "%c", 'H'-i);//57
            mvprintw(1, 66+(OFFSET*i), "%c", 'H'-i);
        }
    }


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



}


void Board::draw_infos()
/** Initialise la fenetre des infos **/
{
  int x_win, y_win;
  getmaxyx(infos_win, y_win, x_win);

  mvwprintw(infos_win, 1, 1, "GAME MODE : %s", mode.c_str());

  mvwprintw(infos_win, 4, 1, "YOUR COLOUR : %s", colour.c_str());

  mvwprintw(infos_win , 7, 1, "%s", "TURN COUNT : ");
  
  mvwprintw(infos_win , 10, 1, "%s", "TIME LEFT : ");

  mvwprintw(infos_win , 13, 1, "ENTER /end TO SURREND");

}

void Board::set_mode(const std::string& game) {
  mode = game;
}

void Board::set_colour(const std::string& player_colour) {
  colour = player_colour;
}

void Board::update_turn(const char* turn) {
  mvwprintw(infos_win, 7, 14, "%s", turn);
}

void Board::show_time_left(const std::string& time)
{
  mvwprintw(infos_win,10, 13,time.c_str());
  refresh();
  wrefresh(infos_win);
}

void Board::declare_check() {
  mvprintw(20, 30, "%s", "CHECK");
  refresh_board();
}

void Board::endgame(const char* message) {
  clear_premove();
  mvprintw(18, 30, "%s", message);
  refresh_board();
  getch();
}

void Board::draw_coordinates()
/** Initialise les coordonnees X et Y du board **/
{

  //print les chiffres du board en fonction de la couleur
  if (colour == "black")
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
  }

  else if (colour == "white")
  {
    for (int i=0; i<lines; i++)
    {
      mvprintw(OFFSET*(i+1), 1 , "%d", 8-i);
      mvprintw(OFFSET*(i+1), 25+OFFSET , "%d", 8-i);
    }

    for (int i=0; i<columns; i++)
    {
        mvprintw(1, 1+OFFSET*(i+1), "%c", 'H'-i);
        mvprintw(26, 1+OFFSET*(i+1), "%c", 'H'-i);
    }
  }


}

void Board::draw_pieces(std::string board)
/** Dessine les pions sur le board de depart **/
{
  clear_board();
  box(infos_win,0,0);
  draw_infos();
  stringToBoard(board,colour);
}

void Board::draw_alice_pieces(std::string board)
{
  draw_alice_board();
  aliceToBoard(board, colour);
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
  for (int i = 0; i < 5; ++i) {
    if (i == 0) {
      mvprintw(18, 30, "%s", "State initial piece position: ");
    }
    else if (i == 2) {
      mvprintw(19, 30, "%s", "State moved piece position: ");
    }
    else if (i == 4) break;
    move[i] = getch();
    mvprintw(18 + (i/2), 60 + (i%2), "%c", move[i]);
  }
  refresh_board();

  std::string effective_move = moveToString(move);
  clear_get_movement();
  return effective_move;
}

void Board::clear_get_movement(){
  mvprintw(18, 30, "%s", "                                 ");
  mvprintw(19, 30, "%s", "                                 ");
}

std::string Board::get_promotion() {
  mvprintw(18, 30, "%s", "What do you wish to promote your pawn to?");
  mvprintw(19, 30, "%s", "Queen: q   Bishop: b   Knight: h    Rook: r");

  int answer = getch();
  std::string promotion;
  promotion.append(1, answer);
  mvprintw(18, 30, "%s", "                                         ");
  mvprintw(19, 30, "%s", "                                           ");
  return promotion;
}

void Board::exit()
{
  delwin(infos_win);

  endwin();
}

void Board::change_mode(const std::string& mode)
{
  mvwprintw(infos_win,1,13,mode.c_str());
  refresh();
  wrefresh(infos_win);
}

void Board::change_last_move(const std::string& move)
{
  mvwprintw(infos_win,4,13,move.c_str());
  refresh();
  wrefresh(infos_win);
}

void Board::change_turn(const std::string& turn)
{
  mvwprintw(infos_win,7,8,turn.c_str());
  refresh();
  wrefresh(infos_win);
}

void Board::ask_ipos(){
	mvprintw(18, 30, "%s", "State initial piece position: ");
	refresh_board();
}

void Board::print_ipos(int ch, int offset){
	mvprintw(18, 60+offset, "%c", ch);
	refresh_board();
}

void Board::ask_epos(){
	mvprintw(19, 30, "%s", "State moved piece position: ");
	refresh_board();
}

void Board::print_epos(int ch, int offset){
	mvprintw(19, 60+offset, "%c", ch);
	refresh_board();
}

void Board::print_premove(){
	mvprintw(17, 30, "%s", "Premove:");
	Board::ask_ipos();
	refresh_board();
}

void Board::print_your_turn(){
	mvprintw(17, 30, "%s", "Your turn:");
	Board::ask_ipos();
	refresh_board();
}

void Board::clear_premove(){
	mvprintw(17, 30, "%s", "          ");
	clear_get_movement();
	refresh_board();
}

char Board::getchar(){
	return getch();
}


