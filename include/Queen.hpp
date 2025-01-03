#ifndef QUEEN_H
#define QUEEN_H

#include "Include.hpp"

class Queen : public Piece{

	private:
		std::string icon;

	public:
		Queen(std::string type, char c, int x, int y)
			: Piece("Queen", c, x, y) {
				if (c == 'W')
					icon = "♛";
				else
					icon = "♕";
			}
		void movements(int new_x, int new_y) override{
			if (new_x >= 8 || new_x < 0 || new_y >= 8 || new_y < 0)
				std::cout << "Move out of bound !" << std::endl;
				return;
			if (new_x == get_x() || new_y == get_y())
		}
};


#endif