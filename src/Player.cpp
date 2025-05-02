#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"
#include "raymath.h"
#include <iostream>

Player::Player(float x, float y, float z) : GameObject(x, y, z) {
    // Lock player to a standard eye height (1.0f)
    camera.position.y = 1.0f;

    // Lock the target to look straight (same height)
    Vector3 direction = {
        sinf(DEG2RAD * rotationAngle),
        0.0f,
        cosf(DEG2RAD * rotationAngle)
    };
    camera.target = Vector3Add(camera.position, direction);

    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    rotationAngle = 0.0f;
}

void Player::Update() {
    float deltaTime = GetFrameTime();

    //  Movement Speeds
    float baseSpeed = 15.0f;
    float sprintSpeed = 30.0f;
    float moveSpeed = IsKeyDown(KEY_LEFT_SHIFT) ? sprintSpeed : baseSpeed;

    //  Rotation
    float rotationSpeed = 90.0f;
    if (IsKeyDown(KEY_LEFT)) rotationAngle += rotationSpeed * deltaTime;
    if (IsKeyDown(KEY_RIGHT)) rotationAngle -= rotationSpeed * deltaTime;

    // Direction Vector 
    Vector3 forward = {
        sinf(DEG2RAD * rotationAngle),
        0.0f,
        cosf(DEG2RAD * rotationAngle)
    };
    Vector3 right = Vector3CrossProduct(forward, {0.0f, 1.0f, 0.0f});

    //  Movement Logic 
    Vector3 targetPos = camera.position;
    float frameMove = moveSpeed * deltaTime;

    if (IsKeyDown(KEY_W)) targetPos = Vector3Add(targetPos, Vector3Scale(forward, frameMove));
    if (IsKeyDown(KEY_S)) targetPos = Vector3Subtract(targetPos, Vector3Scale(forward, frameMove));
    if (IsKeyDown(KEY_A)) targetPos = Vector3Subtract(targetPos, Vector3Scale(right, frameMove));
    if (IsKeyDown(KEY_D)) targetPos = Vector3Add(targetPos, Vector3Scale(right, frameMove));

    // Apply Movement Smoothly 
    camera.position = Vector3Lerp(camera.position, targetPos, 10.0f * deltaTime);

    //  Lock to Eye Level 
    camera.position.y = 1.0f;

    // Set View Direction 
    Vector3 lookDir = Vector3Normalize(forward);
    camera.target = Vector3Add(camera.position, lookDir);

    // --- Store back into player position ---
    position = camera.position;
}


void Player::Shoot(std::vector<Enemy>& enemies) {
    Vector3 myPos = camera.position;
    Vector3 myDir = Vector3Normalize(Vector3Subtract(camera.target, camera.position));

    for (Enemy& enemy : enemies) {
        Vector3 toEnemy = Vector3Subtract(enemy.GetPosition(), myPos);
        float distance = Vector3Length(toEnemy);
        Vector3 dirToEnemy = Vector3Normalize(toEnemy);

        float angle = Vector3DotProduct(myDir, dirToEnemy); // 1 = directly in front

        // Must be within 6 units and roughly in front (60 degrees)
        if (distance < 6.0f && angle > 0.5f) {
            std::cout << "Direct hit!\n";
            enemy.TakeDamage(999);  // Guaranteed kill for testing
            break;
        }
    }
}


void Player::Draw() const {
    DrawCube(position, 1.0f, 2.0f, 1.0f, RED);
}