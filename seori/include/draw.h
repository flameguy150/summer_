#ifndef DRAW_H
#define DRAW_H

#include <raylib.h>
#include "globals.h"

/*
will use this to call initpoints in resize
*/

void DrawSinFunc(float xStart, float xEnd);
void DrawCosFunc(float xStart, float xEnd);
void DrawTanFunc(float xStart, float xEnd);
//----------------------------------------------ANIMATION-------------------------------------------------------------
void InitSinPoints(float xStart, float xEnd);
void AnimateSinFunc();
// void InitCosPoints(float xStart, float xEnd);
// void AnimateCosFunc();
// void InitTanPoints(float xStart, float xEnd);
// void AnimateTanFunc();
void pushPointsToAll();

void InitPoints(float xStart, float xEnd, std::string Func);
void AnimateFunc(std::string Func, Color color);
void resizePoints();

//--------------------------------------------------------------------------------------------------------------------
void DrawNumericTicks();
void DrawRadianTicks();
void DrawCoordinatePlane();

#endif