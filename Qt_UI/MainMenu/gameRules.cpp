#include "gameRules.h"
#include "ui_gameRules.h"

GameRules::GameRules(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameRules)
{
    ui->setupUi(this);
}

GameRules::~GameRules()
{
    delete ui;
}


void GameRules::on_classicPushButton_pressed()
{
    ui->rulesTextEdit->clear();
    ui->rulesTextEdit->appendPlainText("The player controlling the white pieces is named 'White'; the player controlling the black pieces is named 'Black'. White moves first, then players alternate moves. Making a move is required; it is not legal to skip a move, even when having to move is detrimental. Play continues until a king is checkmated, a player resigns, or a draw is declared, as explained below.");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("Each type of chess piece has its own method of movement. A piece moves to a vacant square except when capturing an opponent's piece.");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("Except for any move of the knight and castling, pieces cannot jump over other pieces. A piece is captured (or taken) when an attacking enemy piece replaces it on its square (en passant is the only exception). The captured piece is thereby permanently removed from the game.The king can be put in check but cannot be captured (see below).");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("The king moves exactly one square horizontally, vertically, or diagonally. A special move with the king known as castling is allowed only once per player, per game (see below).");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("A rook moves any number of vacant squares in a horizontal or vertical direction. It also is moved when castling.");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("A bishop moves any number of vacant squares in any diagonal direction.");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("The queen moves any number of vacant squares in a horizontal, vertical, or diagonal direction.");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("A knight moves to the nearest square not on the same rank, file, or diagonal. (This can be thought of as moving two squares horizontally then one square vertically, or moving one square horizontally then two squares vertically—i.e. in an 'L' pattern.) The knight is not blocked by other pieces: it jumps to the new location.");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("A pawn moves straight forward one square, if that square is vacant. If it has not yet moved, a pawn also has the option of moving two squares straight forward, provided both squares are vacant. Pawns cannot move backwards.");
    ui->rulesTextEdit->appendPlainText("Pawns are the only pieces that capture differently from how they move. A pawn can capture an enemy piece on either of the two squares diagonally in front of the pawn (but cannot move to those squares if they are vacant).");
    ui->rulesTextEdit->appendPlainText("The pawn is also involved in the two special moves en passant and promotion");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("For more info :");
    ui->rulesTextEdit->appendHtml("https://en.wikipedia.org/wiki/Rules_of_chess");
}

void GameRules::on_darkPushButton_pressed()
{
    ui->rulesTextEdit->clear();
    ui->rulesTextEdit->appendPlainText("The goal of this chess variant is not to checkmate the king, but to capture it. A player is not told if their king is in check. Failing to move out of check, or moving into check, are both legal, and can obviously result in a capture and loss of the game.");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("Each player views a different version of the board, on which they can only see their own pieces, and the squares where these pieces can legally move, as well as any opponent pieces on those squares (which must therefore be capturable). It is indicated to the player which squares are hidden, so a hidden square can never be confused with a visible empty square. As an example, it is always clear when an enemy piece is directly in front of a pawn, because that square will be hidden (as capturing it is not a legal move for the pawn to make).");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("En passant capture is allowed, the threatened pawn and the square it moved through are both visible to the capturing player, but only until the end of the turn. Unlike standard chess, castling is allowed out of check, into check, and through the positions attacked by enemy pieces. ");
}

void GameRules::on_hordePushButton_pressed()
{
    ui->rulesTextEdit->clear();
    ui->rulesTextEdit->appendPlainText("This chess variation differs from the other variations at the first glance. White plays with the normal set of chess pieces, black has only a horde of 32 pawns located exactly as shown at the following picture.");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("The rules are the same as for normal chess with these differences:");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("White wins if he/she captures all black pieces. Black wins if he/she checkmates the white king.");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("If no black piece can make a valid move, the game is a draw (stalemate).");
    ui->rulesTextEdit->appendPlainText("Black pawns can be promoted to a black queen, rook, bishop or knight if they reach the last row (from black's point of view).");
    ui->rulesTextEdit->appendPlainText("Black pawns cannot move two spaces forward from any position except the second rank (from black's point of view).");
}

void GameRules::on_alicePushButton_pressed()
{
    ui->rulesTextEdit->clear();
    ui->rulesTextEdit->appendPlainText("Pieces move the same as they do in standard chess, but a piece transfers at the completion of its move to the opposite board. This simple change has dramatic impact on gameplay.");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("At the beginning of the game, pieces start in their normal positions on board A, while board B starts empty. After each move is made on a given board, the moved piece is transferred (goes 'through the looking-glass') to the corresponding square on the opposite board. (So, if a piece is moved on board A, it is transferred to board B at the completion of its move; if the piece started on board B, it ends up on board A.) ");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("For more info :");
    ui->rulesTextEdit->appendHtml("https://en.wikipedia.org/wiki/Alice_Chess");

}

void GameRules::on_realTimePushButton_pressed()
{
    ui->rulesTextEdit->clear();
    ui->rulesTextEdit->appendPlainText("The rules are the same as for Classic but we add the realtime on top of it.");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("It's not turnbased, you may move any piece at any time");
    ui->rulesTextEdit->appendPlainText("Your pawn will always promote to a Queen");
    ui->rulesTextEdit->appendPlainText("There is no check or checkmate, you can move your King where you want and when you want, and you can castle disregarding the check rule.");
    ui->rulesTextEdit->appendPlainText("There are no autodraws or claimed draws based on repetion of moves or number of moves");
    ui->rulesTextEdit->appendPlainText("");
    ui->rulesTextEdit->appendPlainText("You cannot move a piece, if it has a delaytime.");
    ui->rulesTextEdit->appendPlainText("If any piece is moving to the field X.You cannot move a piece to the same field X. - Same destination blocking");
    ui->rulesTextEdit->appendPlainText("If an opponent piece has started a move to a field Y before you. You cannot start a move of your piece X to a path through that field Y. - Move blocking This rule is ignored if and only if the piece X is a knight, they jump.");
    ui->rulesTextEdit->appendPlainText("You may move your piece X through your own piece Y, if it's already moving. Only if the piece X's destination doesn't go though the piece Y's destination. This rule is ignored if and only if the piece X is a knight, they jump.");
    ui->rulesTextEdit->appendPlainText("You can only do the enpassant move if the opponent pawn still has a delaytime");
    ui->rulesTextEdit->appendPlainText("When it's possible to capture two pieces by enpassant move and a normal capture by the same pawn, the enpassant capture will not happen");
    ui->rulesTextEdit->appendPlainText("When a King is taken the owner of that King loses the game. When a player resigns og leaves the game, that player loses the game.");

}

void GameRules::on_returnPushButton_pressed()
{
    close();
}

