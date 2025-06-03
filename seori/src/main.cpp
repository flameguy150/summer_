// #include <raylib.h>
// #include <iostream>
// #include "draw.h"

// using namespace std;

// int screenWidth = 1200;
// int screenHeight = 600;

// int main()
// {
//     Color bgColor = BLACK;

//     Font font = LoadFont("/seori/resources/noto-sans/NotoSans-Regular.ttf");

//     SetConfigFlags(FLAG_WINDOW_RESIZABLE);
//     InitWindow(screenWidth, screenHeight, "seori");

//     SetTargetFPS(60);
//     float rotation = 0.0f;

//     // DisableCursor();

//     while (!WindowShouldClose()) // Detect window close button or ESC key
//     {
//         screenWidth = GetScreenWidth();
//         screenHeight = GetScreenHeight();

//         rotation += GetFPS() * 0.05;

//         //---------------------------------------------DRAWING--------------------------------------------------------

//         BeginDrawing();
//         ClearBackground(bgColor);

//         DrawFPS(0, 0);
//         DrawPolyLines((Vector2){20, 50}, 6, 20, rotation, RED);

//         DrawCircle(screenWidth / 2, screenHeight / 2, 100, RED);
//         DrawCoordinatePlane();

//         EndDrawing();
//     }
//     // De-Initialization
//     //--------------------------------------------------------------------------------------
//     UnloadFont(font);
//     CloseWindow();
//     return 1;
// }