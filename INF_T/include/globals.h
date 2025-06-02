// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

#include <raylib.h>

#define TERRAIN_WIDTH 200
#define TERRAIN_DEPTH 200

// Declare global variables
extern Camera3D camera;
extern Vector3 originCubePosition;
extern Vector3 cubePosition;

extern float terrain[TERRAIN_WIDTH][TERRAIN_DEPTH];

#endif