#include "../include/Include.hpp"

int main() {
    App app; // Création de la structure

    init_app(app); // Initialisation
    if (app.running) { // Si l'initialisation a réussi
        main_loop(app); // Lancement de la boucle principale
    }
    cleanup_app(app); // Nettoyage des ressources

    return 0;
}