#include "../include/Include.hpp"

int main() {
	Piece knight("knight", 'B', 0, 0);
	Boards board;

	board.display_board();
	knight.display_info();
	return(0);
}