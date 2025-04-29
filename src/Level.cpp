#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"


Level::Level() {
    // Initialize member variables
    mazeWidth = 20;    // Number of horizontal rooms
    mazeHeight = 20;   // Number of vertical rooms
    roomSize = 10;     // Size of each room (width and height)
    corridorSize = 2;  // Size of corridors between rooms
}

void Level::GenerateMap() {
    // Set spawn point (entrance)
    Vector3 entrancePosition = { static_cast<float>(roomSize), 0.0f, static_cast<float>(roomSize) };  // Entrance at (roomSize, 0, roomSize)

    // Create walls for the maze (initial grid of walls)
    for (int i = 0; i < mazeWidth; i++) {
        for (int j = 0; j < mazeHeight; j++) {
            // Create walls at grid intersections (leaving some spaces for corridors)
            if (i == 0 || j == 0 || i == mazeWidth - 1 || j == mazeHeight - 1 || rand() % 4 == 0) {
                walls.push_back(Wall(i * (roomSize + corridorSize), 0.0f, j * (roomSize + corridorSize), roomSize, 10, roomSize));
            }
        }
    }

    // Create corridors that connect rooms
    for (int i = 1; i < mazeWidth - 1; i++) {
        for (int j = 1; j < mazeHeight - 1; j++) {
            if (rand() % 3 == 0) {  // Randomly create corridors
                walls.push_back(Wall(i * (roomSize + corridorSize), 0.0f, j * (roomSize + corridorSize), corridorSize, 10, roomSize));
            }
        }
    }

    // Adding the edge walls (boundary walls) around the entire maze, making them very tall and thick
    for (int i = 0; i < mazeWidth; i++) {
        walls.push_back(Wall(i * (roomSize + corridorSize), 0.0f, mazeHeight * (roomSize + corridorSize), roomSize + 1, 20, 5));  // Top wall with overlap
    }
    
    for (int i = 0; i < mazeWidth; i++) {
        walls.push_back(Wall(i * (roomSize + corridorSize), 0.0f, -corridorSize, roomSize + 1, 20, 5));  // Bottom wall with overlap
    }

    for (int i = 0; i < mazeHeight; i++) {
        walls.push_back(Wall(-corridorSize, 0.0f, i * (roomSize + corridorSize), 5, 20, roomSize + 1));  // Left wall with overlap
    }

    for (int i = 0; i < mazeHeight; i++) {
        walls.push_back(Wall(mazeWidth * (roomSize + corridorSize), 0.0f, i * (roomSize + corridorSize), 5, 20, roomSize + 1));  // Right wall with overlap
    }

    // Adding walls around the opening (entrance) in green color (creating the doorway)
    walls.push_back(Wall(entrancePosition.x - roomSize / 2, 0.0f, entrancePosition.z, roomSize, 20, corridorSize, true));   // Left of entrance (Green wall)
    walls.push_back(Wall(entrancePosition.x + roomSize / 2, 0.0f, entrancePosition.z, roomSize, 20, corridorSize, true));   // Right of entrance (Green wall)
    walls.push_back(Wall(entrancePosition.x, 0.0f, entrancePosition.z - roomSize / 2, corridorSize, 20, roomSize, true));   // Top of entrance (Green wall)

    // Optional: Special markers or interactive points (like keys or items)
    walls.push_back(Wall(5.0f, 0.0f, 5.0f, 1.0f, 2.0f, 1.0f)); // Special marker "X"
}

void Level::Draw() const {
    // Draw floor
    DrawCube({ (mazeWidth * (roomSize + corridorSize)) / 2.0f, -0.1f, (mazeHeight * (roomSize + corridorSize)) / 2.0f }, 
             mazeWidth * (roomSize + corridorSize), 0.1f, mazeHeight * (roomSize + corridorSize), BLACK); // Floor

    // Draw ceiling
    DrawCube({ (mazeWidth * (roomSize + corridorSize)) / 2.0f, 20.1f, (mazeHeight * (roomSize + corridorSize)) / 2.0f }, 
             mazeWidth * (roomSize + corridorSize), 0.1f, mazeHeight * (roomSize + corridorSize), BLACK); // Ceiling

    // Draw walls
    for (const auto& wall : walls) {
        wall.Draw();
    }
}

bool Level::CheckCollision(const BoundingBox& playerBounds) {
    for (const auto& wall : walls) {
        if (CheckCollisionBoxes(playerBounds, wall.GetBounds())) return true;
    }
    return false;
}
