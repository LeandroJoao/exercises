#pragma once
#include "Barra.h"
#include "Pelota.h"

class Juego
{
	Barra* B1;
	Barra* B2;
	Pelota* P;

	int tiempo;
	clock_t start;
public:
	Juego()
	{
		B1 = new Barra(3);
		B2 = new Barra(ANCHO - 3);
		P = new Pelota();

		tiempo = 25;
		start = clock();
	}
	~Juego()
	{
		delete B1, B2, P;
	}

	void MostrarVariables()
	{
		Console::SetCursorPosition(10, 0);
		cout << "Jugador A: " << B1->GetPuntos();
		
		Console::SetCursorPosition(60, 0);
		cout << "Jugador B: " << B2->GetPuntos();

		Console::SetCursorPosition(35, ALTO - 1);
		cout << "              ";
		Console::SetCursorPosition(35, ALTO - 1);
		cout << "Tiempo: " << tiempo;
	}

	bool Validaciones()
	{
		if (B1->Colision(P->GetX() + P->GetDX(), P->GetY() + P->GetDY()))
			P->SetDX(P->GetDX() * (-1));

		if (B2->Colision(P->GetX() + P->GetDX(), P->GetY() + P->GetDY()))
			P->SetDX(P->GetDX() * (-1));

		if (P->GetX() == 0)
		{
			B2->SetPuntos(B2->GetPuntos() + 1);
			P->Borrar();
			delete P;
			P = new Pelota();
		}
		if (P->GetX() == ANCHO - 1)
		{
			B1->SetPuntos(B1->GetPuntos() + 1);
			P->Borrar();
			delete P;
			P = new Pelota();
		}

		if (tiempo == 0)
		{
			system("cls");
			Console::SetCursorPosition(35, ALTO / 2);
			if (B1->GetPuntos() > B2->GetPuntos())
				cout << "HA GANADO EL JUEGO";
			else if (B2->GetPuntos() > B1->GetPuntos())
				cout << "HA PERDIDO EL JUEGO";
			else
				cout << "HAN EMPATADO";
			_sleep(2000);
			return true;
		}

		return false;
	}

	void MoverPelota()
	{
		P->Borrar();
		P->Mover();
		P->Mostrar();
	}
	void MoverJugador(char tecla)
	{
		if (tecla == 'W')
			B1->SetDY(-1);
		else if (tecla == 'S')
			B1->SetDY(1);

		B1->Borrar();
		B1->Mover();
		B1->Mostrar();

		B1->SetDY(0);
	}
	void MoverCPU()
	{
		if (B2->GetY() + 1 > P->GetY())
			B2->SetDY(-1);
		else if (B2->GetY() + 1  < P->GetY())
			B2->SetDY(1);
		else
			B2->SetDY(0);

		B2->Borrar();
		B2->Mover();
		B2->Mostrar();
	}

	void Tiempo()
	{
		if (clock() - start >= CLOCKS_PER_SEC)
		{
			tiempo--;
			start = clock();
		}
	}
};