#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "Display.h"
#include <iostream>
#include <filesystem>


int main() {
    SDL_Init(SDL_INIT_VIDEO);
    Display display;

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        display.reset();
        display.drawGrid();

        display.drawTile(16, 1, 1);
        display.drawTile(32, 2, 0);
        display.drawTile(64, 0, 0);
        display.drawTile(128, 2, 2);
        display.drawScore(20,20);
        display.present();

        SDL_Delay(30);
    }

    SDL_Quit();
    return 0;
}
