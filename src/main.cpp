#include "../include/Include.hpp"

int main() {
	Boards board;
	std::cout << "\033[1;31mThis is red and bold text!\033[0m" << std::endl;
	board.display_board();
	std::cout << "\033[1;31mThis is red and bold text!\033[0m" << std::endl;
    King WKing('W', 4, 4);
	board.set_pos_value(WKing.get_icon(), WKing.get_x(), WKing.get_y());
	board.display_board();
	return(0);
}