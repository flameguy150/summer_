#include <raylib.h>
#include <iostream>
#include "globals.h"
#include "terrain.h"

using namespace std;

Camera3D camera = {0};
Vector3 originCubePosition = {0.0f, 0.0f, 0.0f};
Vector3 cubePosition = {2.0f, 0.0f, 0.0f};
float terrain[TERRAIN_WIDTH][TERRAIN_DEPTH];

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

    // DisableCursor();

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();

        rotation += GetFPS() * 0.05;
        UpdateCamera(&camera, CAMERA_FREE);

        for (int x = 0; x < TERRAIN_WIDTH; ++x)
        {
            for (int z = 0; z < TERRAIN_DEPTH; ++z)
            {
                terrain[x][z] = noise(x, z);
            }
        }
        //---------------------------------------------DRAWING--------------------------------------------------------

        BeginDrawing();
        ClearBackground(bgColor);

        DrawFPS(0, 0);
        DrawPolyLines((Vector2){20, 50}, 6, 20, rotation, RED);
        //---------------------------------------------3D--------------------------------------------------------
        BeginMode3D(camera);
        if (IsKeyPressed('Z'))
        {
            camera.target = (Vector3){0.0f, 0.0f, 0.0f};
        }
        createFlatTerrain(screenWidth, screenHeight);

        EndMode3D();
        //--------------------------------------------------------------------------------------------------------

        EndDrawing();
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();
    return 1;
}