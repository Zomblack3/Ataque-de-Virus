#include "gameplay.h"

#include "math.h"

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
		ball.y = player.y + 40;
	}
	else
	{
		ball.x += ball.speedX;
		ball.y += ball.speedY;

		if (ballPlayerCollition(player, ball))
			ball.speedY *= -1.0f;

		if (ball.x < ball.radius || ball.x > windowWidth - ball.radius)
			ball.speedX *= -1.0f;

		if (ball.y > windowHeight - ball.radius)
			ball.speedY *= -1.0f;

		if (ball.y < 0)
			ball.isActive = false;
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

bool ballPlayerCollition(Player player, Ball ball)
{
	float closerPosX = ball.x;
	float closerPosY = ball.y;

	if (ball.x < player.x)         
		closerPosX = player.x;
	else if (ball.x > player.x + player.width) 
		closerPosX = player.x + player.width;
	if (ball.y < player.y)         
		closerPosY = player.y;
	else if (ball.y > player.y + player.height) 
		closerPosY = player.y + player.height;

	float distX = ball.x - closerPosX;
	float distY = ball.y - closerPosY;
	float distance = sqrt((distX * distX) + (distY * distY));

	if (distance <= ball.radius)
		return true;

	return false;
}

