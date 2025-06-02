#include <raylib.h>
#include <iostream>
#include "draw.h"

using namespace std;

int screenWidth = 1200;
int screenHeight = 600;

int main()
{
    Color bgColor = BLACK;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "sin");

    SetTargetFPS(60);
    float rotation = 0.0f;

    // DisableCursor();

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();

        rotation += GetFPS() * 0.05;

        //---------------------------------------------DRAWING--------------------------------------------------------

        BeginDrawing();
        ClearBackground(bgColor);

        DrawFPS(0, 0);
        DrawPolyLines((Vector2){20, 50}, 6, 20, rotation, RED);

        drawSinFunc(2 * -PI, 2 * PI);
        drawLilSinFunc(2 * -PI, 2 * PI);
        drawCoordinatePlane();

        EndDrawing();
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();
    return 1;
}