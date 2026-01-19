#pragma once

class Grid {
private:


public:
    Grid();

    static const int SIZE = 4;
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
