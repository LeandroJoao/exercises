#pragma once
#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;
using namespace System;

#define ALTO 20
#define ANCHO 80

class Entidad
{
protected:
	int x, y;
	int dy;
public:
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	int GetDY()
	{
		return dy;
	}

	void SetX(int value)
	{
		x = value;
	}
	void SetY(int value)
	{
		y = value;
	}
	void SetDY(int value)
	{
		dy = value;
	}
};