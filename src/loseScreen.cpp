#include "loseScreen.h"

void loseScreen(SCREENS& actualScreen, Player& player, Ball& ball)
{
	updateLoseScreen(actualScreen, player, ball);

	drawLoseScreen(player);
}

void updateLoseScreen(SCREENS& actualScreen, Player& player, Ball& ball)
{
	if (slGetKey('r') || slGetKey('R'))
	{
		actualScreen = GAMEPLAY;

		player.lives = player.startingLives;
	}
}

void drawLoseScreen(Player player)
{
	slSetBackColor(0, 0, 0);

	slSetForeColor(1, 1, 1, 100);

	slText(windowWidth / 2.0f, (windowHeight / 2.0f) + 200, "PERDISTE");
	slText(windowWidth / 2.0f, windowHeight / 2.0f, "Presione R para reiniciar");

	slRender();
}
