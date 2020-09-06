#include "game.h"
#include <iostream>

Game::Game()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Init error" << SDL_GetError() << std::endl;
	}



	this->player.init(this->graphics, "dt/chr/chr.pbm");

	this->enemys.initSprites(this->graphics);

	//temporal:
	this->enemys.newButterfly();

	this->debug.init(this->graphics);
	this->hud.init(this->graphics);
	this->gameLoop();
		
}

void Game::gameLoop()
{
	bool loop=true;
	
	while (loop)
	{
		this->startFframe();

		this->readInputs();
		

		this->endFrame();
	}
}

void Game::readInputs()
{
	this->pollEvent();
	if (this->input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
	{

	}
	else
	if ((this->input.isKeyHeld(SDL_SCANCODE_LEFT) == true)|| (this->input.isKeyHeld(SDL_SCANCODE_A) == true))
	{
		this->player.moveLeft();
	}
	if ((this->input.isKeyHeld(SDL_SCANCODE_RIGHT) == true)|| (this->input.isKeyHeld(SDL_SCANCODE_D) == true))
	{
		this->player.moveRight();
	}
	if ((this->input.isKeyHeld(SDL_SCANCODE_UP) == true)|| (this->input.isKeyHeld(SDL_SCANCODE_W) == true))
	{
		this->player.moveUp();
	}
	if ((this->input.isKeyHeld(SDL_SCANCODE_DOWN) == true)|| (this->input.isKeyHeld(SDL_SCANCODE_S) == true))
	{
		this->player.moveDown();
	}
	if ((this->input.wasKeyPressed(SDL_SCANCODE_X) == true)|| (this->input.wasKeyPressed(SDL_SCANCODE_K) == true))
	{
		this->player.attack();
	}
	if ((this->input.isKeyHeld(SDL_SCANCODE_E) == true))
	{
		this->player.hurt(1);
	}
	if (this->input.isKeyHeld(SDL_SCANCODE_F1) == true)
	{
		this->debug.viewOptions = true;
	}
	if (this->input.wasKeyReleased(SDL_SCANCODE_F1) == true)
	{
		this->debug.viewOptions = false;
	}
	if (this->input.wasKeyPressed(SDL_SCANCODE_F2) == true)
	{
		this->debug.swichPlayerXY();
	}
	if (this->input.wasKeyPressed(SDL_SCANCODE_F3) == true)
	{
		this->debug.swichPlayerCenter();
	}
	if (this->input.wasKeyPressed(SDL_SCANCODE_F4) == true)
	{
		this->debug.swichPlayerHitboxesXY();
	}
	if (this->input.wasKeyPressed(SDL_SCANCODE_F5) == true)
	{
		this->debug.swichPlayerLife();
	}
	if (this->input.wasKeyPressed(SDL_SCANCODE_F6) == true)
	{
		this->debug.swichPlayerLive();
	}
	if (this->input.wasKeyPressed(SDL_SCANCODE_F7) == true)
	{
		this->debug.swichCantBullets();
	}
	if (this->input.wasKeyPressed(SDL_SCANCODE_F8) == true)
	{
		this->debug.swichCantEntities();
	}
	if (this->input.wasKeyPressed(SDL_SCANCODE_F9) == true)
	{
		this->debug.swichCantEnemies();
	}
	if (this->input.wasKeyPressed(SDL_SCANCODE_F10) == true)
	{
		this->debug.swichPlayerHitboxes();
	}
	if (this->input.wasKeyPressed(SDL_SCANCODE_F11) == true)
	{
		this->debug.swichEntitiesHitboxes();
	}
	if (this->input.wasKeyPressed(SDL_SCANCODE_F12) == true)
	{
		this->debug.swichAll();
	}
	if ((this->input.wasKeyReleased(SDL_SCANCODE_X) == true)|| (this->input.wasKeyReleased(SDL_SCANCODE_K) == true))
	{
		this->player.releasedKey(true);
	}

}

void Game::draw()
{
	this->graphics.clear();

	this->player.print(this->graphics, this->player.sprite);

	this->enemys.printAll(this->graphics);

	this->player.drawBullets(this->graphics);
	this->hud.drawLifeBar(this->graphics, 20, 20, 100, 0, this->player.getLife(), 2);
	this->hud.drawLives(this->graphics, this->player.getLives(), (globals::SCREEN_WIDTH-20) / 2,35 );
	//this->hud.drawLives(this->graphics, this->player.balas.contarNodos(), (globals::SCREEN_WIDTH - 20) / 2, 35);

	this->debug.printAll(this->player.getCantBullets() + this->enemys.getCant() + 1, this->enemys.getCant(), this->player.getCantBullets(), this->player.getLife(), this->player.getLives(), this->player.getX(), this->player.getY(), this->player.getHU(), this->player.getHD(), this->player.getHL(), this->player.getHR(), this->graphics);

	this->graphics.flip();
}

void Game::pollEvent()
{
	if (SDL_PollEvent(&this->event))
	{
		if (this->event.type == SDL_KEYDOWN)
		{

			if (this->event.key.repeat == 0)
			{
				this->input.KeyDownEvent(this->event);
			}
		}
		else
		if (this->event.type == SDL_KEYUP)
		{
			this->input.KeyUpEvent(this->event);
		}
		else
		if (this->event.type == SDL_QUIT)
		{
			this->~Game();
		}
	}
}

void Game::startFframe()
{
	this->fps.start();
	this->input.beginNewFrame();
}

void Game::endFrame()
{
	this->player.update();
	this->enemys.updateAll();

	this->draw();
	this->frame++;
	this->delayFrame();	
}

void Game::delayFrame()
{
	if ((this->cap == true) && (this->fps.getTicks() < (1000 / ((size_t) this->MAX_FPS))))
	{
		SDL_Delay((1000 / this->MAX_FPS) - fps.getTicks());
	}
}

Game::~Game()
{
	SDL_Quit();
	return;
}