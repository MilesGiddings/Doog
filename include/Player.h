// Player.h
#pragma once
#include "GameObject.h"

class Player : public GameObject {
private:
    const float PLAYER_SPEED = 5.0f;
    static int totalPlayers;
public:
    Player(float x, float y, float z);
    void Update() override; // Correct: overrides virtual method
    void Draw() const override;
};