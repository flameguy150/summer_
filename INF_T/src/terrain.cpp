#include "terrain.h"
#include "globals.h"
#include <math.h>

float noise(int x, int y)
{
    return sinf(x * 0.1f) * cosf(y * 0.1f);
}

/*
Draw 600 squares split diagonally
*/
void createFlatTerrain(int screenWidth, int screenHeight)
{

    for (int x = 0; x < TERRAIN_WIDTH; ++x)
    {
        for (int z = 0; z < TERRAIN_DEPTH; ++z)
        {
            float y = terrain[x][z];
            Vector3 cubePosition = {(float)x, y, (float)z};
            DrawCube(cubePosition, 1.0f, y, 1.0f, GREEN);
            DrawCubeWires(cubePosition, 1.0f, y, 1.0f, RED);
        }
    }

    DrawGrid(100, 1.0f);
}