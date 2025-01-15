#include "../include/Include.hpp"

void main_loop(App& app) {
    SDL_Event event;

    while (app.running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                app.running = false;
            }
        }

        // Effacer l'écran
        SDL_SetRenderDrawColor(app.renderer, 50, 50, 50, 255);
        SDL_RenderClear(app.renderer);

        // Dessiner le plateau
        app.boards.render_board(app.renderer);

        // Afficher à l'écran
        SDL_RenderPresent(app.renderer);
    }
}

void cleanup_app(App& app) {
    if (app.renderer) {
        SDL_DestroyRenderer(app.renderer);
    }
    if (app.window) {
        SDL_DestroyWindow(app.window);
    }
    SDL_Quit();
}

void init_app(App& app) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << "\n";
        app.running = false; // Arrête l'application en cas d'erreur
        return;
    }

    // Création de la fenêtre
    app.window = SDL_CreateWindow("SDL2 Application", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!app.window) {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << "\n";
        app.running = false;
        SDL_Quit();
        return;
    }

    // Création du renderer
    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
    if (!app.renderer) {
        std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        app.running = false;
        return;
    }
}