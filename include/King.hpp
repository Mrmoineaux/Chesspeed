#ifndef KING_H
#define KING_H

#include "Include.hpp"

class King : public Piece {

	private:
		std::string icon;

	public:
		King(std::string type, char c, int x, int y) 
			: Piece("King", c, x, y) {
				if (c == 'W')
					icon = "♚";
				else
					icon = "♔";
			}

		void movements(int new_x, int new_y) override{
			if (std::abs(new_x - get_x()) <= 1 && std::abs(new_y - get_y() <= 1))
				Piece::movements(new_x, new_y);
			else
				std::cout << "Invalid movement for king !" << std::endl;
		}

};

#endif