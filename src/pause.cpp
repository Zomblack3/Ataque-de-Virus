#include "pause.h"

#include "gameplay.h"

void pause(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns])
{
	updatePause(actualScreen, player, ball, bricks);
	drawPause();
}

void updatePause(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns])
{
	if (slGetKey('c') || slGetKey('C'))
		actualScreen = GAMEPLAY;

	if (slGetKey('m') || slGetKey('M'))	
	{
		actualScreen = MAIN_MENU;
		resetGameplay(player, ball, bricks);
	}
}

void drawPause()
{
	slSetBackColor(0, 0, 0);

	slSetForeColor(1, 1, 0, 100);

	slText(windowWidth / 2.0f - ((6.0f / 3.0f) * 20.0f), (windowHeight / 2.0f) + 100, "PAUSA");
	
	slSetForeColor(1, 1, 1, 100);

	slText(windowWidth / 2.0f - ((26.0f / 3.0f) * 20.0f), windowHeight / 2.0f, "Presione C para continuar");
	slText(windowWidth / 2.0f - ((31.0f / 3.0f) * 20.0f), (windowHeight / 2.0f) - 50, "Presione M para volver al menu");

	slRender();
}
