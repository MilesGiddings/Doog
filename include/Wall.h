#pragma once
#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Wall.h"
#include "GameObject.h"

class Wall {
    private:
        Vector3 position;  // Position of the wall
        Vector3 size;      // Size of the wall (width, height, depth)
        bool isEntrance;   // Whether the wall is part of the entrance | I tried to make the entrance a wall, but it didn't work out the way I wanted
    public:
        Wall(float x, float y, float z, float width, float height, float depth, bool entrance = false);
    
        void Draw() const;
    
        // Made to get the bounds of the wall for collision detection 
        BoundingBox GetBounds() const {
            return { 
                {position.x - size.x / 2, position.y - size.y / 2, position.z - size.z / 2}, // Min corner
                {position.x + size.x / 2, position.y + size.y / 2, position.z + size.z / 2}  // Max corner
            };
        }
    };