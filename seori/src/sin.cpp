#include <raylib.h>
#include <iostream>
#include "draw.h"
// #include "globals.h"

using namespace std;

int screenWidth = 1200;
int screenHeight = 600;

int main()
{
    Color bgColor = BLACK;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "sin");

    Font font = LoadFont("/seori/resources/noto-sans/NotoSans-Regular.ttf");

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

        DrawSinFunc(-4 * PI, 4 * PI);
        DrawCosFunc(-4 * PI, 4 * PI);
        DrawTanFunc(-4 * PI, 4 * PI);
        DrawCoordinatePlane();

        EndDrawing();
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadFont(font);
    CloseWindow();
    return 1;
}