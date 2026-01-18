#pragma once

class Grid{
private:
    static const int SIZE = 4;
    int cases[SIZE][SIZE];
public:
    Grid();
    bool move(char direction);
    void addTiles();
    bool canMove();
    void reset();
};

