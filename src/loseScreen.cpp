#include "loseScreen.h"

#include "gameplay.h"

#include <string>

void loseScreen(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns], int backgroundTexture)
{
	updateLoseScreen(actualScreen, player, ball, bricks);

	drawLoseScreen(player, backgroundTexture);
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

void drawLoseScreen(Player player, int backgroundTexture)
{
	std::string pointsText = "Puntos: " + std::to_string(player.points);

	slSetBackColor(0, 0, 0);

	slSetForeColor(1, 0, 0, 100);

	slSprite(backgroundTexture, windowWidth / 2.0f, windowHeight / 2.0f, windowWidth, windowHeight);

	slText(windowWidth / 2.0f - ((22.0f / 3.0f) * 20.0f), (windowHeight / 2.0f) + 150, "SU COMPUTADORA A SIDO");

	slRectangleFill(windowWidth / 2.0f, (windowHeight / 2.0f) + 110, (10.0f * 20.0f), 30);
	
	slSetForeColor(1, 1, 1, 100);

	slText(windowWidth / 2.0f - ((10.0f / 3.0f) * 20.0f), (windowHeight / 2.0f) + 100, "INFECTADA");
	
	slSetForeColor(1, 1, 0, 100);
	
	slText(windowWidth / 2.0f - ((pointsText.size() / 3.0f) * 20.0f), windowHeight / 2.0f + 25, pointsText.c_str());
	slText(windowWidth / 2.0f - (8.0f * 20.0f), (windowHeight / 2.0f) - 25, "Presione R para reiniciar");
	slText(windowWidth / 2.0f - (10.0f * 20.0f), (windowHeight / 2.0f) - 75, "Presione M para volver al menu");

	slRender();
}
