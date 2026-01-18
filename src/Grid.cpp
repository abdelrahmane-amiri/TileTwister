#include "../include/Grid.hpp"
#include <SDL.h>
#include <cstdlib>
#include <ctime>

Grid::Grid(){
    srand(time(nullptr));
    reset();
    addTiles();
    addTiles();
}

void Grid::reset(){
    for (int i=0; i < SIZE; i++ ){
        for (int j=0; j < SIZE; j++){
            cases[i][j] = 0;
        }
    }
}

void Grid::addTiles(){
    int i, j;
    do {
        i = rand() % 4;
        j = rand() % 4; 
    } while ( cases[i][j] !=0);
    int value = (rand() % 2 == 0) ? 2 : 4;
    cases [i][j] = value; 
}

