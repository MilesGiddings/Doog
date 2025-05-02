#pragma once
#include <string>
#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"


Texture2D LoadGameTexture(const std::string& path, bool useDefault = true);