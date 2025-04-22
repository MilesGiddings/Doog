#pragma once
#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"
#include "raymath.h"

class Player : public GameObject {
private:
    Camera3D camera;
    float rotationAngle;
    int health = 100;
    int maxHealth = 200;
public:
    Player(float x, float y, float z);
    void Update() override;
    void Draw() const override;
    Camera3D& GetCamera() { return camera; }
    Vector3 GetPosition() const { return camera.position; }
    void TakeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0; // Prevent negative health
    }
    int getHealth() const { return health; }
};