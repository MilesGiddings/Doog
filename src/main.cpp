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
    SetTargetFPS(60); // If -1 is set, the program will run as fast as possible
    SetExitKey(KEY_ESCAPE); // Enable ESC key to exit
    DisableCursor();
    
    Player player(6.0f, 7.0f, 10.0f);
    Enemy enemy(10.0f, 1.0f, 20.0f, &player); // Create an enemy instance
    Level level;
    level.GenerateMap(); // Generate the map with walls

    while (!WindowShouldClose()) {
        // Collision check (optional)
        BoundingBox playerBounds = player.GetBounds();
        if (level.CheckCollision(playerBounds)) {
            // Handle collision (e.g., reset position)
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);  // Clear the screen to white
            BeginMode3D(player.GetCamera());  // Begin 3D rendering
                level.Draw();  // Draw 3D level
                player.Draw(); // Optional: Draw player model
                enemy.Draw();  // Optional: Draw enemy model
            EndMode3D();  // End 3D rendering

            // Now we can draw 2D UI elements like FPS, health, etc.
            BeginDrawing();  // Start drawing 2D elements

                // FPS Display
                DrawFPS(1365, 0);

                // Display number of cats
                string eTotal = std::to_string(enemy.total());
                eTotal = "Total Cats: " + eTotal;
                const char* trueTotal = eTotal.c_str();
                DrawText(trueTotal, 1300, 20, 20, BLUE);

                // Display player health
                string pHealth = std::to_string(player.getHealth());
                pHealth = "Health " + pHealth;
                const char* trueHealth = pHealth.c_str();
                DrawText(trueHealth, 1100, 20, 20, BLUE);

                // Display player position for debugging purposes
                Vector3 playerPos = player.GetPosition();  // Get the player's position
                string positionText = "Player Position: X=" + std::to_string(playerPos.x) + 
                                      " Y=" + std::to_string(playerPos.y) + 
                                      " Z=" + std::to_string(playerPos.z);
                const char* truePosition = positionText.c_str();
                DrawText(truePosition, 100, 100, 20, GREEN);  // Display position in the top-left corner


                int centerX = GetScreenWidth() / 2;
                int centerY = GetScreenHeight() / 2;
                
                DrawCircle(centerX, centerY, 5, RED); // Tiny center dot



            EndDrawing();  // End 2D drawing

        // Update player and enemy
        enemy.Update();
        player.Update();
    }

    CloseWindow();
    return 0;
}
