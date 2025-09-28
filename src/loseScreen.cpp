#include "loseScreen.h"

#include "gameplay.h"

#include <string>

void loseScreen(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns])
{
	updateLoseScreen(actualScreen, player, ball, bricks);

	drawLoseScreen(player);
}

void updateLoseScreen(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns])
{
	if (slGetKey('r') || slGetKey('R'))
	{
		actualScreen = GAMEPLAY;

		resetGameplay(player, ball, bricks);
	}
}

void drawLoseScreen(Player player)
{
	std::string pointsText = "Puntos: " + std::to_string(player.points);

	slSetBackColor(0, 0, 0);

	slSetForeColor(1, 1, 1, 100);

	slText(windowWidth / 2.0f - (3.0f * 24.0f), (windowHeight / 2.0f) + 200, "PERDISTE");
	slText(windowWidth / 2.0f - (3.0f * 24.0f), windowHeight / 2.0f, pointsText.c_str());
	slText(windowWidth / 2.0f - (8.0f * 24.0f), (windowHeight / 2.0f) - 50, "Presione R para reiniciar");

	slRender();
}
