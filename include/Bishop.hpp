#ifndef BISHOP_H
#define BISHOP_H

#include "Include.hpp"

class Bishop : public Piece {
	public:
		Bishop(char c, int x, int y)
			: Piece("Bishop", c, x, y, (c == 'W') ? "♝" : "♗") {}
		void movements(int new_x, int new_y) override{
			if (new_x >= 8 || new_x < 0 || new_y >= 8 || new_y < 0) {
				std::cout << "\033[1;31mMove out of bound !\033[0m" << std::endl;
				return;
			}
			if (std::abs(new_x - get_x()) == std::abs(new_x - get_y())) {
				Piece::movements(new_x, new_y);
			}
			else {
				std::cout << "\033[1;31mInvalid movement for Bishop !\033[0m" << std::endl;
			}
		}
};

#endif