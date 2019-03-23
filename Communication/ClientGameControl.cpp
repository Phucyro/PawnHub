#include <sys/select.h>
#include <unistd.h>
#include "ClientGameControl.hpp"
#define TIMER_UPDATE_RATE 1000000 //microsecond

std::string moveToString(int*);

ClientGameControl::ClientGameControl(Socket& _socket): board(), socket(_socket), game_ongoing(true), is_alice(false), is_real_time(false), _color('\0'), timer() {
  startParty();
}

void ClientGameControl::receiveBoard(std::string message) {
  if (!is_alice) {
    board.draw_pieces(message);
    board.refresh_board();
  }
  else if (message[0] == '1') {
    board.draw_pieces(message.erase(0,1));
  }
  else {
    board.draw_alice_pieces(message.erase(0,1));
    board.refresh_board();
  }
}

void ClientGameControl::receiveUpdate(std::string message) {
  if (message == "start") {
    board.init_ncurses();
  }
  else if (message == "alice") {
    is_alice = true;
    board.draw_alice_board();
  }
  else if (message == "realtime") {
    is_real_time = true;
  }
  else if (message == "check") {
    board.declare_check();
  }
  else {
    game_ongoing = false;
    if (message == "stalemate") {
      message = "Stalemate !";
    }
    else if (message == "surrend") {
      message = "You win: your oppenent gave up !";
    }
    else if (message == "timeout") {
      message = "You win: your oppenent ran out of time !";
    }
    else if (message == "white"){
      message = "Checkmate: white player won !";
    }
    else {
      message = "Checkmate: black player won !";
    }
    board.endgame(message.c_str());
  }
}

void ClientGameControl::receiveGameMode(std::string message) {
  board.set_mode(message);
  board.refresh_board();
}

void ClientGameControl::receivePlayerColour(std::string message) {
  _color = message[0];
  board.set_colour(message);
  board.refresh_board();
}

void ClientGameControl::receiveTurn(std::string message) {
  const char* msg = message.c_str();
  board.update_turn(msg);
}

void ClientGameControl::receiveTime(std::string message) {
	int time = atoi(message.c_str());
	if (time < 0) board.show_time_left(std::string("-"));
	else{
		timer.reset(time);
		board.show_time_left(timer);
	}
}

void ClientGameControl::receiveAskMove(std::string message) {
	struct timeval updateRate;
	int move[4], i = 0, newch = STDIN_FILENO;
	fd_set read;
	std::string effective_move;
	int timeLeft = timer.get_remaining_time();
	
	board.ask_ipos();
	timer.start();
	timer.unpause();
	
  while (i < 4 && timeLeft){
  	updateRate.tv_sec = int(TIMER_UPDATE_RATE / 1000000);
  	updateRate.tv_usec = int(TIMER_UPDATE_RATE % 1000000);
  	FD_ZERO(&read);
		FD_SET(newch, &read);
		if (select(newch+1, &read, nullptr, nullptr, &updateRate) == -1) throw std::runtime_error("Select failed");
		timeLeft = timer.get_remaining_time();
		
		if (FD_ISSET(newch, &read)){
			move[i] = board.getchar();
			if (i < 2) board.print_ipos(move[i], i);
			else board.print_epos(move[i], i%2);
			i++;
			if (i == 2) board.ask_epos();
			else if (i == 4){
				board.clear_get_movement();
				effective_move = moveToString(move);
			}
		}
		board.show_time_left(timer);
  }
  if (!timeLeft){
  	effective_move = "/tim";
  	sendMove(effective_move);
  	game_ongoing = false;
  	board.clear_get_movement();
  	board.endgame("Time out! You lost.");
  }
  
  if (game_ongoing){
    sendMove(effective_move);
    if (effective_move == "/end"){
      game_ongoing = false;
      board.clear_get_movement();
      board.endgame("You gave up.");
    }
  }
}

void ClientGameControl::receiveGoodMove(std::string message) {
	timer.pause();
	board.show_time_left(timer);
}


void ClientGameControl::receiveAskPromotion(std::string message) {
  std::string promotion = board.get_promotion();
  sendPromotion(promotion);
}

void ClientGameControl::sendMove(std::string move) {
  std::string header = headerSendMap["move"];
  socket.sendMessage("30~" + header + _color + move);
}

void ClientGameControl::sendPromotion(std::string promotion) {
  std::string header = headerSendMap["promote"];
  socket.sendMessage("30~" + header + promotion);
}

void ClientGameControl::receiveFirstMessage(std::string){
	//just here to be sure no one use the F as header.
	//can be used to do something just after the clean up.
}

void ClientGameControl::handleMessage() {
  if (is_real_time) listenSocketAndKeyboard();
  else{
  	std::string message = socket.receiveMessage();
  	char header = message[0];
  	(this->*(headerReceiveMap[header]))(message.erase(0,1));
  }
}

void ClientGameControl::listenSocketAndKeyboard(){
	int move[4], i = 0, sockfd = socket.getFileDescriptor(), newch = STDIN_FILENO;
	int nfd = sockfd < STDIN_FILENO ? STDIN_FILENO+1 : sockfd+1;
	fd_set read;
	std::string effective_move;
	board.ask_ipos();
	while(game_ongoing){
		FD_ZERO(&read);
		FD_SET(sockfd, &read);
		FD_SET(newch, &read);
		if (select(nfd, &read, nullptr, nullptr, nullptr) == -1) throw std::runtime_error("Select failed");
		if (FD_ISSET(sockfd, &read)){
			std::string message = socket.receiveMessage();
  			char header = message[0];
  			(this->*(headerReceiveMap[header]))(message.erase(0,1));
		}
		if(FD_ISSET(newch, &read)){
			move[i] = board.getchar();
			if (i < 2) board.print_ipos(move[i], i);
			else board.print_epos(move[i], i%2);
			i++;
			if (i == 2) board.ask_epos();
			else if (i == 4){
				board.clear_get_movement();
				effective_move = moveToString(move);
				sendMove(effective_move);
				i=0;
				board.ask_ipos();
				if (effective_move == "/end"){
      					game_ongoing = false;
      					board.endgame("You gave up.");
    				}
			}
		}
	}
}

void ClientGameControl::cleanOldMsg(){
	// to avoid message from previous game to break everything
	bool firstMsgRecv = false;
	std::string message;
	while (!firstMsgRecv){
		message = socket.receiveMessage();
  	if(message[0] == 'F'){
  		firstMsgRecv = true;
  		char header = message[0];
  	  (this->*(headerReceiveMap[header]))(message.erase(0,1));
  	}
  }
}

void ClientGameControl::startParty() {
  game_ongoing = true;
  cleanOldMsg();
  while(game_ongoing) {handleMessage();}
  board.exit();
}
