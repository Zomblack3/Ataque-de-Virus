#include "winScreen.h"

#include "gameplay.h"

#include <string>

void winScreen(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns])
{
	updateWinScreen(actualScreen, player, ball, bricks);

	drawWinScreen(player);
}

void updateWinScreen(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns])
{
	if (slGetKey('r') || slGetKey('R'))
	{
		actualScreen = GAMEPLAY;

		resetGameplay(player, ball, bricks);
	}
}

void drawWinScreen(Player player)
{
	std::string livesText = "Vidas: " + std::to_string(player.lives);
	std::string pointsText = "Puntos: " + std::to_string(player.points);
	
	slSetBackColor(0, 0, 0);
	
	slSetForeColor(1, 1, 1, 100);
	
	slText(windowWidth / 2.0f - (3.0f * 24.0f), (windowHeight / 2.0f) + 200, "GANASTE");
	slText(windowWidth / 2.0f - ((pointsText.size() / 3) * 24.0f), windowHeight / 2.0f, pointsText.c_str());
	slText(windowWidth / 2.0f - ((livesText.size() / 3) * 24.0f), (windowHeight / 2.0f) - 50, livesText.c_str());
	slText(windowWidth / 2.0f - (8.0f * 24.0f), (windowHeight / 2.0f) - 100, "Presione R para reiniciar");
	
	slRender();
}
