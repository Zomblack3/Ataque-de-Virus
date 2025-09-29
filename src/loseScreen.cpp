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

	if (slGetKey('m') || slGetKey('M'))
	{
		actualScreen = MAIN_MENU;

		resetGameplay(player, ball, bricks);
	}
}

void drawLoseScreen(Player player)
{
	std::string pointsText = "Puntos: " + std::to_string(player.points);

	slSetBackColor(0, 0, 0);

	slSetForeColor(1, 0, 0, 100);

	slText(windowWidth / 2.0f - (2.5f * 20.0f), (windowHeight / 2.0f) + 100, "PERDISTE");
	
	slSetForeColor(1, 1, 1, 100);
	
	slText(windowWidth / 2.0f - ((pointsText.size() / 3.0f) * 20.0f), windowHeight / 2.0f, pointsText.c_str());
	
	slSetForeColor(0.25f, 1, 0, 100);
	
	slText(windowWidth / 2.0f - (8.0f * 20.0f), (windowHeight / 2.0f) - 50, "Presione R para reiniciar");
	
	slSetForeColor(0, 1, 0.25f, 100);
	
	slText(windowWidth / 2.0f - (10.0f * 20.0f), (windowHeight / 2.0f) - 100, "Presione M para volver al menu");

	slRender();
}
