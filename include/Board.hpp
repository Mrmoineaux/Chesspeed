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
						board[i][j] = "◼︎";
					else
						board[i][j] = "◻︎";
				}
			}
		};
		
		void display_board() const{
			for (int i = 0; i <= 17; ++i) {
				if (i == 0)
					std::cout << " ╔";
				else
					std::cout << "═";
			}
			std::cout << "╗";
			std::cout << "\n";
			for (int i = 0; i < 8; ++i) {
				std::cout << "\033[1;31m" << 8 - i << "\033[0m║ ";
				for (int j = 0; j < 8; ++j) {
					std::cout << board[i][j] << " ";
				}
				std::cout << "║";
				std::cout << "\n";
			}
			for (int i = 0; i <= 17; ++i) {
				if (i == 0)
					std::cout << " ╚";
				else
					std::cout << "═";
			}
			std::cout << "╝";
			std::cout << "\n";
			for (int i = 0; i <= 8; ++i) {
				if (i == 0)
					std::cout << "   ";
				else
					std::cout << "\033[1;31m" << i << "\033[0m ";
			}
			std::cout << "\n";
		}

		std::string get_pos_state(int x, int y) const{
			if (x >= 0 && x < 8 && y >= 0 && y < 8)
				return (board[y][x]);
			else 
				return ("invalid pos");
		}

		void set_pos_value(std::string icon, int x, int y) {
			if (x >= 0 && x < 8 && y >= 0 && y < 8) {
				board[y][x] = icon;}
			else 
				std::cout << "invalid pos" << std::endl;
		}

		void render_board(SDL_Renderer* renderer) {
			const int square_size = 100; // Taille d'une case
			SDL_Color dark_square = {0, 0, 0, 255}; // Couleur des cases noires
			SDL_Color light_square = {255, 255, 255, 255}; // Couleur des cases blanches

			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 8; ++j) {
					// Déterminer la couleur de la case
					SDL_Color color = (i + j) % 2 == 0 ? light_square : dark_square;
					SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

					// Définir la position et la taille de la case
					SDL_Rect square = {j * square_size, i * square_size, square_size, square_size};
					SDL_RenderFillRect(renderer, &square);
				}
			}
		}
};

#endif