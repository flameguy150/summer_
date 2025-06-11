#include "draw.h"
#include <math.h>
#include <cmath>
#include <cwchar>
#include <string>
#include <thread>
#include <chrono>
#include <cctype>

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
    int resolution = 2000;
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
//----------------------------------------------ANIMATION-------------------------------------------------------------

void InitSinPoints(float xStart, float xEnd)
{
    float scaleX = 50.0f;  //( 1 unit on the x-axis = 50 pixels if scaleX = 50)
    float scaleY = 100.0f; // ( 1 unit on the Y-axis = 100 pixels if scaleY = 100)
    int resolution = 10000;
    float step = (xEnd - xStart) / resolution;
    float offset = screenWidth / 2;
    for (int i = 0; i <= resolution; ++i)
    {
        float x1 = xStart + (i * step);
        float y1 = sinf(x1) * scaleY;

        int sx1 = (int)(x1 * scaleX + offset);
        int sy1 = screenHeight / 2 - (int)(y1); // Flip y-axis

        sinPoints.push_back({float(sx1), float(sy1)});
    }

    animationIndex = 0;
}

/*
Funny things:
    - To draw a laser drawing out the line, change sinPointsToDraw.size() - 1 to sinPointsToDraw.size().
      This works because when the loop access an out of bounds array, the array auto points to {0,0}. Funny lol
    - **WARNING** Elliptic redrawing, careful for flash**WARNING**
      To draw mirage, just comment out DrawFPS(0, 0) in sin.cpp
*/
void AnimateSinFunc()
{
    if (animationIndex + 1 < sinPoints.size())
    {
        sinPointsToDraw.push_back(sinPoints[animationIndex]);
        for (int i = 0; i < sinPointsToDraw.size() - 1; ++i)
        {
            DrawLine(sinPointsToDraw[i].x, sinPointsToDraw[i].y,
                     sinPointsToDraw[i + 1].x, sinPointsToDraw[i + 1].y, RED);
        }
        animationIndex += 1;
    }
    else // if end is reached
    {
        for (int i = 0; i < sinPointsToDraw.size() - 1; ++i)
        {
            DrawLine(sinPointsToDraw[i].x, sinPointsToDraw[i].y,
                     sinPointsToDraw[i + 1].x, sinPointsToDraw[i + 1].y, RED);
        }
    }
}
void pushPointsToAll()
{
    allPoints.push_back(sinPoints);
    allPoints.push_back(cosPoints);
    allPoints.push_back(tanPoints);
    allPoints.push_back(absPoints);
    allPointsToDraw.push_back(sinPointsToDraw);
    allPointsToDraw.push_back(cosPointsToDraw);
    allPointsToDraw.push_back(tanPointsToDraw);
    allPointsToDraw.push_back(absPointsToDraw);
}

/*
math:
    scaleX = 1200:50, ScreenWidth / 24
    sca;eY = 600:100, ScreenHeight / 6
*/
void InitPoints(float xStart, float xEnd, std::string Func)
{

    //----------------------------------------------------------------------------------------------------------
    float scaleX = (float)screenWidth / 24.0f; //( 1 unit on the x-axis = 50 pixels if scaleX = 50) 1200 : 50
    float scaleY = (float)screenWidth / 6.0f;  // ( 1 unit on the Y-axis = 100 pixels if scaleY = 100) 600 : 100
    int resolution = 10000;
    float step = (xEnd - xStart) / resolution;
    float offset = screenWidth / 2;
    for (char &c : Func)
    {
        c = std::tolower(c);
    }
    if (Func == "sin")
    {
        for (int i = 0; i <= resolution; ++i)
        {
            float x1 = xStart + (i * step);
            float y1 = sinf(x1) * scaleY;

            int sx1 = (int)(x1 * scaleX + offset);
            int sy1 = screenHeight / 2 - (int)(y1); // Flip y-axis

            sinPoints.push_back({float(sx1), float(sy1)});
        }
        sinIsCalled = true;
        sinInfo = {xStart, xEnd, Func};
    }
    else if (Func == "cos")
    {
        for (int i = 0; i <= resolution; ++i)
        {
            float x1 = xStart + (i * step);
            float y1 = cosf(x1) * scaleY;

            int sx1 = (int)(x1 * scaleX + offset);
            int sy1 = screenHeight / 2 - (int)(y1); // Flip y-axis

            cosPoints.push_back({float(sx1), float(sy1)});
        }
        cosIsCalled = true;
        cosInfo = {xStart, xEnd, Func};
    }
    if (Func == "tan")
    {
        for (int i = 0; i <= resolution; ++i)
        {
            float x1 = xStart + (i * step);
            float y1 = tanf(x1) * scaleY;

            int sx1 = (int)(x1 * scaleX + offset);
            int sy1 = screenHeight / 2 - (int)(y1); // Flip y-axis

            tanPoints.push_back({float(sx1), float(sy1)});
        }
        tanIsCalled = true;
        tanInfo = {xStart, xEnd, Func};
    }
    if (Func == "abs")
    {
        for (int i = 0; i <= resolution; ++i)
        {
            float x1 = xStart + (i * step);
            float y1 = fabsf(x1) * scaleY;

            int sx1 = (int)(x1 * scaleX + offset);
            int sy1 = screenHeight / 2 - (int)(y1); // Flip y-axis

            absPoints.push_back({float(sx1), float(sy1)});
        }
        absIsCalled = true;
        absInfo = {xStart, xEnd, Func};
    }
    animationIndex = 0;
}

/*
Funny things:
    - To draw a laser drawing out the line, change sinPointsToDraw.size() - 1 to sinPointsToDraw.size().
      This works because when the loop access an out of bounds array, the array auto points to {0,0}. Funny lol
    - **WARNING** Elliptic redrawing, careful for flash**WARNING**
      To draw mirage, just comment out DrawFPS(0, 0) in sin.cpp
*/
void AnimateFunc(std::string Func, Color color)
{
    for (char &c : Func)
    {
        c = std::tolower(c);
    }

    if (Func == "sin")
    {
        if (animationIndex + 1 < sinPoints.size())
        {
            sinPointsToDraw.push_back(sinPoints[animationIndex]);
            for (int i = 0; i < sinPointsToDraw.size() - 1; ++i)
            {
                DrawLine(sinPointsToDraw[i].x, sinPointsToDraw[i].y,
                         sinPointsToDraw[i + 1].x, sinPointsToDraw[i + 1].y, color);
            }
            animationIndex += 1;
        }
        else // if end is reached
        {
            for (int i = 0; i < sinPointsToDraw.size() - 1; ++i)
            {
                DrawLine(sinPointsToDraw[i].x, sinPointsToDraw[i].y,
                         sinPointsToDraw[i + 1].x, sinPointsToDraw[i + 1].y, color);
            }
        }
    }
    else if (Func == "cos")
    {
        if (animationIndex + 1 < cosPoints.size())
        {
            cosPointsToDraw.push_back(cosPoints[animationIndex]);
            for (int i = 0; i < cosPointsToDraw.size() - 1; ++i)
            {
                DrawLine(cosPointsToDraw[i].x, cosPointsToDraw[i].y,
                         cosPointsToDraw[i + 1].x, cosPointsToDraw[i + 1].y, color);
            }
            animationIndex += 1;
        }
        else // if end is reached
        {
            for (int i = 0; i < cosPointsToDraw.size() - 1; ++i)
            {
                DrawLine(cosPointsToDraw[i].x, cosPointsToDraw[i].y,
                         cosPointsToDraw[i + 1].x, cosPointsToDraw[i + 1].y, color);
            }
        }
    }
    else if (Func == "tan")
    {
        if (animationIndex + 1 < tanPoints.size())
        {
            tanPointsToDraw.push_back(tanPoints[animationIndex]);
            for (int i = 0; i < tanPointsToDraw.size() - 1; ++i)
            {
                DrawLine(tanPointsToDraw[i].x, tanPointsToDraw[i].y,
                         tanPointsToDraw[i + 1].x, tanPointsToDraw[i + 1].y, color);
            }
            animationIndex += 1;
        }
        else // if end is reached
        {
            for (int i = 0; i < tanPointsToDraw.size() - 1; ++i)
            {
                DrawLine(tanPointsToDraw[i].x, tanPointsToDraw[i].y,
                         tanPointsToDraw[i + 1].x, tanPointsToDraw[i + 1].y, color);
            }
        }
    }
    else if (Func == "abs")
    {
        if (animationIndex + 1 < absPoints.size())
        {
            absPointsToDraw.push_back(absPoints[animationIndex]);
            for (int i = 0; i < absPointsToDraw.size() - 1; ++i)
            {
                DrawLine(absPointsToDraw[i].x, absPointsToDraw[i].y,
                         absPointsToDraw[i + 1].x, absPointsToDraw[i + 1].y, color);
            }
            animationIndex += 1;
        }
        else // if end is reached
        {
            for (int i = 0; i < absPointsToDraw.size() - 1; ++i)
            {
                DrawLine(absPointsToDraw[i].x, absPointsToDraw[i].y,
                         absPointsToDraw[i + 1].x, absPointsToDraw[i + 1].y, color);
            }
        }
    }
}

/*
called when window size changes
resizing calculation:
*/
void resizePoints()
{
    for (std::vector<Vector2> &points : allPoints)
    {
        points.clear();
    }

    if (sinIsCalled)
    {
        InitPoints(sinInfo.start, sinInfo.end, sinInfo.Func);
    }
    if (cosIsCalled)
    {
        InitPoints(cosInfo.start, cosInfo.end, cosInfo.Func);
    }
    if (tanIsCalled)
    {
        InitPoints(tanInfo.start, tanInfo.end, tanInfo.Func);
    }
    if (absIsCalled)
    {
        InitPoints(absInfo.start, absInfo.end, absInfo.Func);
    }

    for (std::vector<Vector2> &pointsToDraw : allPointsToDraw)
    {
        pointsToDraw.clear();
    }
    animationIndex = 0;
}
//----------------------------------------------COORDINATE PLANE-------------------------------------------------------------

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