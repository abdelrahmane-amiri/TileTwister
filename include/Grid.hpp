#pragma once

class Grid {
private:
    static const int SIZE = 4;

public:
    Grid();

    int tiles[SIZE][SIZE];

    bool move(char direction);
    void print();
    
    bool moveLeft();
    bool moveRight();
    bool moveUp();
    bool moveDown();

    void addTiles();
    bool canMove();
    void reset();
};
