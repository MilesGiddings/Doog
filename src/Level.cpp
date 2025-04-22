#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"

Level::Level() {
    // Example: Create a simple 3D maze
    walls.push_back(Wall(0.0f, 0.0f, 0.0f, 10.0f, 2.0f, 1.0f)); // Wall at origin
    walls.push_back(Wall(10.0f, 0.0f, 0.0f, 1.0f, 2.0f, 10.0f)); // Wall to the right
    walls.push_back(Wall(0.0f, 0.0f, 10.0f, 10.0f, 2.0f, 1.0f)); // Wall at the back
    walls.push_back(Wall(-10.0f, 0.0f, 0.0f, 1.0f, 2.0f, 10.0f)); // Wall to the left
    walls.push_back(Wall(0.0f, 0.0f, -10.0f, 10.0f, 2.0f, 1.0f)); // Wall at the front
    walls.push_back(Wall(5.0f, 0.0f, 5.0f, 1.0f, 2.0f, 1.0f)); // Wall in the middle
    walls.push_back(Wall(-5.0f, 0.0f, -5.0f, 1.0f, 2.0f, 1.0f)); // Wall in the middle
    walls.push_back(Wall(0.0f, 0.0f, 5.0f, 1.0f, 2.0f, 1.0f)); // Wall in the middle
    walls.push_back(Wall(5.0f, 0.0f, 0.0f, 1.0f, 2.0f, 1.0f)); // Wall in the middle
    walls.push_back(Wall(-5.0f, 0.0f, 5.0f, 1.0f, 2.0f, 1.0f)); // Wall in the middle
    walls.push_back(Wall(0.0f, 0.0f, -5.0f, 1.0f, 2.0f, 1.0f)); // Wall in the middle
    walls.push_back(Wall(5.0f, 0.0f, -5.0f, 1.0f, 2.0f, 1.0f)); // Wall in the middle
    walls.push_back(Wall(-5.0f, 0.0f, -5.0f, 1.0f, 2.0f, 1.0f)); // Wall in the middle
    walls.push_back(Wall(0.0f, 0.0f, -5.0f, 1.0f, 2.0f, 1.0f)); // Wall in the middle
    walls.push_back(Wall(5.0f, 0.0f, -5.0f, 1.0f, 2.0f, 1.0f)); // Wall in the middle
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