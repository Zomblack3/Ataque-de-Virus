#include "gameplay.h"

void gameplay(SCREENS& actualScreen, Player& player, Ball& ball)
{
	updateGameplay(actualScreen, player, ball);
	drawGameplay(player, ball);
}

void updateGameplay(SCREENS& actualScreen, Player& player, Ball& ball)
{
	if (ball.isActive == false)
	{
		ball.x = player.x;
		ball.y = player.y + 30;
	}
	else
	{
		ball.x += ball.speedX;
		ball.y += ball.speedY;
	}

	if (slGetKey('a') || slGetKey('A'))
		if (player.x > player.width / 2)
			player.x -= 10;

	if (slGetKey('d') || slGetKey('D'))
		if (player.x < windowWidth - player.width / 2)
		player.x += 10;

	if (slGetKey(' '))
		if (ball.isActive == false)
			ball.isActive = true;
}

void drawGameplay(Player player, Ball ball)
{
	slSetBackColor(0, 0, 0);

	slSetForeColor(1, 1, 1, 100);

	slCircleFill(ball.x, ball.y, ball.radius, 100);
	slRectangleFill(player.x, player.y, player.width, player.height);

	slRender();
}

