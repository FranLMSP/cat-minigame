#include "player.h"

int frameCounter = 0;
int deadFrameCounter = 0;

Player::Player()
{
	this->setElement(100, 100, 35, 58);
	this->setSourceAndDest(0, 0, 35, 58);

	this->speed = 5;
	this->state = 1;
	this->life = MAXLIFE;
	this->lives = 3;
}

void Player::init(Graphics &graphics, std::string path)
{
	RGB_Color color{ 255,255,255 };
	this->spriteBalas.loadSprite(graphics,"dt/bllt/catBullet.pbm",&color);
	color= { 0,0,0 };
	this->sprite.loadSprite(graphics, path,&color);
	this->_visible = true;

}

void Player::moveUp()
{
	this->setY(this->getY() - speed);
}

void Player::moveDown()
{
	this->setY(this->getY() + speed);
}

void Player::moveLeft()
{
	this->setX(this->getX() - speed);
}

void Player::moveRight()
{
	this->setX(this->getX() + speed);
}

void Player::speedUp(char cant)
{
	this->speed += cant;
}

void Player::hurt(int damage)
{
	this->life -= damage;
}

void Player::dead()
{
	this->state = 4;
	this->lives--;
}

void Player::attack()
{
	if ((this->state == 1)&&(this->_releasedKey==true))
	{
		this->setSourceY(59);
		this->state = 2;
		this->releasedKey(false);

		HaryBall elemento;
		elemento.setElement(this->getX() + 30, this->getY() + 14, 15, 15);
		elemento.setSource(0, 0, 15, 15);
		elemento.updateHary();
		this->balas.push_back(new HaryBall(elemento));
	}
}

void Player::reloadAttack(int frames)
{
	if (frameCounter < frames)
	{
		frameCounter++;
	}
	else
	{
		frameCounter = 0;
		this->state = 1;
		this->setSourceY(0);
	}
}

void Player::releasedKey(bool rel)
{
	this->_releasedKey = rel;
}

void Player::update()
{
	
	this->updateBullets();

	if (this->getX() < 0)
		this->setX(0);
	if (this->getY() < 0)
		this->setY(0);
	if (this->getX() + 35 > globals::SCREEN_WIDTH)
		this->setX(globals::SCREEN_WIDTH - 35);
	if (this->getY() + 58 > globals::SCREEN_HEIGHT)
		this->setY(globals::SCREEN_HEIGHT - 58);

	if (this->state == 2)
	{
		this->reloadAttack(30);
	}

	if (this->life <= 0)
	{
		this->life = MAXLIFE;
		this->lives--;
	}

	this->setDest();
}

void Player::drawBullets(Graphics &graphics)
{
	list<HaryBall*>::iterator it;

	for (it = this->balas.begin(); it != this->balas.end(); it++)
	{
		(*it)->print(graphics,this->spriteBalas);
	}
}

void Player::updateBullets()
{
	list<HaryBall*>::iterator it;

	for (it = this->balas.begin(); it != this->balas.end(); it++)
	{
		(*it)->updateHary();
		if ((*it)->deleteFromList)
		{
			delete(*it);
			it = this->balas.erase(it);
			break;
		}
	}
}

int Player::getLife()
{
	return this->life;
}

int Player::getMaxLife()
{
	return MAXLIFE;
}

int Player::getLives()
{
	return this->lives;
}

Player::~Player()
{
	this->sprite.~Sprite();
}