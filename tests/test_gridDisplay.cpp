#include "../include/Display.h"
#include "../include/Grid.hpp"
#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    Display display;
    Grid grid;

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;

            else if (event.type == SDL_KEYDOWN) {
                bool moved = false;
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        moved = grid.moveLeft();
                        break;
                    case SDLK_ESCAPE:
                        running = false;
                        break;
                }
                if (moved) {
                    // La tuile est ajoutée dans moveLeft déjà
                    // Tu peux ici ajouter un son, un score, etc.
                }
            }
        }

        display.reset();
        display.drawGrid();

        for (int row = 0; row < Grid::SIZE; ++row) {
            for (int col = 0; col < Grid::SIZE; ++col) {
                int val = grid.tiles[row][col];
                if (val != 0)
                    display.drawTile(val, row, col);
            }
        }

        display.present();
        SDL_Delay(16);
    }

    TTF_Quit();
    SDL_Quit();

    return 0;
}