#include "globals.h"
#include <vector>

// bool animatingFlag = true;

std::vector<Vector2> sinPoints;
std::vector<Vector2> sinPointsToDraw;
std::vector<Vector2> cosPoints;
std::vector<Vector2> cosPointsToDraw;
std::vector<Vector2> tanPoints;
std::vector<Vector2> tanPointsToDraw;
std::vector<Vector2> absPoints;
std::vector<Vector2> absPointsToDraw;

std::vector<std::vector<Vector2>> allPoints;
std::vector<std::vector<Vector2>> allPointsToDraw;

bool sinIsCalled = false;
bool cosIsCalled = false;
bool tanIsCalled = false;
bool absIsCalled = false;

std::vector<Vector2> pointClearHelper; // for resizing

WaveInfo sinInfo;
WaveInfo cosInfo;
WaveInfo tanInfo;
WaveInfo absInfo;

size_t animationIndex = 0;