#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include "sprite.h"
#include "haryball.h"
#include "enemy.h"

class Graphics;

class Butterfly :public Enemy
{
public:
	Butterfly();
	~Butterfly();

	void move(int speed);
	void update();
	void animation(int dif);
	bool limits();
		
protected:
	
};

/*class NodoButter
{
private:
	Butterfly elemento;
public:
	NodoButter*sig;
	NodoButter(Butterfly elemento)
	{
		this->elemento = elemento;
		sig = NULL;
	}
	Butterfly getElemento()
	{
		return this->elemento;
	}
	void updateAndMoveElemento()
	{
		this->elemento.move(6);
		this->elemento.update();
	}
};

class ListaButter
{
private:
	NodoButter*primero;
	NodoButter*ultimo;
	Sprite spriteButter;
public:
	ListaButter()
	{
		this->primero = this->ultimo = NULL;
	}
	
	bool vacio()
	{
		return (this->primero == NULL);
	}

	void initSprite(Graphics &graphics,std::string path)
	{
		RGB_Color color{ 38,130,232 };
		this->spriteButter.loadSprite(graphics, path, &color);
	}

	int contarNodos()
	{
		NodoButter*aux = this->primero;
		int i = 0;
		while (aux != NULL)
		{
			aux = aux->sig;
			i++;
		}
		aux = NULL;
		delete aux;
		return i;
	}

	void ingresarDatoInicio()
	{
		Butterfly elemento;
		NodoButter*temp = new NodoButter(elemento);
		if (vacio() == true)
		{
			this->primero = this->ultimo = temp;
		}
		else
		{
			temp->sig = this->primero;
			this->primero = temp;
		}
	}

	void ingresarDatoFinal()
	{
		Butterfly elemento;
		NodoButter*temp = new NodoButter(elemento);
		if (vacio() == true)
		{
			this->primero = this->ultimo = temp;
		}
		else
		{
			this->ultimo->sig = temp;
			this->ultimo = temp;
		}
	}

	void borrarNodo(NodoButter *&nodo)
	{

		if (this->vacio() == true)
		{

		}
		else
		{
			if (this->primero == this->ultimo)
			{
				delete primero;
				this->primero = this->ultimo = NULL;
			}
			else
			if (nodo == this->ultimo)
			{
				NodoButter*temp = this->ultimo;
				NodoButter*aux = this->primero;
				while (aux->sig->sig != NULL)
				{
					aux = aux->sig;
				}
				this->ultimo = aux;
				this->ultimo->sig = NULL;
				aux = NULL;
				delete aux;
				delete temp;
			}
			else
			if (nodo == this->primero)
			{
				NodoButter*temp = this->primero;
				this->primero = this->primero->sig;
				delete temp;
			}
			else
			{
				NodoButter*temp = nodo;
				NodoButter*aux = this->primero;
				while (aux->sig != temp)
				{
					aux = aux->sig;
				}
				aux->sig = temp->sig;
				delete temp;
			}
		}
	}

	void imprimirLista(Graphics &graphics)
	{
		if (vacio() == true)
		{

		}
		else
		{
			NodoButter*aux = this->primero;
			int i = 0;
			while (aux != NULL)
			{
				aux->getElemento().print(graphics, this->spriteButter);
				aux = aux->sig;
				i++;
			}
			aux = NULL;
			delete aux;
			std::cout << "cant: " << i << std::endl;
		}
	}

	void updateAndMove()
	{
		if (vacio() == true)
		{

		}
		else
		{
			NodoButter*aux = this->primero;
			while (aux != NULL)
			{
				bool repeat = false;
				aux->updateAndMoveElemento();
				if (aux->getElemento().deleteFromList)
				{
					this->borrarNodo(aux);
					aux = this->primero;
					repeat = true;
					this->ingresarDatoFinal();
				}
				if (!repeat)
					aux = aux->sig;
			}
			aux = NULL;
			delete aux;
		}
	}
};
*/

#endif