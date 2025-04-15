#pragma once  
#include "GameObject.h"  

class Wall : public GameObject {  
private:  
    const Color WALL_COLOR = GRAY; // Const data  
    static int totalWalls;         // Static data  
public:  
    Wall(float x, float y, float z);  
    ~Wall();  
    void Draw() const override;  
};  