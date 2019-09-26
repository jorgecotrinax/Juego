#pragma once
#include <string>
#include <stdio.h>
using namespace System::Drawing;
using namespace std;
using namespace System;
class Objeto
{
public:
	Objeto(int x, int y, int dx, int dy)
	{
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
	}
	~Objeto() {}
	int getX() { return x; }
	int getY() { return y; }
	int getDX() { return dx; }
	int getDY() { return dy; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setDX(int dx) { this->dx = dx; }
	void setDY(int dy) { this->dy = dy; }

protected:
	int x, y, dx, dy;
};
