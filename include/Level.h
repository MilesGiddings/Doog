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
    std::vector<Wall> walls; // Dynamic array of walls
public:
    Level();
    void Draw() const;
    bool CheckCollision(const BoundingBox& playerBounds);
};