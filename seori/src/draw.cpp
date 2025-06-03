#include "draw.h"
#include <math.h>
#include <cmath>
#include <cwchar>
#include <string>

#define PI_PIXELS 120 // 1π == 100 pixels
#define RADIANS_TO_PIXEL (PI_PIXELS / PI)

/**
 * @param xStart Startin X coordinate
 * @param xEnd Ending X coordinate
 **/
void DrawSinFunc(float xStart, float xEnd)
{
    float scaleX = 50.0f;  //( 1 unit on the x-axis = 50 pixels if scaleX = 50)
    float scaleY = 100.0f; // ( 1 unit on the Y-axis = 100 pixels if scaleY = 100)
    int resolution = 10000;
    float step = (xEnd - xStart) / resolution;
    float offset = screenWidth / 2;

    for (int i = 0; i < resolution; ++i)
    {
        float x1 = xStart + (i * step);
        float x2 = xStart + (1 + i) * step;

        float y1 = sinf(x1) * scaleY;
        float y2 = sinf(x2) * scaleY;

        int sx1 = (int)(x1 * scaleX + offset);
        int sy1 = screenHeight / 2 - (int)(y1); // Flip y-axis
        int sx2 = (int)(x2 * scaleX + offset);
        int sy2 = screenHeight / 2 - (int)(y2);

        DrawLine(sx1, sy1, sx2, sy2, RED);
    }
}

/**
 * @param xStart Startin X coordinate
 * @param xEnd Ending X coordinate
 **/
void DrawCosFunc(float xStart, float xEnd)
{
    float scaleX = 50.0f;  //( 1 unit on the x-axis = 50 pixels if scaleX = 50)
    float scaleY = 100.0f; // ( 1 unit on the Y-axis = 100 pixels if scaleY = 100)
    int resolution = 10000;
    float step = (xEnd - xStart) / resolution;
    float offset = screenWidth / 2;

    for (int i = 0; i < resolution; ++i)
    {
        float x1 = xStart + (i * step);
        float x2 = xStart + (1 + i) * step;

        float y1 = cosf(x1) * scaleY;
        float y2 = cosf(x2) * scaleY;

        int sx1 = (int)(x1 * scaleX + offset);
        int sy1 = screenHeight / 2 - (int)(y1); // Flip y-axis
        int sx2 = (int)(x2 * scaleX + offset);
        int sy2 = screenHeight / 2 - (int)(y2);

        DrawLine(sx1, sy1, sx2, sy2, SKYBLUE);
    }
}

/**
 * @param xStart Startin X coordinate
 * @param xEnd Ending X coordinate
 **/
void DrawTanFunc(float xStart, float xEnd)
{
    float scaleX = 50.0f;  //( 1 unit on the x-axis = 50 pixels if scaleX = 50)
    float scaleY = 100.0f; // ( 1 unit on the Y-axis = 100 pixels if scaleY = 100)
    int resolution = 10000;
    float step = (xEnd - xStart) / resolution;
    float offset = screenWidth / 2;

    for (int i = 0; i < resolution; ++i)
    {
        float x1 = xStart + (i * step);
        float x2 = xStart + (1 + i) * step;

        float y1 = tanf(x1) * scaleY;
        float y2 = tanf(x2) * scaleY;

        int sx1 = (int)(x1 * scaleX + offset);
        int sy1 = screenHeight / 2 - (int)(y1); // Flip y-axis
        int sx2 = (int)(x2 * scaleX + offset);
        int sy2 = screenHeight / 2 - (int)(y2);

        DrawLine(sx1, sy1, sx2, sy2, GREEN);
    }
}

void DrawNumericTicks()
{
    // draw 20 ticks, from -10 to 10

    // horizontal ticks
    int numTicks = 21;
    int step = screenWidth / numTicks;
    for (int i = 0; i < 20; ++i)
    {
        int x1 = i * step;
        int y1 = screenHeight / 2 - 10;
        int x2 = i * step;
        int y2 = screenHeight / 2 + 10;
        DrawLine(x1, y1, x2, y2, WHITE);
    }

    // vertical ticks
    int stepH = screenHeight / 10;
    for (int i = 0; i < 10; ++i)
    {
        int x1 = screenWidth / 2 - 10;
        int y1 = i * stepH;
        int x2 = screenWidth / 2 + 10;
        int y2 = i * stepH;
        DrawLine(x1, y1, x2, y2, WHITE);
    }
}

void DrawRadianTicks()
{
    float scaleX = 50.0f;
    int origin_X = screenWidth / 2;
    int origin_Y = screenHeight / 2;

    std::string text;

    for (int i = -5; i <= 5; ++i)
    {
        int x1 = origin_X + (int)(i * PI * scaleX);
        int y1 = origin_Y - 10;
        int x2 = origin_X + (int)(i * PI * scaleX);
        int y2 = origin_Y + 10;
        DrawLine(x1, y1, x2, y2, WHITE);

        if (i != 0)
        {
            std::string text = std::to_string(i) + "pi";
            DrawText(text.c_str(), (x1 - 5), (y2 + 10), 15, WHITE);
        }
    }
}

void DrawCoordinatePlane()
{
    int x = screenWidth / 2;
    int y = screenHeight / 2;
    // X Axis
    int startx = 0;
    int starty = y;
    int endx = screenWidth;
    int endy = y;

    DrawLine(startx, starty, endx, endy, WHITE);

    int startx2 = x;
    int starty2 = 0;
    int endx2 = x;
    int endy2 = screenHeight;

    DrawLine(startx2, starty2, endx2, endy2, WHITE);

    // DrawNumericTicks();
    DrawRadianTicks();
}