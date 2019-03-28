#ifndef BOARDPARSE_H
#define BOARDPARSE_H

#include <iostream>
#include <string>
#include <map>

#include "ClientGameControl.hpp"

#include <QIcon>

/*
board sent as list of piece and position, white then black
each piece 3 characters: representation symbol + position in two characters
separation for white and black by !
padding with #
*/
#define CHAR_NUM 3

static std::map<const char, std::string> pieceMap = {
  {'p', "pawn"},
  {'r', "rook"},
  {'h', "knight"},
  {'b', "bishop"},
  {'q', "queen"},
  {'k', "king"}
};

QIcon piece_icon_fetcher(std::string pieceName, std::string colour) {
    //    example path for resource:
    //    :/black_pieces/bishop-black.png
    QString piecePath = QString::fromStdString(":/" + colour + "_pieces/" + pieceName + "-" + colour + ".png");
    QPixmap piecePixmap(piecePath);
    QIcon pieceIcon(piecePixmap);
    return pieceIcon;
}

void convert_piece(ClientGameControl* control, char piece_symbol, char column, char line, std::string colour) {
    std::string currentPieceName = pieceMap[piece_symbol];
    QIcon currentPieceIcon = piece_icon_fetcher(currentPieceName, colour);
    QString currentPiecePosition(column);
    currentPiecePosition += line;
    control->callPieceUpdate(currentPieceIcon, currentPiecePosition, QString::fromStdString(currentPieceName));
}

void stringToBoard(ClientGameControl* control, std::string board_string) {
  unsigned a = 0;
  std::string currentPieceName;
  QIcon currentPieceIcon;
  QString currentPosition;

  std::string colour = "white";
  while (board_string[a] != '!'){
    convert_piece(control, board_string[a], board_string[a+1], board_string[a+2], colour);
    a += CHAR_NUM;
  }
  a += 1;
  colour = "black";
  while (board_string[a] != '#'){
    convert_piece(control, board_string[a], board_string[a+1], board_string[a+2], colour);
    a += CHAR_NUM;
  }
}

//void separateAlicePieces(unsigned a,std::string message,std::string colour) {
//  const char piece = pieceMap[message[a]];
//  Coordinate coor(message[a+1], message[a+2]);
//  int column = coor.getRealColumn();
//  int line = coor.getRealRow();
//  if (colour == "white") {
//    attron(COLOR_PAIR(WHITE_PLAYER));
//    mvprintw((1+line)*OFFSET, 63+((column+1)*OFFSET), "%c", piece);//54
//    attroff(COLOR_PAIR(WHITE_PLAYER));
//  }
//  else {
//    attron(COLOR_PAIR(BLACK_PLAYER));
//    mvprintw((1+line)*OFFSET, 63+((column+1)*OFFSET), "%c", piece);
//    attroff(COLOR_PAIR(BLACK_PLAYER));
//  }
//}

//void aliceToBoard(std::string message) {
//  unsigned int a = 0;
//  std::string colour = "white";
//  while (message[a] != '!'){
//    separateAlicePieces(a, message, colour);
//    a += CHAR_NUM;
//  }
//  a += 1;
//  colour = "black";
//  while (message[a] != '#'){
//    separateAlicePieces(a, message, colour);
//    a += CHAR_NUM;
//  }
//}

#endif
