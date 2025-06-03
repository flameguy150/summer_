#ifndef GLOBALS_H
#define GLOBALS_H

#include <cstddef>
#include <raylib.h>
#include <vector>

// Declare global variables

extern Font font;
extern size_t animationIndex;
extern std::vector<Vector2> sinPoints;
extern std::vector<Vector2> sinPointsToDraw;
extern int screenWidth;
extern int screenHeight;

#endif