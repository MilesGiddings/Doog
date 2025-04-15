// Enemy.h
#pragma once
#include "GameObject.h"

class Enemy : public GameObject {
private:
    static int totalCats;
public:
    Enemy(float x, float y, float z);
    ~Enemy();
    void Update() override; // Correct: overrides virtual method
    void Draw() const override;
};