#include "gameplay.h"

#include "math.h"

int pauseButtonInputTimer = 0;
bool isPauseOn = false;

void gameplay(SCREENS& actualScreen, Player& player, Ball& ball)
{
	updateGameplay(actualScreen, player, ball);
	drawGameplay(player, ball);
}

void updateGameplay(SCREENS& actualScreen, Player& player, Ball& ball)
{
	if (!isPauseOn)
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

			if (ball.untouchableTimer <= 0)
			{
				/*if (ballCollitionTest(player, ball))
				{
					ball.speedY *= -1.0f;
					ball.speedX = (ball.x - player.x) / player.width * 5;

					ball.untouchableTimer = 10;
				}*/

				ballPlayerCollition(player, ball);
			}
			else
				ball.untouchableTimer--;

			if (ball.x < ball.radius || ball.x > windowWidth - ball.radius)
				ball.speedX *= -1.0f;

			if (ball.y > windowHeight - ball.radius)
				ball.speedY *= -1.0f;

			if (ball.y < 0)
			{
				ball.isActive = false;

				ball.speedX = ball.startSpeedX;
				ball.speedY = ball.startSpeedY;
			}
		}
	}

	//bool isFuckingballColliding = ballPlayerCollition(player, ball);

	if (pauseButtonInputTimer == 0)
	{
		if (slGetKey('p') || slGetKey('P'))
		{
			if (isPauseOn)
				isPauseOn = false;
			else
				isPauseOn = true;

			pauseButtonInputTimer = 50;
		}
	}
	else
		pauseButtonInputTimer--;

	if (slGetKey('a') || slGetKey('A') || slGetKey(SL_KEY_LEFT))
		if (player.x > player.width / 2)
			player.x -= 10;

	if (slGetKey('d') || slGetKey('D') || slGetKey(SL_KEY_RIGHT))
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

	slRectangleFill(player.x, player.y, player.width, player.height);
	slCircleFill(ball.x, ball.y, ball.radius, 100);

	slRender();
}

void ballPlayerCollition(Player player, Ball& ball)
{
	if (ball.y - ball.radius <= (player.y + (player.height / 2)))
	{
		if ((ball.x + (ball.radius / 2)) >= (player.x - (player.width / 2)) && (ball.x - (ball.radius / 2)) <= (player.x + (player.width / 2)))
		{
			ball.speedY *= -1.0f;
			ball.speedX = (ball.x - player.x) / player.width * 5;
		}
	}
}

