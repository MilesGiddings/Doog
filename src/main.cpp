#include "raylib.h"  
#include "Player.h"  
#include "Level.h"  


// To RUN 
//  make 
// ./build/Doog

int main() {  
    const int screenWidth = 800;  
    const int screenHeight = 450;  

    InitWindow(screenWidth, screenHeight, "Doog");  
    SetTargetFPS(60);  

    Player player(screenWidth/2, 0.0f, screenHeight/2);  
    Level level(10);  

    Camera camera = { 0 };  
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };  
    camera.target = player.GetPosition();  
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };  
    camera.fovy = 60.0f;  
    camera.projection = CAMERA_PERSPECTIVE;  

    while (!WindowShouldClose()) {  
        player.Update();  
        camera.target = player.GetPosition(); 

        BeginDrawing();  
            ClearBackground(RAYWHITE);  
            BeginMode3D(camera);  
                level.DrawWalls();  
                player.Draw();  
            EndMode3D();  
        EndDrawing();  
    }  

    CloseWindow();  
    return 0;  
}  