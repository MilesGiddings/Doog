#include "Level.h"

Level::Level() {
    // Example: Create a simple 3D maze
    walls.emplace_back(0.0f, 2.0f, 5.0f, 10.0f, 4.0f, 1.0f); // Wall at (0, 2, 5)
    walls.emplace_back(5.0f, 2.0f, 0.0f, 1.0f, 4.0f, 10.0f); // Wall at (5, 2, 0)
}

void Level::Draw() const {
    for (const auto& wall : walls) wall.Draw();
}

bool Level::CheckCollision(const BoundingBox& playerBounds) {
    for (const auto& wall : walls) {
        if (CheckCollisionBoxes(playerBounds, wall.GetBounds())) return true;
    }
    return false;
}