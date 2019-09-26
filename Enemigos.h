#pragma once
#include "Jugador.h"
class Enemigos : public Objeto
{
private:
	int ancho, alto, indice_ancho, indice_alto;

public:
	Enemigos(int x0, int y0) : Objeto(x0, y0, 4, 4)
	{
		alto = 50;
		ancho = 50;
	}
	~Enemigos() {}
	void drawEnemigo(Graphics^ buffer)
	{
		buffer->DrawRectangle(gcnew Pen(Color::Pink, 2), x, y, alto, ancho);
	}
	void moverEnemigo(Graphics^ buffer)
	{
		if (x + dx < 50 || x + dx + ancho > 673)
			dx *= -1;
		if (y + dy + alto > 656 || y + dy < 50)
			dy *= -1;

		x += dx; y += dy;
		drawEnemigo(buffer);
	}
};