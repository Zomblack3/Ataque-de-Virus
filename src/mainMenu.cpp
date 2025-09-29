#include "mainMenu.h"

#include "sl.h"

void mainMenu(SCREENS& actualScreen)
{
	updateMainMenu(actualScreen);

	drawMainMenu();
}

void updateMainMenu(SCREENS& actualScreen)
{
	if (slGetKey('i') || slGetKey('I'))
		actualScreen = GAMEPLAY;
}

void drawMainMenu()
{
	slSetBackColor(0, 0, 0);

	slSetForeColor(1, 1, 1, 100);

	slText(windowWidth / 2.0f - (6.0f * 24.0f), (windowHeight / 2.0f) + 200, "BREAKOUT PROJECT");
	slText(windowWidth / 2.0f - (10.5f * 24.0f), windowHeight / 2.0f, "Presione la tecla I para iniciar");
	slText(windowWidth / 2.0f - (10.0f * 24.0f), (windowHeight / 2.0f) - 50, "Presione la tecla S para salir");
	slText(10, 10, "Hecho por Zomblack3 (Santiago Britos)");

	slRender();
}
