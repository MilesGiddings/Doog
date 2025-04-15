#include "raylib.h"
#include "Player.h"
#include "Level.h"

int main() {
    InitWindow(800, 600, "Doog");
    SetTargetFPS(60);// If -1 is set, the program will run as fast as possible : This could be useful for pacing/ scaling the game diffuculty
    SetExitKey(0); // Disable ESC key to exit
    EnableCursor();

    Player player(0.0f, 1.0f, 0.0f);
    Level level;

    while (!WindowShouldClose()) {
        DrawFPS(725, 0);
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
            EndMode3D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}