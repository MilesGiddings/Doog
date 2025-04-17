#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"

int Enemy::totalCats = 0;  

Enemy::Enemy(float x, float y, float z) : GameObject(x, y, z) {  
    totalCats++;  
}  

Enemy::~Enemy() {  
    totalCats--;  
}  

void Enemy::Draw() const {  
    DrawCube(position, 1.0f, 2.0f, 1.0f, ORANGE);  
}
void Enemy::Patrol(bool patrol){
    static bool movingRight = true;
    if (!patrol) return; // If not patrolling, do nothing
    if (movingRight) {
        position.x += 0.025f; // Move right
        if (position.x > 2.5f) { // Change direction at boundary
            movingRight = false;
        }
    } else {
        position.x -= 0.025f; // Move left
        if (position.x < -2.5f) { // Change direction at boundary
            movingRight = true;
        }
    }
}

void Enemy::Update() {
    // Add enemy logic here (e.g., patrol, chase player)
    // Simple movement logic: move back and forth along the x-axis
    Patrol(false);

}  