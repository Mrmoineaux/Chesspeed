#ifndef KING_H
#define KING_H

#include "Include.hpp"

class King : public Piece {

	public:
		King(char c, int x, int y) 
			: Piece("King", c, x, y, (c == 'W') ? "♚" : "♔") {}

	void movements(int new_x, int new_y) override {
    	if (new_x >= 8 || new_x < 0 || new_y >= 8 || new_y < 0) {
        	std::cout << "\033[1;31mMove out of bound !\033[0m" << std::endl;
        	return;
    	}
    	if (std::abs(new_x - get_x()) <= 1 && std::abs(new_y - get_y()) <= 1) {
    	    Piece::movements(new_x, new_y);
    	}
		else {
    	    std::cout << "\033[1;31mInvalid movement for King !\033[0m" << std::endl;
    	}
	}
};

#endif