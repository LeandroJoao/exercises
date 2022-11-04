#pragma once
#include "Entidad.h"

class Pelota : public Entidad
{
private:
	int dx;
public:
	Pelota()
	{
		x = ANCHO / 2;
		y = ALTO / 2;

		dy = rand() % 2;
		if (dy == 0)
			dy = -1;

		dx = rand() % 2;
		if (dx == 0)
			dx = -1;
	}

	int GetDX()
	{
		return dx;
	}
	void SetDX(int value)
	{
		dx = value;
	}

	void Borrar()
	{
		Console::SetCursorPosition(x, y);
		cout << " ";
	}
	void Mover()
	{
		if (x + dx < 0 || x + dx >= ANCHO)
			dx *= -1;
		if (y + dy < 1 || y + dy >= ALTO)
			dy *= -1;

		x += dx;
		y += dy;
	}
	void Mostrar()
	{
		Console::SetCursorPosition(x, y);
		cout << (char)254;
	}
};