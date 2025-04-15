#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"
#include "raymath.h"

Player::Player(float x, float y, float z) : GameObject(x, y, z) {
    camera.position = {x, y, z};
    camera.target = {x, y, z - 1.0f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    rotationAngle = 0.0f;
}

void Player::Update() {
    float deltaTime = GetFrameTime();

    // 1. Handle sprint first
    float baseSpeed = 50.0f;
    float sprintSpeed = 100.0f;
    float currentMoveSpeed = baseSpeed;
    
    if (IsKeyDown(KEY_LEFT_SHIFT)) {
        currentMoveSpeed = sprintSpeed;
    }
    
    // Rotation
    float rotationSpeed = 90.0f; // Degrees per second
    if (IsKeyDown(KEY_LEFT)) rotationAngle += rotationSpeed * deltaTime;
    if (IsKeyDown(KEY_RIGHT)) rotationAngle -= rotationSpeed * deltaTime;

    // Direction calculation
    Vector3 direction = {
        sinf(DEG2RAD * rotationAngle),
        0,
        cosf(DEG2RAD * rotationAngle)
    };
    Vector3 forward = Vector3Normalize(direction);
    Vector3 right = Vector3CrossProduct(forward, {0, 1, 0});

    // Movement
    float frameMove = currentMoveSpeed * deltaTime;
    Vector3 targetPos = camera.position;

    if (IsKeyDown(KEY_W)) targetPos = Vector3Add(targetPos, Vector3Scale(forward, frameMove));
    if (IsKeyDown(KEY_S)) targetPos = Vector3Subtract(targetPos, Vector3Scale(forward, frameMove));
    if (IsKeyDown(KEY_A)) targetPos = Vector3Subtract(targetPos, Vector3Scale(right, frameMove));
    if (IsKeyDown(KEY_D)) targetPos = Vector3Add(targetPos, Vector3Scale(right, frameMove));

    // Collision detection with walls


    // Apply smoothed movement
    camera.position = Vector3Lerp(camera.position, targetPos, 10.0f * deltaTime);
    camera.target = Vector3Add(camera.position, direction);
    camera.position.y = 1.0f; // Lock Y position
    position = camera.position;
}

void Player::Draw() const {
    DrawCube(position, 1.0f, 2.0f, 1.0f, RED);
}