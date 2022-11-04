#include "Juego.h"

int main()
{
	srand(time(NULL));
	Console::SetWindowSize(ANCHO, ALTO);
	Console::CursorVisible = false;

	Juego* J = new Juego();

	for (int t = 0; true; t++)
	{
		if (J->Validaciones() == true)
			break;

		if (t == 2000)
		{
			J->MostrarVariables();
			J->MoverPelota();
			J->MoverCPU();
			t = 0;
		}
		if (_kbhit())
		{
			char tecla = toupper(_getch());
			J->MoverJugador(tecla);
		}
		J->Tiempo();
	}

	delete J;

	return 0;
}