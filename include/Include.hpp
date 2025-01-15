#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <string>

#include "SDL2/SDL.h"
#include "Piece.hpp"
#include "Board.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"

// Dimensions de la fenêtre
#define SCREEN_WIDTH   800
#define SCREEN_HEIGHT  800

// Structure pour regrouper les ressources de l'application
struct App {
    SDL_Window* window = nullptr;      // Pointeur vers la fenêtre
    SDL_Renderer* renderer = nullptr; // Pointeur vers le renderer
    bool running = true;              // Indicateur pour la boucle principale
	Boards boards;
};

// Prototypes de fonctions
void init_app(App& app); // Initialisation des ressources
void cleanup_app(App& app); // Libération des ressources
void main_loop(App& app); // Boucle principale
void init_windows(); // Initialisation de la fenetre

#endif