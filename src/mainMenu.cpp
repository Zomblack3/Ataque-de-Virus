#include "mainMenu.h"

#include "sl.h"

bool areTheControlesShown = false;

void mainMenu(SCREENS& actualScreen)
{
	updateMainMenu(actualScreen);

	drawMainMenu();
}

void updateMainMenu(SCREENS& actualScreen)
{
	if (!areTheControlesShown)
	{
		if (slGetKey('i') || slGetKey('I'))
			actualScreen = GAMEPLAY;

		if (slGetKey('c') || slGetKey('C'))
			areTheControlesShown = true;
	}
	else
	{
		if (slGetKey('v') || slGetKey('V'))
			areTheControlesShown = false;
	}
}

void drawMainMenu()
{
	slSetBackColor(0, 0, 0);

	slSetForeColor(1, 1, 1, 100);

	if (!areTheControlesShown)
	{
		slText(windowWidth / 2.0f - (6.0f * 24.0f), (windowHeight / 2.0f) + 200, "BREAKOUT PROJECT");
		slText(windowWidth / 2.0f - (10.5f * 24.0f), windowHeight / 2.0f, "Presione la tecla I para iniciar");
		slText(windowWidth / 2.0f - (13.0f * 24.0f), (windowHeight / 2.0f) - 50, "Presione la tecla C para ver los controles");
		slText(windowWidth / 2.0f - (10.0f * 24.0f), (windowHeight / 2.0f) - 100, "Presione la tecla S para salir");
		slText(10, 10, "Hecho por Zomblack3 (Santiago Britos)");
	}
	else
	{
		slText(windowWidth / 2.0f - (14.0f * 24.0f), (windowHeight / 2.0f) + 50, "Moverse (izquierda): A / Flecha izquierda");
		slText(windowWidth / 2.0f - (12.0f * 24.0f), windowHeight / 2.0f, "Moverse (derecha): D / Flecha derecha");
		slText(windowWidth / 2.0f - (11.0f * 24.0f), (windowHeight / 2.0f) - 50, "Iniciar partida; Barra espaciadora");
		slText(windowWidth / 2.0f - (3.0f * 24.0f), (windowHeight / 2.0f) - 100, "Pausa: P");
		slText(windowWidth / 2.0f - (10.0f * 24.0f), (windowHeight / 2.0f) - 150, "Presione V para volver al menu");
	}

	slRender();
}
