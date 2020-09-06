#ifndef HUD_H
#define HUD_H

#include "sprite.h"
#include "globals.h"
#include "element.h"

#define BLUE 1
#define RED 2

class Graphics;

class Hud : public Element
{
public:
	void init(Graphics &graphics);
	void drawLifeBar(Graphics &graphics,int x, int y,int w,int h,int life,int color);
	void drawLives(Graphics &graphics,int lives,int x,int y);

	void putIzq(Graphics &graphics, int x, int y);
	void putDer(Graphics &graphics, int x, int y);
	void putLifeBar(Graphics &graphics, int x, int y, int color);
	void putLife(Graphics &graphics, int x, int y, int color);

	void setNumbs(int x, int y);
	
private:
	Sprite sprite;
	SDL_Rect numbs[10];
};

#endif // !HUD_H
