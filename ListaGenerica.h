#pragma once
#include "NodoH.h"
//
template<typename T> class ListaGenerica
{

private: int size;
		 Nodo<T>* ini;

public:
	ListaGenerica() : ini(nullptr), size(0) {}
	~ListaGenerica() {}
	int returnSize() { return size; }
	/*int compararXY(Nodo<T>* balaCandidata)
	{
	Nodo<T>* tempo = ini;
	for (int i = 0; i < size; i++)
	{
	if (tempo->getNodoX() == balaCandidata->getElemento()->getX() && balaCandidata->getElemento()->getY() == tempo->getElemento()->getY())
	{
	return i;
	}
	else { return -1; }
	}
	}*/
	void addNodo(T* elemento)
	{
		if (size < 1)
		{
			Nodo<T>* tempo = new Nodo<T>(elemento, ini);
			if (tempo != nullptr)
			{
				ini = tempo;
				size++;
			}
		}
		else
		{
			Nodo<T>* tempo = ini;
			while (tempo->getSiguiente() != nullptr)
			{
				tempo = tempo->getSiguiente();
			}
			Nodo<T>* nuevo = new Nodo<T>(elemento, tempo->getSiguiente());
			tempo->setSiguiente(nuevo);
			size++;
		}
	}
	void moverTodasBalas(Graphics^ buffer, SolidBrush^ pilot)
	{
		Nodo<T>* corredor = ini;

		for (int i = 0; i < size; i++)
		{
			corredor->getElemento()->moverBala(buffer, pilot);
			corredor = corredor->getSiguiente();
		}
	}
	void moverTodosEnemigos(Graphics^ buffer, SolidBrush^ pilot)
	{
		Nodo<T>* corredor = ini;

		for (int i = 0; i < size; i++)
		{
			corredor->getElemento()->moverEnemigo(buffer);
			corredor = corredor->getSiguiente();
		}
	}
	T* getBalaPorUbicacion(int x, int y)
	{
		Nodo<T>* comparador = ini;
		for (int i = 0; i < size; i++)
		{
			if (comparador->getElemento()->getX() == x && comparador->getElemento()->getY() == y)
			{
				return comparador->getElemento();
			}
			else
			{
				comparador = comparador->getSiguiente();
			}
		}
	}
	void borrarBalaPorColision(int x, int y)
	{
		/*Nodo<T>* comparador = ini;
		for (int i = 0; i < size; i++)
		{

		}*/
	}
	/*void borrarPos(Nodo<T>* balaCandidata)
	{
	if (compararXY(balaCandidata) >= 0)
	{
	if (compararXY(balaCandidata) == 0)
	{
	}
	else
	{
	Nodo<T>* corredor = ini;
	for (int i = 0; i < compararXY(balaCandidata) - 1; i++)
	{
	corredor = corredor->getSiguiente();
	}
	Nodo<T>* tempo1 = corredor->getSiguiente();
	corredor->setSiguiente(tempo1->getSiguiente());
	}
	}
	//utilizar X n Y para identificar que Bala fue

	}*/
};