#ifndef HARYBALL_H
#define HARYBALL_H

#include "sprite.h"
#include "bullet.h"

class Graphics;

class HaryBall : public Bullet
{
public:
	HaryBall();
	~HaryBall();

	void moveHary(int speed);
	void updateHary();
	//void initHary(int x, int y);

};

/*class NodoHary
{
private:
	HaryBall elemento;
public:
	NodoHary*sig;
	NodoHary(HaryBall elemento)
	{
		this->elemento = elemento;
		sig = NULL;
	}
	HaryBall getElemento()
	{
		return this->elemento;
	}
	void updateAndMoveElemento()
	{
		this->elemento.moveHary(8);
		this->elemento.updateHary();
	}
};

class ListaHary
{
private:
	NodoHary*primero;
	NodoHary*ultimo;
	Sprite spriteHary;
public:
	ListaHary()
	{
		this->primero = this->ultimo = NULL;

	}

	bool vacio()
	{
		return (this->primero == NULL);
	}

	void initSprite(Graphics &graphics)
	{
		RGB_Color color{ 255,255,255 };
		this->spriteHary.loadSprite(graphics, "dt/bllt/catBullet.pbm", &color);
	}

	int contarNodos()
	{
		NodoHary*aux=this->primero;
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

	void ingresarDatoInicio(HaryBall elemento)
	{
		NodoHary*temp = new NodoHary(elemento);
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

	void ingresarDatoFinal(HaryBall elemento)
	{
		NodoHary*temp = new NodoHary(elemento);
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

	void borrarPrimerElemento()
	{
		if (this->vacio() == true)
		{

		}
		else
		{
			if (this->primero==this->ultimo)
			{
				this->primero = this->ultimo = NULL;
			}
			else
			{
				Nodo*temp = this->primero;
				this->primero = this->primero->sig;
				delete temp;
			}
		}
	}

	void borrarUltimoElemento()
	{
		if (this->vacio() == true)
		{

		}
		else
		{
			Nodo*aux = this->primero;
			while (aux != NULL)
			{
				if (this->primero == this->ultimo)
				{
					this->primero = this->ultimo = NULL;
				}
				else
				if (aux->sig==this->ultimo)
				{
					Nodo*temp = this->ultimo;
					this->ultimo = aux;
					this->ultimo->sig = NULL;
					delete temp;
				}
				aux = aux->sig;
			}
		}
	}

	void borrarNodo(NodoHary *&nodo)
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
			if (nodo==this->ultimo)
			{
				NodoHary*temp = this->ultimo;
				NodoHary*aux = this->primero;
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
			if (nodo==this->primero)
			{
				NodoHary*temp = this->primero;
				this->primero = this->primero->sig;
				delete temp;
			}
			else
			{
				NodoHary*temp = nodo;
				NodoHary*aux=this->primero;
				while(aux->sig!=temp)
                {
                    aux=aux->sig;
                }
                aux->sig=temp->sig;
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
			NodoHary*aux = this->primero;
			int i = 0;
			while (aux != NULL)
			{
				aux->getElemento().print(graphics, this->spriteHary);
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
			NodoHary*aux = this->primero;
			while (aux != NULL)
			{
				bool repeat = false;
				aux->updateAndMoveElemento();
				if (aux->getElemento().deleteFromList)
				{
					this->borrarNodo(aux);
					aux = this->primero;
					repeat = true;
				}
				if (!repeat)
					aux = aux->sig;
			}
			aux = NULL;
			delete aux;
		}
	}
};*/

#endif // !HARYBALL_H

