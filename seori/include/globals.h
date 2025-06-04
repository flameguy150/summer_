#ifndef GLOBALS_H
#define GLOBALS_H

#include <cstddef>
#include <raylib.h>
#include <vector>
#include <string>

// Declare global variables

extern int screenWidth;
extern int screenHeight;

extern Font font;
extern size_t animationIndex;

// extern bool animatingFlag;

extern std::vector<Vector2> sinPoints;
extern std::vector<Vector2> sinPointsToDraw;
extern std::vector<Vector2> cosPoints;
extern std::vector<Vector2> cosPointsToDraw;
extern std::vector<Vector2> tanPoints;
extern std::vector<Vector2> tanPointsToDraw;
extern std::vector<Vector2> absPoints;
extern std::vector<Vector2> absPointsToDraw;

#endif