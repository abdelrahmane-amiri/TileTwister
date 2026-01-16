#include "Display.h"
#include "Grid.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
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

void Display::present() {
    SDL_RenderPresent(renderer);
}


void Display::reset(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Display::drawGrid(){

    SDL_SetRenderDrawColor(renderer, 250, 248, 239, 255);
    SDL_RenderClear(renderer);
    
    SDL_Rect gridBg = {margin, margin, spaceDisponible, spaceDisponible};
    SDL_SetRenderDrawColor(renderer, 187, 173, 160, 255);
    SDL_RenderFillRect(renderer, &gridBg);
    
    SDL_SetRenderDrawColor(renderer, 205, 193, 180, 255);
    for (int row = 0; row < sizeGrid; ++row) {
        for (int col = 0; col < sizeGrid; ++col) {
            SDL_Rect cell = {
                margin + cellPadding + col * (cellSize + cellPadding),
                margin + cellPadding + row * (cellSize + cellPadding),
                cellSize,
                cellSize
            };
            SDL_RenderFillRect(renderer, &cell);
        }
    }
    
    SDL_RenderPresent(renderer);
}

void Display::drawTile(int value, int row, int col) {

    SDL_Rect tile = {
        margin + cellPadding + col * (cellSize + cellPadding),
        margin + cellPadding + row * (cellSize + cellPadding),
        cellSize,
        cellSize
    };

    switch (value)
    {
        case 2:
            SDL_SetRenderDrawColor(renderer, 238, 228, 218, 255);
            break;

        case 4:
            SDL_SetRenderDrawColor(renderer, 237, 224, 200, 255);
            break;

        case 8:
            SDL_SetRenderDrawColor(renderer, 242, 177, 121, 255);
            break;

        case 16:
            SDL_SetRenderDrawColor(renderer, 245, 149, 99, 255);
            break;

        case 32:
            SDL_SetRenderDrawColor(renderer, 246, 124, 95, 255);
            break;

        case 64:
            SDL_SetRenderDrawColor(renderer, 246, 94, 59, 255);
            break;

        case 128:
            SDL_SetRenderDrawColor(renderer, 237, 207, 114, 255);
            break;

        case 256:
            SDL_SetRenderDrawColor(renderer, 237, 204, 97, 255);
            break;

        case 512:
            SDL_SetRenderDrawColor(renderer, 237, 200, 80, 255);
            break;

        case 1024:
            SDL_SetRenderDrawColor(renderer, 237, 197, 63, 255);
            break;

        case 2048:
            SDL_SetRenderDrawColor(renderer, 237, 194, 46, 255);
            break;

        default:
            SDL_SetRenderDrawColor(renderer, 205, 193, 180, 255);
            break;
            }

    //SDL_SetRenderDrawColor(renderer, 238, 228, 218, 255);
    SDL_RenderFillRect(renderer, &tile);
}


void Display::drawScore(int score, int best){

}

void Display::drawMessage(const std::string& message){

}

