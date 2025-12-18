#include "../include/Grid.hpp"
#include <SDL.h>

Grid::Grid(){
    reset();
}

void Grid::reset(){

    for (int i=0; i < 4; i++ ){
        for (int j=0; j < 4; j++){
            cases[i][j] = 0;
        }
    }
}