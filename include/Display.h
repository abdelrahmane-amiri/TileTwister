#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class Grid;

class Display {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;

    const int windowSize = 600;

    const int sizeGrid = 4;
    const int margin = 100;
    const int cellPadding = 15;
    const int disponible = windowSize - 2 * margin;
    const int cellSize = (disponible - cellPadding * (sizeGrid + 1)) / sizeGrid;

public:
    Display();

    void present();
    void reset();

    void drawGrid(); //le parametre = const Grid& grid
    void drawTile(int value, int row, int col);
    void drawScore(int score, int best);
    void drawMessage(const std::string& message);
};
