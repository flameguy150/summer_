#include <raylib.h>
#include <iostream>
#include "globals.h"
#include "terrain.h"

using namespace std;

Camera3D camera = {0};
Vector3 cubePosition = {0.0f, 0.0f, 0.0f};

int main()
{
    Color bgColor = BLACK;
    int screenWidth = 1200;
    int screenHeight = 600;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "INFINITE_TERRAIN");

    SetTargetFPS(60);
    float rotation = 0.0f;

    camera.position = (Vector3){0.0f, 10.0f, 10.0f}; // Camera position
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};     // Camera looking at point
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};         // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                             // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;          // Camera mode type

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();

        rotation += GetFPS() * 0.05;
        BeginDrawing();
        ClearBackground(bgColor);

        DrawFPS(0, 0);
        DrawPolyLines((Vector2){20, 50}, 6, 20, rotation, RED);

        BeginMode3D(camera);

        createFlatTerrain(screenWidth, screenHeight);

        EndMode3D();

        EndDrawing();
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();
    return 1;
}