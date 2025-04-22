#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"

int Enemy::totalCats = 0;  

Enemy::Enemy(float x, float y, float z, Player* player) 
    : GameObject(x, y, z), playerRef(player) {
    totalCats++;
}



Enemy::~Enemy() {  
    totalCats--;  
}

int Enemy::total() {  
    return totalCats;  
}

void Enemy::Draw() const {  
    DrawCube(position, 1.0f, 2.0f, 1.0f, ORANGE);  
}
void Enemy::Patrol(bool patrol) {
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
void Enemy::Chase() {
    // Chase logic
    if (!playerRef) return;
    // Get player position directly
    Vector3 playerPos = playerRef->GetPosition();
    
    // Calculate direction
    Vector3 direction = Vector3Subtract(playerPos, position);
    float distance = Vector3Length(direction);
    
    if (distance < 5.0f) { // Chase if within 5 units
        direction = Vector3Normalize(direction);
        
        // Movement with GetFrameTime() for frame-rate independence
        position = Vector3Add(position, 
            Vector3Scale(direction, BASE_SPEED * GetFrameTime())); // Move towards player #### IF YOU REMOVE GETFRAMETIME, THE ENEMY WILL TELEPORT
    }
    if (distance < 1.0f) { // Attack if very close
        Attack();
    }
}

void Enemy::Attack() {
    // Attack logic (e.g., reduce player health)
    if (!playerRef) return;
    // Example: Reduce player health by 10
    playerRef->TakeDamage(10);
}
void Enemy::TakeDamage(int damage) {
    // Logic for taking damage
    // Example: Reduce enemy health
    health -= damage;
    if (health <= 0) {
        // Handle enemy death (e.g., remove from game)
        delete this;
        this->~Enemy();
    }
}


void Enemy::Update() {
    // Add enemy logic here (e.g., patrol, chase player)
    Patrol(true); // Call patrol method
    Chase(); // Call chase method
}