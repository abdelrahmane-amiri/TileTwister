#pragma once

#include <SDL2/SDL.h>
#include <string>

class Grid;

class Display {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    const int windowSize = 500;

public:
    Display();

    void drawGrid(const Grid& grid);
    void drawScore(int score, int best);
    void drawMessage(const std::string& message);
};
