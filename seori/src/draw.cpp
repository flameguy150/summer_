#include "draw.h"
#include <math.h>

void drawLilSinFunc(float xStart, float xEnd)
{
    float scaleX = 10.0f;
    float scaleY = 10.0f;
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
 * @param xStart Where the line starts on screen, X coord
 * @param yStart Where the line starts on screen, Y coord
 * @param xEnd Where the line ends on screen, X coord
 * @param yEnd Where the line ends on screen, Y coord
 * @param scaleX X scaling info for converting sin to drawing on screen ( 1 unit on the x-axis = 50 pixels if scaleX = 50)
 * @param scaleY Y scaling info for converting sin to drawing on screen ( 1 unit on the Y-axis = 100 pixels if scaleY = 100)
 **/
void drawSinFunc(float xStart, float xEnd)
{
    float scaleX = 50.0f;
    float scaleY = 50.0f;
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

void drawCoordinatePlane()
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
}