#ifndef BOARD_H
#define BOARD_H

#include "Include.hpp"

class Boards {
	private :

    std::string board[8][8];

	public:
		Boards() {
			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 8; ++j){
					if ((i + j) % 2 == 0)
						board[i][j] = "⬜️";
					else
						board[i][j] = "⬛️";
				}
			}
		};
		
		void display_board() const{
			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 8; ++j) {
					std::cout << board[i][j] << " ";
				}
				std::cout << "\n";
			}
		}

		std::string get_pos_state(int x, int y) const{
			if (x >= 0 && x < 8 && y >= 0 && y < 8)
				return (board[y][x]);
			else 
				return ("invalid pos");
		}

		void set_pos_value(std::string type, int x, int y) {
			if (x >= 0 && x < 8 && y >= 0 && y < 8) {
				board[y][x] = type;}
			else 
				std::cout << "invalid pos" << std::endl;
		}

	

};

#endif