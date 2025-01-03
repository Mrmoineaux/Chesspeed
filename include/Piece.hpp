#ifndef PIECE_H
#define PIECE_H

#include "Include.hpp"

class Piece {

	private:
		std::string type; //piece type
		char color; //W = white and B = black
		int pos_x, pos_y; //piece position
		std::string icon; //icon of the piece
	public:
		//constructor
		Piece(std::string t, char c, int x, int y, std::string i)
			:type(t), color(c), pos_x(x), pos_y(y) , icon(i){}

		// display info fonction
		void display_info() const{
			std::cout << "\033[31mtype\033[0m = [" << type << "], " << "\n";
			std::cout << "\033[33mtype\033[0m = [" << icon << "], " << "\n";
			std::cout << "\033[32mcolor\033[0m = [" << color << "]," << "\n";
			std::cout << "\033[34mposition\033[0m x, y = [" << pos_x << ", " << pos_y << "]\n";
		}

		// movements fonction
		virtual void movements(int new_x, int new_y) {
			pos_x = new_x;
			pos_y = new_y;
		}
		
		// get info fonctions
		virtual std::string get_type() const{
			return (type);
		}
		virtual char get_color() const{
			return (color);
		}
		virtual int get_x() const{
			return (pos_x);
		}
		virtual int get_y() const{
			return(pos_y);
		}
		virtual std::string get_icon() const{
			return (icon);
		}
};

#endif