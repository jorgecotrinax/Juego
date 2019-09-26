#pragma once
#include "ClasePadre.h"
using namespace System;
class Bala : public Objeto
{

protected:
	int velocidad, danio;
	float base, altura;
	int random;

public:
	Bala() : Objeto(0, 0, 0, 0)
	{
		//inicio dx n dy como 0  
		base = 20; altura = 20;
		danio = 1;
		velocidad = 5;
		//Random r;
		//random = r.Next(1, 25);

	}
	~Bala() {}
	void setDanio(int nuevo) { danio = nuevo; }

	void drawBala(Graphics^ buffer, SolidBrush^ pilot)
	{
		Pen^lapicero = gcnew Pen(Color::SkyBlue, 5);
		buffer->DrawEllipse(lapicero, x, y, 25, random);
		buffer->FillEllipse(pilot, x, y, 25, 25);
	

	}
	void LiberarBala(int pos, int x, int y)
	{
		this->x = x + 25;
		this->y = y + 25;
		switch (pos)
		{
		case 1:  //izq
			dx = -velocidad;
			dy = 0;

			break;

		case 2: //derech
			dx = velocidad;
			dy = 0;
			break;

		case 3: //arriba
			dx = 0;
			dy = -velocidad;
			break;

		case 0:
			dx = 0;
			dy = velocidad;
			break;

		default:break;
		}
	}
	void moverBala(Graphics^ buffer, SolidBrush^ pilot)
	{
		x += dx;
		y += dy;
		drawBala(buffer, pilot);
		//cout << dx << " \ t " << dy << endl;
	}
	bool ColisionEnemigos()
	{

	}
	/*string getdanio()
	{
	return to_string(danio);
	}*/
};