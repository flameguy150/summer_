#include <raylib.h>
#include <iostream>
#include "draw.h"
// #include "globals.h"

using namespace std;

// int screenWidth = GetMonitorWidth(0);
// int screenHeight = GetMonitorHeight(0);

int screenWidth = 1200;
int screenHeight = 1200;

bool animatingFlag = true;

int main()
{
    Color bgColor = BLACK;

    // SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(screenWidth, screenHeight, "seori_sin");

    int prevScreenWidth = GetScreenWidth();
    int prevScreenHeight = GetScreenHeight();

    InitAudioDevice(); // Initialize audio device

    Music music = LoadMusicStream("assets/resources/music/angel_breakcore.mp3");

    PlayMusicStream(music);
    float timePlayed = 0.0f; // Time played normalized [0.0f..1.0f]
    bool pause = false;

    // int monitor = GetCurrentMonitor();
    // screenWidth = GetMonitorWidth(monitor);
    // screenHeight = GetMonitorHeight(monitor);
    // SetWindowSize(screenWidth, screenHeight);
    // Font font = LoadFont("/seori/resources/noto-sans/NotoSans-Regular.ttf");

    SetTargetFPS(600);
    float rotation = 0.0f;
    //--------------------SETTING UP POINT VECTORS-----------------------------------
    pushPointsToAll();
    //-------------------------------------------------------

    // InitSinPoints(-4 * PI, 4 * PI); // for animation, to push all points to animate in a vector
    InitPoints(-4 * PI, 4 * PI, "sin");
    InitPoints(-4 * PI, 4 * PI, "cos");
    InitPoints(-4 * PI, 4 * PI, "tan");
    InitPoints(-4 * PI, 4 * PI, "abs");

    // DisableCursor();

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        int currScreenWidth = GetScreenWidth();
        int currScreenHeight = GetScreenHeight();
        // if (prevScreenWidth != currScreenWidth || prevScreenHeight != currScreenHeight)
        // {
        //     resizePoints();
        // }
        UpdateMusicStream(music);

        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();
        rotation += GetFPS() * 0.05;

        //---------------------------------------------DRAWING--------------------------------------------------------

        BeginDrawing();
        ClearBackground(bgColor);
        DrawFPS(0, 0);
        DrawPolyLines((Vector2){20, 50}, 6, 20, rotation, RED);

        // DrawSinFunc(-4 * PI, 4 * PI);
        // AnimateSinFunc();

        /*
        if window size changes:
                        resizePoints()
        */
        if (IsKeyPressed(KEY_P)) // pause
        {
            animatingFlag = !animatingFlag;
        }
        if (animatingFlag)
        {
            AnimateFunc("sin", RED);
            AnimateFunc("cos", SKYBLUE);
            AnimateFunc("tan", GREEN);
            AnimateFunc("abs", YELLOW);
        }

        // DrawCosFunc(-4 * PI, 4 * PI);
        // DrawTanFunc(-4 * PI, 4 * PI);
        DrawCoordinatePlane();

        EndDrawing();
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    // UnloadFont(font);
    UnloadMusicStream(music); // Unload music stream buffers from RAM

    CloseAudioDevice(); // Close audio device (music streaming is automatically stopped)

    CloseWindow();
    return 0;
}