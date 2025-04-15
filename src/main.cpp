#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"

int main() {
    InitWindow(1920, 1080, "Doog");
    ToggleBorderlessWindowed();
    SetTargetFPS(120);// If -1 is set, the program will run as fast as possible : This could be useful for pacing/ scaling the game diffuculty
    SetExitKey(KEY_ESCAPE); // Disable ESC key to exit
    DisableCursor();

    Player player(0.0f, 1.0f, 0.0f);
    Enemy enemy(0.0f, 1.0f, 0.0f); // Optional: Create an enemy instance
    Level level;

    while (!WindowShouldClose()) {
        DrawFPS(1365, 0);
        enemy.Update();
        player.Update();
        

        // Collision check (optional)
        BoundingBox playerBounds = player.GetBounds();
        if (level.CheckCollision(playerBounds)) {
            // Handle collision (e.g., reset position)
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(player.GetCamera());
                level.Draw();
                player.Draw(); // Optional: Draw player model
                enemy.Draw(); // Optional: Draw enemy model
            EndMode3D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}