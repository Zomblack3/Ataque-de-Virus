#include "gameplay.h"

void gameplay(SCREENS& actualScreen, Player& player)
{
	updateGameplay(actualScreen, player);
	drawGameplay(player);
}

void updateGameplay(SCREENS& actualScreen, Player& player)
{
	if (slGetKey('a') || slGetKey('A'))
		if (player.x > player.width / 2)
			player.x -= 10;

	if (slGetKey('d') || slGetKey('D'))
		if (player.x < windowWidth - player.width / 2)
		player.x += 10;
}

void drawGameplay(Player player)
{
	slSetBackColor(0, 0, 0);

	slSetForeColor(1, 1, 1, 100);

	slRectangleFill(player.x, player.y, player.width, player.height);

	slRender();
}

