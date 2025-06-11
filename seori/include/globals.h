#ifndef GLOBALS_H
#define GLOBALS_H

#include <cstddef>
#include <raylib.h>
#include <vector>
#include <string>

// Declare global variables

struct WaveInfo
{
    float start;
    float end;
    std::string Func;
};

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

extern std::vector<std::vector<Vector2>> allPoints;
extern std::vector<std::vector<Vector2>> allPointsToDraw;

extern bool sinIsCalled;
extern bool cosIsCalled;
extern bool tanIsCalled;
extern bool absIsCalled;
extern std::vector<Vector2> pointClearHelper;

extern WaveInfo sinInfo;
extern WaveInfo cosInfo;
extern WaveInfo tanInfo;
extern WaveInfo absInfo;

#endif