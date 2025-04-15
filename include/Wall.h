#pragma once
#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"

class Wall : public GameObject {
private:
    Vector3 size;
public:
    Wall(float x, float y, float z, float width, float height, float depth);
    void Draw() const override;
};