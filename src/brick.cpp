#include "brick.h"

Brick createBrick(int x, int y, int width, int height, int texture)
{
    Brick brick = { };

    brick.x = x;
    brick.y = y;
    brick.width = width;
    brick.height = height;

	brick.texture = texture;

    return brick;
}

void setBricks(Brick bricks[amountOfBricksRow][amountOfBricksCollumns], float startingX, float startingY, int width, int height, int texture)
{
    for (int j = 0; j < amountOfBricksCollumns; j++)
        for (int i = 0; i < amountOfBricksRow; i++)
            bricks[i][j] = createBrick(startingX + (100 * i), startingY - (50 * j), width, height, texture);
}
