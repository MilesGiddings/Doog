#include "Player.h"
#include "raylib.h"
#include "raymath.h"

Player::Player(float x, float y, float z) : GameObject(x, y, z) {
    camera.position = {x, y, z};
    camera.target = {x, y, z - 1.0f}; // Look ahead
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 90.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    rotationAngle = 0.0f; // Add this member variable to Player class
}

void Player::Update() {
    // Arrow key rotation
    float rotationSpeed = 2.0f;
    if (IsKeyDown(KEY_LEFT)) rotationAngle += rotationSpeed;
    if (IsKeyDown(KEY_RIGHT)) rotationAngle -= rotationSpeed;
    
    // Update camera target based on rotation
    Vector3 direction = {
        sin(DEG2RAD * rotationAngle),
        0,
        cos(DEG2RAD * rotationAngle)
    };
    camera.target = Vector3Add(camera.position, direction);

    // WASD movement relative to rotation
    Vector3 forward = Vector3Normalize(direction);
    Vector3 right = Vector3CrossProduct(forward, {0, 1, 0});

    if (IsKeyDown(KEY_W)) camera.position = Vector3Add(camera.position, Vector3Scale(forward, 0.1f));
    if (IsKeyDown(KEY_S)) camera.position = Vector3Subtract(camera.position, Vector3Scale(forward, 0.1f));
    if (IsKeyDown(KEY_A)) camera.position = Vector3Subtract(camera.position, Vector3Scale(right, 0.1f));
    if (IsKeyDown(KEY_D)) camera.position = Vector3Add(camera.position, Vector3Scale(right, 0.1f));

    // Keep camera height fixed
    camera.position.y = 1.0f; // Adjust this value to match your needs
    position = camera.position;
}

void Player::Draw() const {
    DrawCube(position, 1.0f, 2.0f, 1.0f, RED);
}