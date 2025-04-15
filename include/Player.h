#pragma once
#include "GameObject.h"
#include "raylib.h"
#include "raymath.h"

class Player : public GameObject {
private:
    Camera3D camera;
    float rotationAngle;
public:
    Player(float x, float y, float z);
    void Update() override;
    void Draw() const override;
    Camera3D& GetCamera() { return camera; }
};