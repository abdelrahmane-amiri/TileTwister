#include "Display.h"
#include "Grid.h"
#include <SDL2/SDL.h>
#include <iostream>

Display::Display(){

    window = SDL_CreateWindow(
        "Tiles Twisted",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        windowSize,
        windowSize,
        SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);



}

void Display::reset(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Display::drawGrid(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    int numberCase = 4;
    int sizeCase = 100;

    for (int i = 0; i <= numberCase+1; ++i) {
        int x = i * sizeCase;
        SDL_RenderDrawLine(renderer, x, 100, x, windowSize -100);
    }

    for (int i = 0; i <= numberCase+1; ++i) {
        int y = i* sizeCase;
        SDL_RenderDrawLine(renderer, 100, y, windowSize -100, y);;
    }

    SDL_RenderPresent(renderer);
}

void Display::drawScore(int score, int best){

}

void Display::drawMessage(const std::string& message){

}

