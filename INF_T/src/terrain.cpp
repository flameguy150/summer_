#include "terrain.h"
#include "globals.h"

/*
Draw 600 squares split diagonally
*/
void createFlatTerrain(int screenWidth, int screenHeight)
{
    DrawCube(originCubePosition, 1.0f, 1.0f, 1.0f, RED);
    DrawCubeWires(originCubePosition, 1.0f, 1.0f, 1.0f, BLACK);

    DrawCube(cubePosition, 1.0f, 1.0f, 1.0f, SKYBLUE);
    DrawCubeWires(cubePosition, 1.0f, 1.0f, 1.0f, BLACK);
    DrawGrid(100, 1.0f);
}