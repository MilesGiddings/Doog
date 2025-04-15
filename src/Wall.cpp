#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"

Wall::Wall(float x, float y, float z, float w, float h, float d) 
    : GameObject(x, y, z), size({w, h, d}) {
    bounds = {
        {x - w/2, y - h/2, z - d/2},
        {x + w/2, y + h/2, z + d/2}
    };
}

void Wall::Draw() const {
    DrawCube(position, size.x, size.y, size.z, GRAY);
    // Optional: Draw bounding box for debugging
    // DrawBoundingBox(bounds, RED);
}