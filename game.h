#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "ltimer.h"
#include "input.h"
#include "graphics.h"
#include "player.h"
#include "butterfly.h"
#include "enemylist.h"
#include "debugmode.h"
#include "hud.h"

class Game
{
public:
	Game();
	~Game();

	void gameLoop();

private:
	const char MAX_FPS = 60;
	int frame = 0;
	bool cap = true;
	LTimer fps;

	Player player;
	EnemyList enemys;
	Hud hud;

	SDL_Event event;
	Input input;
	Graphics graphics;

	//temporal
	Debugmode debug;

	void readInputs();
	void startFframe();
	void endFrame();
	void delayFrame();

	void draw();

	void pollEvent();
};

#endif // !GAME_H
