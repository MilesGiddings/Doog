#include "Utility.h"

Texture2D LoadGameTexture(const std::string& path, bool useDefault) {
    if (useDefault) return LoadTexture("resources/default.png");
    return LoadTexture(path.c_str()); // Use raylib's LoadTexture internally
}