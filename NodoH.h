#pragma once
#include <string>
using namespace std;
template<typename T> class Nodo
{
private: T* elemento;
		 Nodo<T>* siguiente;

public:
	Nodo(T* elemento, Nodo<T>* siguiente = nullptr) : elemento(elemento), siguiente(siguiente) {}
	Nodo<T>* getSiguiente()
	{
		return siguiente;
	}
	T* getElemento()
	{
		return elemento;
	}
	void setSiguiente(Nodo<T>* siguiente)
	{
		this->siguiente = siguiente;
	}
	/*int getNodoX()
	{
	return elemento->getX();
	}
	int getNodoY()
	{
	return elemento->getY();
	}*/
	~Nodo() {}

};
#pragma once