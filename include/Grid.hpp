#pragma once

class Grid{
private:
    int cases[4][4];
    
public: 
    bool move(char direction);
    void addTiles();
    bool canMove();
    void reset();
};

