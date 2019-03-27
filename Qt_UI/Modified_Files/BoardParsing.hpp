#ifndef BOARDPARSE_H
#define BOARDPARSE_H

#include <iostream>
#include <string>
#include <map>
#include "../../Code/Coordinate.hpp"

#include <QIcon>

#include "../MainMenu/gameWithoutChat.h"

/*
board sent as list of piece and position, white then black
each piece 3 characters: representation symbol + position in two characters
separation for white and black by !
padding with #
*/
#define CHAR_NUM 3

std::map<const char, std::string> pieceMap = {
  {'p', "pawn"},
  {'r', "rook"},
  {'h', "knight"},
  {'b', "bishop"},
  {'q', "queen"},
  {'k', "king"}
};

QIcon piece_icon_fetcher(std::string pieceName, std::string colour) {
    QString piecePath = QString::fromStdString("./" + pieceName + "-" + colour + ".png");
    QPixmap piecePixmap(piecePath);
    QIcon pieceIcon(piecePixmap);
    return pieceIcon;
}

//void stringToBoard(GameWithoutChat* game, std::string message) {
//  unsigned a = 0;
//  std::string currentPieceName;
//  QIcon currentPieceIcon;
//  QString currentPosition;

//  std::string colour = "white";
//  while (message[a] != '!'){
//    currentPieceName = pieceMap[a];
//    currentPieceIcon = piece_icon_fetcher(currentPieceName, colour);
//    currentPosition = message[a+1] + message[a+2];
//    game->set_piece(currentPieceIcon, currentPosition, QString::fromStdString(currentPieceName));
//    a += CHAR_NUM;
//  }
//  a += 1;
//  colour = "black";
//  while (message[a] != '#'){
//    currentPieceName = pieceMap[a];
//    currentPieceIcon = piece_icon_fetcher(currentPieceName, colour);
//    currentPosition = message[a+1] + message[a+2];
//    game->set_piece(currentPieceIcon, currentPosition, QString::fromStdString(currentPieceName));
//    a += CHAR_NUM;
//  }
//}

void separateAlicePieces(unsigned a,std::string message,std::string colour) {
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
}

#endif
