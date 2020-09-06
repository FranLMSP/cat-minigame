#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <ctime>
#include <list>

using namespace::std;

namespace globals
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	const float SPRITE_SCALE = 1.0f;
}


enum Direction 
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};


struct RGB_Color
{
	int r, g, b;
};

#endif // GLOBALS_H
