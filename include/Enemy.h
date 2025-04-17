// Enemy.h
#pragma once
#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"


class Enemy : public GameObject {
private:
    static int totalCats;
    const float BASE_SPEED = 75.0f; // Speed of the enemy
public:
    Enemy(float x, float y, float z);
    ~Enemy();
    void Update() override; // Correct: overrides virtual method
    void Draw() const override;
    void Patrol(bool patrol); // Method to handle enemy patrol behavior
};