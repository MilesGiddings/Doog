// GameObject.h
#pragma once
#include "raylib.h"

class GameObject {
protected:
    Vector3 position;
public:
    GameObject(float x, float y, float z);
    virtual ~GameObject() = default;

    // Declare Update() as virtual
    virtual void Update() {} // Add this line

    virtual void Draw() const = 0;
    Vector3 GetPosition() const { return position; }
};