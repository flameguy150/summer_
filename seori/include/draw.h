#ifndef DRAW_H
#define DRAW_H

#include <raylib.h>
#include "globals.h"

void DrawSinFunc(float xStart, float xEnd);
void DrawCosFunc(float xStart, float xEnd);
void DrawTanFunc(float xStart, float xEnd);
void InitSinPoints(float xStart, float xEnd);
void AnimateSinFunc();
void DrawNumericTicks();
void DrawRadianTicks();
void DrawCoordinatePlane();

#endif