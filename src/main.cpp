#include "../include/Include.hpp"

int main() {
	Boards board;
std::cout << "\033[1;31mThis is red and bold text!\033[0m" << std::endl;
	board.display_board();
    King WKing('W', 4, 4);
	std::cout << "\nAfficher les informations du roi :\n";
    // Afficher les informations du roi
    WKing.display_info();
	std::cout << "\nEssayer un mouvement valide (se déplacer d'une case):\n";
    // Essayer un mouvement valide (se déplacer d'une case)
    WKing.movements(5, 5);
    WKing.display_info(); // Vérifie la nouvelle position
	std::cout << "\nEssayer un mouvement invalide (trop loin):\n";
    // Essayer un mouvement invalide (trop loin)
    WKing.movements(7, 7);
    WKing.display_info(); // La position ne devrait pas avoir changé
	return(0);
}