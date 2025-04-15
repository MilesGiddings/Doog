#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"

GameObject::GameObject(float x, float y, float z) {  
    position = {x, y, z};  
}
  