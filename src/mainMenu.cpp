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

	if (slGetKey('s') || slGetKey('S'))
		actualScreen = EXIT;
}

void drawMainMenu()
{
	slSetBackColor(0, 0, 0);

	slSetForeColor(1, 1, 1, 100);

	slText(windowWidth / 2.0f - (3.0f * 24.0f), (windowHeight / 2.0f) + 200, "BREAKOUT");
	slText(windowWidth / 2.0f - (11.0f * 24.0f), windowHeight / 2.0f, "Presione la tecla I para iniciar");
	slText(windowWidth / 2.0f - (11.0f * 24.0f), (windowHeight / 2.0f) - 50, "Presione la tecla S para salir");

	slRender();
}
