#include "raylib.h"
#include "raymath.h"

/*
TO COMPILE
clang++ test.cpp -o game -std=c++11 -I/usr/local/include -L/usr/local/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
./game
*/

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Simple Character Movement");
    SetTargetFPS(60);

    float playerX = screenWidth / 2;
    float playerY = screenHeight / 2;
    float playerSpeed = 5.0f;
    const int playerSize = 40;

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT))
            playerX += playerSpeed;
        if (IsKeyDown(KEY_LEFT))
            playerX -= playerSpeed;
        if (IsKeyDown(KEY_UP))
            playerY -= playerSpeed;
        if (IsKeyDown(KEY_DOWN))
            playerY += playerSpeed;

        playerX = Clamp(playerX, 0, screenWidth - playerSize);
        playerY = Clamp(playerY, 0, screenHeight - playerSize);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(playerX, playerY, playerSize, playerSize, RED);
        DrawText("Use arrow keys to move!", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}