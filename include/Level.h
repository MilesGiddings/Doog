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

    void GenerateMap();  // Function to generate the maze
    void Draw() const;  // Function to draw the maze, floor/ceiling, and enemies
    bool CheckCollision(const BoundingBox& playerBounds);  // Function to check for collisions

};
