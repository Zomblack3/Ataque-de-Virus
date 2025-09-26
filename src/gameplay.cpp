#include "gameplay.h"

#include <string>

int pauseButtonInputTimer = 0;

double miliseconds = 0.0f;
int seconds = 0;
int minutes = 0;

bool isPauseOn = false;

void gameplay(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns], int ballTexture)
{
	updateGameplay(actualScreen, player, ball, bricks);
	drawGameplay(player, ball, bricks, ballTexture);
}

static void updateGameplay(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns])
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
				ballPlayerCollition(player, ball);

				ballBrickCollition(bricks, ball, player);
			}
			else
				ball.untouchableTimer--;

			if (ball.x < ball.radius || ball.x > windowWidth - ball.radius)
				ball.speedX *= -1.0f;

			if (ball.y > (windowHeight - 45) - ball.radius)
				ball.speedY *= -1.0f;

			if (ball.y < 0)
			{
				ball.isActive = false;

				ball.speedX = ball.startSpeedX;
				ball.speedY = ball.startSpeedY;

				player.lives--;
			}
		}
	}

	if (pauseButtonInputTimer == 0)
	{
		if (slGetKey('p') || slGetKey('P') || slGetKey(SL_KEY_ESCAPE))
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
		if (player.x > player.width / 2.0f)
			player.x -= 10;

	if (slGetKey('d') || slGetKey('D') || slGetKey(SL_KEY_RIGHT))
		if (player.x < windowWidth - player.width / 2.0f)
		player.x += 10;

	if (slGetKey(' '))
		if (ball.isActive == false)
			ball.isActive = true;

	miliseconds += slGetDeltaTime();

	if (miliseconds >= 1.0f)
	{
		seconds++;
		miliseconds = 0.0f;
	}

	if (seconds >= 60)
	{
		minutes++;
		seconds = 0;
	}

	// kill command
	if (slGetKey('/') && slGetKey('k') || slGetKey('K'))
		player.lives = 0;

	if (haveToResetBricks(bricks))
	{
		ball.isActive = false;

		ball.speedX = ball.startSpeedX;
		ball.speedY = ball.startSpeedY;

		for (int j = 0; j < amountOfBricksCollumns; j++)
			for (int i = 0; i < amountOfBricksRow; i++)
				bricks[i][j].isActive = true;
	}

	if (loseCondition(player))
	{
		actualScreen = LOSE_SCREEN;

		resetGameplay(player, ball, bricks);
	}
}

static void drawGameplay(Player player, Ball ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns], int ballTexture)
{
	std::string timerText = "Tiempo: " + std::to_string(minutes) + ":" + std::to_string(seconds);
	std::string livesText = "Vidas: " + std::to_string(player.lives);
	std::string pointsText = "Points: " + std::to_string(player.points);

	slSetBackColor(0, 0, 0);

	slSetForeColor(1, 1, 1, 100);

	//slRectangleFill(player.x, player.y, player.width, player.height);
	slSprite(player.texture, player.x, player.y, player.width, player.height);

	//slCircleFill(ball.x, ball.y, ball.radius, 100);
	slSprite(ball.texture, ball.x, ball.y, ball.radius * 4, ball.radius * 4);

	for (int j = 0; j < amountOfBricksCollumns; j++)
		for (int i = 0; i < amountOfBricksRow; i++)
			if (bricks[i][j].isActive)
				slSprite(bricks[i][j].texture, bricks[i][j].x, bricks[i][j].y, bricks[i][j].width, bricks[i][j].height);
	
	//slRectangleFill(bricks[i][j].x, bricks[i][j].y, bricks[i][j].width, bricks[i][j].height);

	slSetForeColor(0.5f, 0, 0.5f, 100);

	slRectangleFill(windowWidth / 2.0f, windowHeight - 20, windowWidth, 40);

	slSetForeColor(1, 1, 1, 100);
	
	slText(10, windowHeight - 30, timerText.c_str());
	slText(250, windowHeight - 30, livesText.c_str());
	slText(450, windowHeight - 30, pointsText.c_str());

	slRender();
}

static void ballPlayerCollition(Player player, Ball& ball)
{
	if (ball.y - ball.radius <= (player.y + (player.height / 2.0f)) && ball.y + ball.radius >= (player.y - (player.height / 2.0f)))
	{
		if ((ball.x + (ball.radius / 2.0f)) >= (player.x - (player.width / 2.0f)) && (ball.x - (ball.radius / 2.0f)) <= (player.x + (player.width / 2.0f)))
		{
			ball.speedY *= -1.0f;
			ball.speedX = (ball.x - player.x) / player.width * 10;
			ball.untouchableTimer = 10;
		}
	}
}

static void ballBrickCollition(Brick bricks[amountOfBricksRow][amountOfBricksCollumns], Ball& ball, Player& player)
{
	for (int j = 0; j < amountOfBricksCollumns; j++)
	{
		for (int i = 0; i < amountOfBricksRow; i++)
		{
			if (bricks[i][j].isActive)
			{
				if (ball.y - ball.radius <= (bricks[i][j].y + (bricks[i][j].height / 2.0f)) && ball.y + ball.radius >= (bricks[i][j].y - (bricks[i][j].height / 2.0f)))
				{
					if ((ball.x + (ball.radius / 2.0f)) >= (bricks[i][j].x - (bricks[i][j].width / 2.0f)) && (ball.x - (ball.radius / 2.0f)) <= (bricks[i][j].x + (bricks[i][j].width / 2.0f)))
					{
						ball.speedY *= -1.0f;
						//ball.speedX = ((ball.x - bricks[i][j].x) / bricks[i][j].width * 5) * -1.0f;
						ball.speedX = (ball.x - bricks[i][j].x) / bricks[i][j].width * 10;

						bricks[i][j].isActive = false;

						player.points += 100;
					}
				}
			}
		}
	}
}

static void resetGameplay(Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns])
{
	player.lives = player.startingLives;
	player.points = 0;
	player.x = player.baseX;
	player.y = player.baseY;
	
	ball.isActive = false;
	ball.speedX = ball.startSpeedX;
	ball.speedY = ball.startSpeedY;
	
	for (int j = 0; j < amountOfBricksCollumns; j++)
		for (int i = 0; i < amountOfBricksRow; i++)
			bricks[i][j].isActive = true;
	
	minutes = 0;
	seconds = 0;
	miliseconds = 0.0f;
	
	isPauseOn = false;
}

static bool loseCondition(Player player)
{
	if (player.lives <= 0)
		return true;

	return false;
}

//static bool winCondition()

static bool haveToResetBricks(Brick bricks[amountOfBricksRow][amountOfBricksCollumns])
{
	for (int j = 0; j < amountOfBricksCollumns; j++)
		for (int i = 0; i < amountOfBricksRow; i++)
			if (bricks[i][j].isActive)
				return false;
	
	return true;
}