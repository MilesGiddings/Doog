#pragma once // this is pretty useful 
#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"

class Player;

class Enemy : public GameObject {
private:
    static int totalCats;
    float BASE_SPEED = 2.0f; // Speed of the enemy
    int health = 125; // Health of the enemy 
    Player* playerRef;
    float attackCooldown = 0.0f;      // Tracks remaining cooldown time
    float ATTACK_COOLDOWN = 2.0f; // 2 seconds between attacks // Reference to the player
    Vector3 patrolOrigin;
    float patrolRange = 2.0f;   // How far to move from origin (1 unit left, 1 right)
    float patrolSpeed = 1.0f;   // Units per second
    float patrolDirection = 1.0f;  // +1 or -1
public:
    Enemy(float x, float y, float z, Player* player);
    ~Enemy(); // Destructor
    int total(); // Static method to get total cats
    void Update() override; // overrides virtual method
    void Draw() const override;
    void Patrol(bool patrol); // Patrol method
    void Chase(); // Chase player method
    void Attack(); // Attack player method
    void TakeDamage(int damage); // Take damage method
    BoundingBox GetBounds() const { return bounds; }
    bool isDead = false;
    bool IsDead() const { return isDead; }

};