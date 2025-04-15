#pragma once
#include "GameObject.h"

class Wall : public GameObject {
private:
    Vector3 size;
public:
    Wall(float x, float y, float z, float width, float height, float depth);
    void Draw() const override;
};