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
    Camera3D camera; // Camera for the player
    float rotationAngle; // Angle of rotation
    int health = 100;
    const int maxHealth = 200;
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
    int getHealth() const { return health; } // Get current health
    void Shoot(std::vector<Enemy>& enemies); // Function to shoot at enemies

};