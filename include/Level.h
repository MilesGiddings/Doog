#pragma once
#include "Wall.h"
#include <vector>

class Level {
private:
    std::vector<Wall> walls; // Dynamic array of walls
public:
    Level();
    void Draw() const;
    bool CheckCollision(const BoundingBox& playerBounds);
};