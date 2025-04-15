#include "Enemy.h"  
#include "raylib.h"  

int Enemy::totalCats = 0;  

Enemy::Enemy(float x, float y, float z) : GameObject(x, y, z) {  
    totalCats++;  
}  

Enemy::~Enemy() {  
    totalCats--;  
}  

void Enemy::Draw() const {  
    DrawCube(position, 2.0f, 4.0f, 2.0f, ORANGE);  
}

void Enemy::Update() {
    // Add enemy logic here (e.g., patrol, chase player)
    // For now, leave it empty if not needed:
    // (But it must be defined to resolve the linker error)
}  