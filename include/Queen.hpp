#ifndef QUEEN_H
#define QUEEN_H

#include "Include.hpp"

class Queen : public Piece {
	public:
		Queen(char c, int x, int y)
			: Piece("Queen", c, x, y, (c == 'W') ? "♛" : "♕") {}

		void movements(int new_x, int new_y) override{
			if (new_x >= 8 || new_x < 0 || new_y >= 8 || new_y < 0) {
				std::cout << "\033[1;31mMove out of bound !\033[0m" << std::endl;
				return;
			}
			if (new_x == get_x() || new_y == get_y() || 
				std::abs(new_x - get_x()) == std::abs(new_y - get_y())) {
				Piece::movements(new_x, new_y);
			}
			else {
				std::cout << "\033[1;31mInvalid movement for Queen !\033[0m" << std::endl;
			}
			
		}
};

#endif