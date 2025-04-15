#pragma once  
#include "Wall.h"  

class Level {  
private:  
    Wall** walls; // Dynamic array  
    int numWalls;  
public:  
    Level(int numWalls);  
    ~Level();  
    void DrawWalls() const;  
};  