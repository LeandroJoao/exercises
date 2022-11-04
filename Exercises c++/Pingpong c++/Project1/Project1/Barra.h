#pragma once
#include "Entidad.h"

class Barra : public Entidad
{
private:
	int puntos;
public:
	Barra(int x)
	{
		this->x = x;
		y = ALTO / 2 - 2;
		dy = 0;

		puntos = 0;
		Mostrar();
	}

	void SetPuntos(int value)
	{
		puntos = value;
	}
	int GetPuntos()
	{
		return puntos;
	}

	void Borrar()
	{
		for (int i = 0; i < 4; i++)
		{
			Console::SetCursorPosition(x, y + i);
			cout << " ";
		}
	}
	void Mover()
	{
		if (y + dy >= 0 && y + 3 + dy  < ALTO)
			y += dy;
	}
	void Mostrar()
	{
		for (int i = 0; i < 4; i++)
		{
			Console::SetCursorPosition(x, y + i);
			cout << (char)219;
		}
	}

	bool Colision(int px, int py)
	{
		return (px == x && py >= y && py < y + 4);
	}
};