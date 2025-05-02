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
    InitAudioDevice(); // Initialize audio device
    ToggleBorderlessWindowed();
    SetTargetFPS(60); // If -1 is set, the program will run as fast as possible
    SetExitKey(KEY_ESCAPE); // Enable ESC key to exit
    DisableCursor();

    Sound gunshot = LoadSound("assets/bark.wav");
    
    Player player(6.0f, 1.0f, 6.0f);
    //Enemy enemy(10.0f, 1.0f, 20.0f, &player); // Create an enemy instance
    Level level;
    level.GenerateMap(&player);  // pass in player reference
    // Generate the map with walls

    while (!WindowShouldClose()) {
        if (player.getHealth() <= 0) {
            // Handle player death (e.g., reset game)
            CloseWindow();
        }
        BoundingBox playerBounds = player.GetBounds();
        if (level.CheckCollision(playerBounds)) {
            // Handle collision 
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);  // Clear the screen to white
            BeginMode3D(player.GetCamera());  // Begin 3D rendering
                Ray testRay;
                testRay.position = player.GetCamera().position;
                testRay.direction = Vector3Normalize(Vector3Subtract(player.GetCamera().target, player.GetCamera().position));
                DrawRay(testRay, RED);
                level.Draw();  // Draw 3D level
                player.Draw(); //Draw player model
                //enemy.Draw();  //Draw enemy model
                for (Enemy& e : level.GetEnemies()) e.Draw();

            EndMode3D();  // End 3D rendering

            // Draw 2D elements | Basically UI
            BeginDrawing();

                // FPS Display
                DrawFPS(1365, 0);

                // Display number of cats
                //string eTotal = std::to_string(enemy.total());
                //eTotal = "Total Cats: " + eTotal;
                //const char* trueTotal = eTotal.c_str();
                //DrawText(trueTotal, 1300, 20, 20, BLUE);

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


                DrawCircle(centerX, centerY, 5, RED); // Tiny center dot for a crosshair

                Camera3D cam = player.GetCamera();
                DrawText(TextFormat("Cam Pos: %.2f %.2f %.2f", cam.position.x, cam.position.y, cam.position.z), 50, 50, 20, RED);
                DrawText(TextFormat("Cam Target: %.2f %.2f %.2f", cam.target.x, cam.target.y, cam.target.z), 50, 70, 20, RED);



            EndDrawing();  // End 2D drawing


            if (IsKeyPressed(KEY_SPACE)) {
                player.Shoot(level.GetEnemies());
                PlaySound(gunshot); // give player a gunshot sound
            }
            
            for (Enemy& e : level.GetEnemies()) e.Update();
            player.Update();
            level.RemoveDeadEnemies(); // kill confirmed and remove dead enemies
        // Update player and enemy
        for (Enemy& e : level.GetEnemies()) e.Update();
        //enemy.Update();
        player.Update();
    }

    CloseWindow();
    return 0;
}
