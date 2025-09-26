#pragma once

struct Brick
{
	float x = 0;
	float y = 0;

	int width = 0;
	int height = 0;

	bool isActive = true;
};

const int amountOfBricksCollumns = 5;
const int amountOfBricksRow = 5;

Brick createBrick(int x, int y, int width, int height);

void setBricks(Brick bricks[amountOfBricksRow][amountOfBricksCollumns], float startingX, float startingY, int width, int height);