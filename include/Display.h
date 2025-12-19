#pragma once

#include <SDL2/SDL.h>
#include <string>

class Grid;

class Display {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    const int windowSize = 600;

    const int sizeGrid = 4;
    const int margin = 100;
    const int cellPadding = 15;
    const int spaceDisponible = windowSize - 2 * margin;
    const int cellSize = (spaceDisponible - cellPadding * (sizeGrid + 1)) / sizeGrid;

public:
    Display();

    void present();
    void reset();

    void drawGrid(); //le parametre = const Grid& grid
    void drawTile(int value, int row, int col);
    void drawScore(int score, int best);
    void drawMessage(const std::string& message);
};
