#pragma once
#include "ClasePadre.h"
#include "B_Pilas.h"
#include "ClaseBala.h"
#include<string.h>
#include<stdlib.h>
#include"MAPA.h"
enum DIRECCION { DERECHA, ARRIBA, ABAJO, IZQUIERDA, NINGUNO };
using namespace System;
using namespace System::Drawing;
class JUGADOR : public Objeto
{
protected:
	int ancho, alto, indice_ancho, indice_alto;
	char* nombre_imagen;
	MAPA* mapa;
	PilaBalas<Bala>* Municiones;
public:
	JUGADOR() : Objeto(200, 200, 0, 0)
	{
		/*dx = 0;
		dy = 0;
		x = 200;
		y = 200;*/
		alto = 0;
		ancho = 0;
		indice_ancho = 1;
		indice_alto = 1;
		nombre_imagen = new char[50];
		mapa = new MAPA();
		//------------------------------
		Municiones = new PilaBalas<Bala>();

	}
	~JUGADOR()
	{
		delete nombre_imagen;
	}
	void cambiar_imagen(char* _imagen)
	{
		strcpy(nombre_imagen, _imagen);
		Bitmap^ fotograma = gcnew Bitmap(gcnew String(nombre_imagen));
		alto = fotograma->Height / 4;
		ancho = fotograma->Width / 4;
		delete fotograma;
	}
	void pintar(Graphics^ can)
	{

		Bitmap^ im = gcnew Bitmap(gcnew String(nombre_imagen));
		Rectangle porcion(indice_ancho * ancho, indice_alto * alto, ancho, alto);
		can->DrawImage(im, x, y, porcion, GraphicsUnit::Pixel);
	}

	void mover(Graphics^ c, DIRECCION mov)
	{
		coalicion();
		if (x + dx < 1)dx = 0;
		if (y + dy < 1)dy = 0;
		if (x + ancho + dx > c->VisibleClipBounds.Width)dx = 0;
		if (y + alto + dy > c->VisibleClipBounds.Height)dy = 0;
		if (mov == DIRECCION::ABAJO) 		indice_alto = 0;
		if (mov == DIRECCION::IZQUIERDA)	indice_alto = 1;
		if (mov == DIRECCION::DERECHA)		indice_alto = 2;
		if (mov == DIRECCION::ARRIBA)		indice_alto = 3;

		indice_ancho++;
		if (indice_ancho > 3) indice_ancho = 0;
		x = x + dx;
		y = y + dy;
		pintar(c);
	}
	void agregar_direccion(DIRECCION tecla) {
		switch (tecla) {
		case ARRIBA:dx = 0; dy = -6; break;
		case ABAJO:dx = 0; dy = 6; break;
		case IZQUIERDA:dx = -6; dy = 0; break;
		case DERECHA:dx = 6; dy = 0; break;
			//case NINGUNO:dx = 0; dy = 0; break;
		default:break;
		}
	}
	void coalicion()
	{
		mapa->llenar_matriz();
		Rectangle jugador = Rectangle(x + dx, y + dy, ancho - 10, alto - 10);
		int xx, yy = 0;
		for (int i = 0; i < 15; i++)
		{
			xx = 0;
			for (int j = 0; j < 15; j++)
			{
				Rectangle cua = Rectangle(xx, yy, 50, 50);
				if (mapa->matriz()[i][j] == 1)
				{
					if (cua.IntersectsWith(jugador))
					{
						dx = 0;
						dy = 0;
					}
				}
				xx += 50;
			}
			yy += 50;
		}
	}
	int getOrientacion() { return indice_alto; }
	void agregar_x(int _x) { x = _x; }
	void agregar_y(int _y) { y = _y; }
	void agregar_dy(int _dy) { dy = _dy; }
	void agregar_dx(int _dx) { dx = _dx; }
	int mostrar_x() { return x; }
	int mostrar_y() { return y; }
	int mostrar_dx() { return dx; }
	int mostrar_dy() { return dy; }
	int mostrar_alto() { return alto; }
	int mostrar_ancho() { return ancho; }
	//////-----------------------------
	void recogerBala(Bala* balaSuelo)
	{
		// En el juego , apareceran balas aleatoriamente en el suelo cada cierto tiempo
		Municiones->addPila(balaSuelo);
	}
	Bala* dispararBala()
	{
		//El jugador retorna un objetoBala
		return Municiones->getPila();
	}
	int CuantasBalas()
	{
		return Municiones->getSize();
	}
};