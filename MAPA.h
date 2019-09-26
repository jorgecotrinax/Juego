#pragma once

using namespace System;
using namespace System::Drawing;
class MAPA
{
private:
	int** mapa;
	int n;
public:
	MAPA()
	{
		n = 15;
		mapa = new int*[n];
	}
	~MAPA() {}
	void llenar_matriz()
	{
		for (int i = 0; i < n; i++)
		{
			mapa[i] = new int[n];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
				{
					mapa[i][j] = 1;
				}
				else
				{
					mapa[i][j] = 0;
				}
			}
		}
	}
	void pintar(Graphics^ g, Image^ borde)
	{
		llenar_matriz();
		int x, y = 0;
		for (int i = 0; i < n; i++)
		{
			x = 0;
			for (int j = 0; j < n; j++)
			{
				if (mapa[i][j] == 1)
				{
					g->DrawImage(borde, x, y, 50, 50);
				}
				x += 50;
			}
			y += 50;
		}
	}
	int **matriz() { return mapa; }
};
