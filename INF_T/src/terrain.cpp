#include "terrain.h"
#include "globals.h"

/*
Draw 600 squares split diagonally
*/
void createFlatTerrain(int screenWidth, int screenHeight)
{
    DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
    DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
    DrawGrid(10, 1.0f);
}