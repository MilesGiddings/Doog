#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"
using namespace std;
#include <iostream>

int Enemy::totalCats = 0;  

Enemy::Enemy(float x, float y, float z, Player* player)
    : GameObject(x, y, z), playerRef(player) {
    totalCats++;
    patrolOrigin = { x, y, z };

    bounds.min = { x - 0.5f, y, z - 0.5f }; 
    bounds.max = { x + 0.5f, y + 2.0f, z + 0.5f }; // these bouds were for collision detection that was never implemented
}


Enemy::~Enemy() {  
    totalCats--;  
}

int Enemy::total() {  
    return totalCats;  
}

// Enemy.cpp
void Enemy::Draw() const {
    DrawCube(position, 1.0f, 2.0f, 1.0f, ORANGE);
    
    // Cooldown indicator (red ring)
    if (attackCooldown > 0) {
        DrawCircle3D(
            position, 1.5f, {0, 1, 0}, 90.0f, Fade(RED, 0.5f) // Draw a red ring around the enemy showing cooldown and hitbox
        );
    }
}

void Enemy::Patrol(bool patrolActive) {
    if (!patrolActive) return;

    float delta = patrolSpeed * GetFrameTime();
    position.x += patrolDirection * delta;

    // If its too far from origin, reverse direction
    if (position.x > patrolOrigin.x + patrolRange || position.x < patrolOrigin.x - patrolRange) {
        patrolDirection *= -1.0f;
        position.x = Clamp(position.x, patrolOrigin.x - patrolRange, patrolOrigin.x + patrolRange); // Clamp position to patrol range
        // clamp is a function that limits the value to a specified range
    }
}

void Enemy::Chase() {
    if (!playerRef) return;

    Vector3 playerPos = playerRef->GetPosition();
    Vector3 direction = Vector3Subtract(playerPos, position);
    float distance = Vector3Length(direction);

    // Cooldown logic
    attackCooldown -= GetFrameTime(); // Decrement cooldown timer
    if (attackCooldown < 0) attackCooldown = 0;

    if (distance < 5.0f) { // Chase if within 5 units
        direction = Vector3Normalize(direction);
        
        // Movement with GetFrameTime() for frame-rate independence
        position = Vector3Add(position, 
            Vector3Scale(direction, BASE_SPEED * GetFrameTime())); // Move towards player #### IF YOU REMOVE GETFRAMETIME, THE ENEMY WILL TELEPORT
            //GetFrameTime() returns the time in seconds since the last frame, allowing for smooth movement regardless of frame rate
            // #WeloveGetFrameTime() multilply everything by it to make it frame-rate independent
            // Here is a helpful youtube link talking about frametime in video games that helped me understand it better: https://www.youtube.com/watch?v=yGhfUcPjXuE
    }

    if (distance < 1.0f) { 
        // Only attack if cooldown is ready
        if (attackCooldown <= 0) {
            Attack();
            attackCooldown = ATTACK_COOLDOWN; // Reset cooldown
        }
    }
}

void Enemy::TakeDamage(int damage) {
    health -= damage;
    std::cout << "Enemy took " << damage << " damage. Health: " << health << "\n";
    
    if (health <= 0 && !isDead) {
        isDead = true;
    }
    
}// Function to handle enemy death

void Enemy::Attack() {
    // Attack logic (e.g., reduce player health)
    if (!playerRef) return;
    // Example: Reduce player health by 10
    playerRef->TakeDamage(10); 
}






void Enemy::Update() {
    // enemy logic
    Patrol(true); // Call patrol method
    Chase(); // Call chase method
    bounds.min = { position.x - 0.5f, position.y, position.z - 0.5f };// Update bounds for collision detection that was never implemented
    bounds.max = { position.x + 0.5f, position.y + 2.0f, position.z + 0.5f };

}