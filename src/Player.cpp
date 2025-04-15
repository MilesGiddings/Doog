#include "Player.h"  
#include "raylib.h"  

int Player::totalPlayers = 0;  

Player::Player(float x, float y, float z) : GameObject(x, y, z) {  
    totalPlayers++;  
}  

void Player::Update() {  
    if (IsKeyDown(KEY_W)) position.z -= PLAYER_SPEED;  
    if (IsKeyDown(KEY_S)) position.z += PLAYER_SPEED;  
    // Add left/right movement  
}  

void Player::Draw() const {  
    DrawCube(position, 2.0f, 4.0f, 2.0f, DARKBLUE);  
}