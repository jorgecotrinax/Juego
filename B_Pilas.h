#pragma once
#include <iostream>
#include "NodoH.h"
template<typename T> class PilaBalas
{
private:
	Nodo<T>* tope;
	int sizeMunicion;
	// Agregaremos el tope al inicio de cada PilaBalas
public:
	PilaBalas() : tope(NULL), sizeMunicion(0) {}
	int getSize() { return sizeMunicion; }
	void addPila(T* nuevaBala)
	{
		Nodo<T>* nuevo = new Nodo<T>(nuevaBala, tope);
		tope = nuevo;
		sizeMunicion = sizeMunicion + 1;
	}
	T* getPila()
	{
		if (sizeMunicion >= 1)
		{
			Nodo<T>* dameBala = tope;
			tope = tope->getSiguiente();
			sizeMunicion = sizeMunicion - 1;
			return dameBala->getElemento();

		}
	}
	/*void mostrarPila()
	{
	Nodo<T>* corredor = tope;
	std::cout << corredor->getElemento() << "\t ";
	while (corredor->getSiguiente() != nullptr)
	{
	corredor = corredor->getSiguiente();
	std::cout << corredor->getElemento() << "\t";
	}
	std::cout << endl;
	}*/

	~PilaBalas() {}


};