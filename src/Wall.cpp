#include "Wall.h"  
#include "raylib.h"  

int Wall::totalWalls = 0;  

Wall::Wall(float x, float y, float z) : GameObject(x, y, z) {  
    totalWalls++;  
}  

Wall::~Wall() {  
    totalWalls--;  
}  

void Wall::Draw() const {  
    DrawCube(position, 2.0f, 4.0f, 2.0f, WALL_COLOR);  
}  