#pragma once
#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"
#include <vector>

class Level {
private:
    int mazeWidth;
    int mazeHeight;
    int roomSize;
    int corridorSize;

    std::vector<Wall> walls;  // List of walls in the maze
    std::vector<Enemy> enemies; // List of enemies in the maze

public:
    Level();  // Constructor

    void GenerateMap(Player* playerRef); // Function to generate the map
    void Draw() const;  // Function to draw the everything in the level, floor/ceiling, and enemies
    bool CheckCollision(const BoundingBox& playerBounds);  // Function to check for collisions
    std::vector<Enemy>& GetEnemies() { return enemies; } // Function to get enemies
    void RemoveDeadEnemies();  // Function to remove dead enemies
};
