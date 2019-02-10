#ifndef _CLASSIC_HPP_
#define _CLASSIC_HPP_

#include "Game.hpp"

class Classic : public Game {

	private :

		constexpr void Pieces();

	protected :

		void _initBoard() override;
		void _nextTurn() override;
		bool _isFinish() const override;
		Classic(const Classic&) = delete;

	public :

		constexpr Classic() noexcept : Game(nullptr, 32) {Pieces();}
		virtual ~Classic() noexcept = default;
		Classic& operator=(const Classic&) = delete;
}

constexpr void Pieces() {

	Piece pieces[32];

	pieces[0] = Rook('w', 'A', '1');		//0 -> 7 : pièces fortes blanches
	pieces[1] = Knight('w', 'B', '1');
	pieces[2] = Bishop('w', 'C', '1');
	pieces[3] = Queen('w', 'D', '1');
	pieces[4] = King('w', 'E', '1');
	pieces[5] = Bishop('w', 'F', '1');
	pieces[6] = Knight('w', 'G', '1');
	pieces[7] = Rook('w', 'H', '1');
	pieces[8] = Pawn('w', 'A', '2');		//8 -> 15 : pions blancs
	pieces[9] = Pawn('w', 'B', '2');
	pieces[10] = Pawn('w', 'C', '2');
	pieces[11] = Pawn('w', 'D', '2');
	pieces[12] = Pawn('w', 'E', '2');
	pieces[13] = Pawn('w', 'F', '2');
	pieces[14] = Pawn('w', 'G', '2');
	pieces[15] = Pawn('w', 'H', '2');

	pieces[16] = Rook('b', 'A', '8');		//16 -> 23 : pièces fortes noires
	pieces[17] = Knight('b', 'B', '8');
	pieces[18] = Bishop('b', 'C', '8');
	pieces[19] = Queen('b', 'D', '8');
	pieces[20] = King('b', 'E', '8');
	pieces[21] = Bishop('b', 'F', '8');
	pieces[22] = Knight('b', 'G', '8');
	pieces[23] = Rook('b', 'H', '8');
	pieces[24] = Pawn('b', 'A', '7');		//24 -> 31 : pions noirs
	pieces[25] = Pawn('b', 'B', '7');
	pieces[26] = Pawn('b', 'C', '7');
	pieces[27] = Pawn('b', 'D', '7');
	pieces[28] = Pawn('b', 'E', '7');
	pieces[29] = Pawn('b', 'F', '7');
	pieces[30] = Pawn('b', 'G', '7');
	pieces[31] = Pawn('b', 'H', '7');

	Game::_pieces = pieces;
}

#endif