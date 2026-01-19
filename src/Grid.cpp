#include "../include/Grid.hpp"
#include <SDL2/SDL.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <iostream>


Grid::Grid(){
    srand(time(nullptr));
    reset();
    addTiles();
    addTiles();
}

void Grid::reset(){
    for (int i=0; i < SIZE; i++ ){
        for (int j=0; j < SIZE; j++){
            tiles[i][j] = 0;
        }
    }
}

void Grid::addTiles(){
    int i, j;
    do {
        i = rand() % 4;
        j = rand() % 4; 
    } while ( tiles[i][j] !=0);
    int value = (rand() % 2 == 0) ? 2 : 4;
    tiles [i][j] = value; 
}

bool Grid::moveLeft() {
    bool moved = false;
    bool merged[SIZE][SIZE] = { false };

    for (int row = 0; row < SIZE; ++row) {
        for (int col = 1; col < SIZE; ++col) {
            if (tiles[row][col] == 0)
                continue;

            int target = col;
            while (target > 0 && tiles[row][target-1] == 0) {
                tiles[row][target-1] = tiles[row][target];
                tiles[row][target] = 0;
                target--;
                moved = true;
            }

            if (target > 0 && tiles[row][target-1] == tiles[row][target] && !merged[row][target-1]) {
                tiles[row][target-1] *= 2;
                tiles[row][target] = 0;
                merged[row][target-1] = true;
                moved = true;
            }
        }
    }

    if (moved) addTiles();
    return moved;
}

bool Grid::moveRight() {
    bool moved = false;
    bool merged[SIZE][SIZE] = { false };

    for (int row = 0; row < SIZE; ++row) {
        for (int col = SIZE-2; col >= 0; --col) {
            if (tiles[row][col] == 0)
                continue;

            int target = col;
            while (target < SIZE-1 && tiles[row][target+1] == 0) {
                tiles[row][target+1] = tiles[row][target];
                tiles[row][target] = 0;
                target++;
                moved = true;
            }

            if (target < SIZE-1 && tiles[row][target+1] == tiles[row][target] && !merged[row][target+1]) {
                tiles[row][target+1] *= 2;
                tiles[row][target] = 0;
                merged[row][target+1] = true;
                moved = true;
            }
        }
    }

    if (moved) addTiles();
    return moved;
}

bool Grid::moveUp() {
    bool moved = false;
    bool merged[SIZE][SIZE] = { false };

    for (int col = 0; col < SIZE; ++col) {
        for (int row = 1; row < SIZE; ++row) {
            if (tiles[row][col] == 0)
                continue;

            int target = row;
            while (target > 0 && tiles[target-1][col] == 0) {
                tiles[target-1][col] = tiles[target][col];
                tiles[target][col] = 0;
                target--;
                moved = true;
            }

            if (target > 0 && tiles[target-1][col] == tiles[target][col] && !merged[target-1][col]) {
                tiles[target-1][col] *= 2;
                tiles[target][col] = 0;
                merged[target-1][col] = true;
                moved = true;
            }
        }
    }

    if (moved) addTiles();
    return moved;
}

bool Grid::moveDown() {
    bool moved = false;
    bool merged[SIZE][SIZE] = { false };

    for (int col = 0; col < SIZE; ++col) {
        for (int row = SIZE-2; row >= 0; --row) {
            if (tiles[row][col] == 0)
                continue;

            int target = row;
            while (target < SIZE-1 && tiles[target+1][col] == 0) {
                tiles[target+1][col] = tiles[target][col];
                tiles[target][col] = 0;
                target++;
                moved = true;
            }

            if (target < SIZE-1 && tiles[target+1][col] == tiles[target][col] && !merged[target+1][col]) {
                tiles[target+1][col] *= 2;
                tiles[target][col] = 0;
                merged[target+1][col] = true;
                moved = true;
            }
        }
    }

    if (moved) addTiles();
    return moved;
}