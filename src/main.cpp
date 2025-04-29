#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include "Utility.h"
#include "Wall.h"
#include "GameObject.h"
#include <iostream>
using namespace std;

int main() {
    InitWindow(1920, 1080, "Doog");
    ToggleBorderlessWindowed();
    SetTargetFPS(60);// If -1 is set, the program will run as fast as possible : This could be useful for pacing / scaling the game diffuculty
    SetExitKey(KEY_ESCAPE); // Enable ESC key to exit
    DisableCursor();
    
    Player player(0.0f, 5.0f, 0.0f);
    Enemy enemy(10.0f, 1.0f, 0.0f, &player); // Create an enemy instance
    Level level;
    level.GenerateMap(); // Generate the map with walls

    while (!WindowShouldClose()) {
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
            DrawCircle(GetScreenWidth()/2, GetScreenHeight()/2, 5, GREEN);
        EndDrawing();

        DrawFPS(1365, 0);
        string eTotal = std::to_string(enemy.total());
        eTotal = "Total Cats: " + eTotal;
        const char* trueTotal = eTotal.c_str();
        DrawText(trueTotal, 1300, 20, 20, BLUE);
        string pHealth = std::to_string(player.getHealth());
        pHealth = "Health " + pHealth;
        const char* trueHealth = pHealth.c_str();
        DrawText(trueHealth, 1100, 20, 20, BLUE);
        enemy.Update();
        player.Update();
    }

    CloseWindow();
    return 0;
}