#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"

Texture2D LoadGameTexture(const std::string& path, bool useDefault) {
    if (useDefault) return LoadTexture("resources/default.png");
    return LoadTexture(path.c_str()); // Use raylib's LoadTexture internally
}