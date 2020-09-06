#ifndef ELEMENTLIST_H
#define ELEMENTLIST_H

#include "element.h"
#include "sprite.h"
#include "haryball.h"

class Nodo
{
private:
	Element elemento;
	HaryBall elementoH;
public:
	Nodo*sig;
	Nodo(Element elemento)
	{
		this->elemento = elemento;
		sig = NULL;
	}

	Element getElemento()
	{
		return this->elemento;
	}

	HaryBall getElementoHary()
	{
		return this->elementoH;
	}

	void updateHaryElement()
	{
		this->elementoH.updateHary();
	}
};

class Lista
{
private:
	Nodo*primero;
	Nodo*ultimo;
	Sprite sprite;
public:
	Lista()
	{
		this->primero = this->ultimo = NULL;

	}

	~Lista()
	{
		while (this->primero == NULL)
		{
			this->borrarUltimo();
		}
	}

	bool vacio()
	{
		return (this->primero == NULL);
	}

	void initSprite(Graphics &graphics,std::string path,RGB_Color color)
	{
		this->sprite.loadSprite(graphics, path, &color);
	}

	int contarNodos()
	{
		Nodo*aux = this->primero;
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

	void ingresarDatoInicio(Element elemento)
	{
		Nodo*temp = new Nodo(elemento);
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

	void ingresarDatoFinal(Element elemento)
	{
		Nodo*temp = new Nodo(elemento);
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

	void ingresarDatoFinalH(HaryBall elemento)
	{
		Nodo*temp = new Nodo(elemento);
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

	void borrarPrimero()
	{
		if (this->vacio())
		{

		}
		else
		{
			if (this->primero == this->ultimo)
			{
				delete this->primero;
				this->primero = ultimo  = NULL;
			}
			else
			{
				Nodo*temp = this->primero;
				this->primero = this->primero->sig;
				delete temp;
				temp = NULL;
			}
		}
	}

	void borrarUltimo()
	{
		if (this->vacio())
		{

		}
		else
		{
			if (this->primero == this->ultimo)
			{
				delete this->primero;
				this->primero = this->ultimo = NULL;
			}
			else
			{
				Nodo*temp = this->ultimo;
				Nodo*aux = this->primero;
				while (aux != this->ultimo)
				{
					aux = aux->sig;
				}
				this->ultimo = aux;
				this->ultimo->sig = NULL;
				delete temp;
				aux = NULL;
				delete aux;
				temp = NULL;
			}
		}
	}

	void borrarNodo(Nodo *&nodo)
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
				Nodo*temp = this->ultimo;
				Nodo*aux = this->primero;
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
				Nodo*temp = this->primero;
				this->primero = this->primero->sig;
				delete temp;
			}
			else
			{
				Nodo*temp = nodo;
				Nodo*aux = this->primero;
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
			Nodo*aux = this->primero;
			int i = 0;
			while (aux != NULL)
			{
				aux->getElemento().print(graphics, this->sprite);
				aux = aux->sig;
				i++;
			}
			aux = NULL;
			delete aux;
			std::cout << "cant: " << i << std::endl;
		}
	}

	void recorrerLista()
	{
		if (vacio() == true)
		{

		}
		else
		{
			Nodo*aux = this->primero;
			while (aux != NULL)
			{
				bool repeat = false;
				//aux->updateAndMoveElemento();
				aux->updateHaryElement();
				if ((aux->getElemento().deleteFromList==true)|| (aux->getElementoHary().deleteFromList == true))
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
};

#endif