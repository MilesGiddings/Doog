#pragma once
#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"

class GameObject {
protected:
    Vector3 position;
    BoundingBox bounds; // For collision
public:
    GameObject(float x, float y, float z);
    virtual ~GameObject() = default;
    virtual void Update() {}
    virtual void Draw() const = 0;
    Vector3 GetPosition() const { return position; }
    BoundingBox GetBounds() const { return bounds; }
};