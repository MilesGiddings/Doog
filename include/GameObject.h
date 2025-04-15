#pragma once
#include "raylib.h"

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