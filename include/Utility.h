#pragma once
#include <string>
#include "raylib.h"

// Renamed to avoid conflict
Texture2D LoadGameTexture(const std::string& path, bool useDefault = true);