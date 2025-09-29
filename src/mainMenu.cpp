#include "mainMenu.h"

#include "sl.h"

bool areTheControlesShown = false;
bool areTheRulesShown = false;

void mainMenu(SCREENS& actualScreen)
{
	updateMainMenu(actualScreen);

	drawMainMenu();
}

void updateMainMenu(SCREENS& actualScreen)
{
	if (!areTheControlesShown && !areTheRulesShown)
	{
		if (slGetKey('i') || slGetKey('I'))
			actualScreen = GAMEPLAY;

		if (slGetKey('c') || slGetKey('C'))
			areTheControlesShown = true;

		if (slGetKey('r') || slGetKey('R'))
			areTheRulesShown = true;
	}
	else
	{
		if (slGetKey('v') || slGetKey('V'))
		{
			if (areTheControlesShown)
				areTheControlesShown = false;

			if (areTheRulesShown)
				areTheRulesShown = false;
		}
	}
}

void drawMainMenu()
{
	slSetBackColor(0, 0, 0);

	slSetForeColor(1, 1, 1, 100);

	if (!areTheControlesShown && !areTheRulesShown)
	{
		slText(windowWidth / 2.0f - (6.0f * 24.0f), (windowHeight / 2.0f) + 200, "BREAKOUT PROJECT");
		slText(windowWidth / 2.0f - (10.5f * 24.0f), windowHeight / 2.0f, "Presione la tecla I para iniciar");
		slText(windowWidth / 2.0f - (13.0f * 24.0f), (windowHeight / 2.0f) - 50, "Presione la tecla C para ver los controles");
		slText(windowWidth / 2.0f - (13.0f * 24.0f), (windowHeight / 2.0f) - 100, "Presione la tecla R para ver las reglas");
		slText(windowWidth / 2.0f - (10.0f * 24.0f), (windowHeight / 2.0f) - 150, "Presione la tecla S para salir");
		slText(10, 10, "Hecho por Zomblack3 (Santiago Britos)");
	}
	else if (areTheControlesShown)
	{
		slText(windowWidth / 2.0f - (14.0f * 24.0f), (windowHeight / 2.0f) + 50, "Moverse (izquierda): A / Flecha izquierda");
		slText(windowWidth / 2.0f - (12.0f * 24.0f), windowHeight / 2.0f, "Moverse (derecha): D / Flecha derecha");
		slText(windowWidth / 2.0f - (11.0f * 24.0f), (windowHeight / 2.0f) - 50, "Iniciar partida; Barra espaciadora");
		slText(windowWidth / 2.0f - (3.0f * 24.0f), (windowHeight / 2.0f) - 100, "Pausa: P");
		slText(windowWidth / 2.0f - (10.0f * 24.0f), (windowHeight / 2.0f) - 150, "Presione V para volver al menu");
	}
	else
	{
		slText(windowWidth / 2.0f - (9.0f * 24.0f), (windowHeight / 2.0f) + 150, "El jugador debera eliminar a");
		slText(windowWidth / 2.0f - (11.0f * 24.0f), (windowHeight / 2.0f) + 100, "todos los ladrillos de la pantalla");
		slText(windowWidth / 2.0f - (11.0f * 24.0f), (windowHeight / 2.0f) + 50, "haciendo rebotar una bola en el,");
		slText(windowWidth / 2.0f - (11.0f * 24.0f), windowHeight / 2.0f, "cada vez que la bola rebote contra");
		slText(windowWidth / 2.0f - (12.0f * 24.0f), (windowHeight / 2.0f) - 50, "los ladrillos estos seran eliminados.");
		slText(windowWidth / 2.0f - (11.0f * 24.0f), (windowHeight / 2.0f) - 100, "En caso de que la pelota salga de");
		slText(windowWidth / 2.0f - (11.0f * 24.0f), (windowHeight / 2.0f) - 150, "la pantalla por el lado inferior");
		slText(windowWidth / 2.0f - (9.0f * 24.0f), (windowHeight / 2.0f) - 200, "el jugador perdera una vida,");
		slText(windowWidth / 2.0f - (13.0f * 24.0f), (windowHeight / 2.0f) - 250, "si pierde tres vidas pierde la partida");
		slText(windowWidth / 2.0f - (10.0f * 24.0f), (windowHeight / 2.0f) - 300, "Presione V para volver al menu");
	}


	slRender();
}
