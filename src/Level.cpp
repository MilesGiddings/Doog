#include "Level.h"  

Level::Level(int numWalls) : numWalls(numWalls) {  
    walls = new Wall*[numWalls];  
    for (int i = 0; i < numWalls; i++) {  
        walls[i] = new Wall(i * 4.0f, 0.0f, 0.0f);  
    }  
}  

Level::~Level() {  
    for (int i = 0; i < numWalls; i++) delete walls[i];  
    delete[] walls;  
}  

void Level::DrawWalls() const {  
    for (int i = 0; i < numWalls; i++) walls[i]->Draw();  
}  