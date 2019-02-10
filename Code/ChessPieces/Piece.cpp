#ifdef  __PIECE__CPP__
#define __PIECE__CPP__

Piece& Piece::operator= (const Piece& original){
	_color = original._color;
	_coords = original._coords;
	_isTaken = original._isTaken;
	for (int i = 0; i < 4; i++){
				_str[i] = original._str[i];
			}
			return *this;
}

Piece& Piece::operator= (Piece&&){
	_color = original._color;
	_coords = original._coords;
	_isTaken = original._isTaken;
	_str = original._str;
	original._str = nullptr;
	return *this;
}


bool Piece::move(Coordinate end, Board* board, Game game){
/*Move this piece to the correct location on the board and return true if the move is possible. Else return false and leave the board unchanged*/
	if(this->_checkMove()){
		Piece *takenPiece;
		takenPiece = board->movePiece(_coords, end);
		takenPiece.changeIsTaken();
		
		if(game.testCheck()){
			board->movePiece(end, _coords);
			board->setCase(end, takenPiece);
			takenPiece.changeIsTaken();
			return false;
		}
		else{
			_coords = end;
			return true;
		}
	}
}

#endif
