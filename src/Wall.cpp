#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"

Wall::Wall(float x, float y, float z, float width, float height, float depth, bool entrance)
    : position({x, y, z}), size({width, height, depth}), isEntrance(entrance) {}


void Wall::Draw() const {
    if (isEntrance) {
        DrawCube(position, size.x, size.y, size.z, GREEN);  // Draw green wall for entrance | got rid of this idea
    } else {            
        DrawCube(position, size.x, size.y, size.z, GRAY);   // Default wall color
    }
}
