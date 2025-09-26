#include "brick.h"

Brick createBrick(int x, int y, int width, int height)
{
    Brick brick = { };

    brick.x = x;
    brick.y = y;
    brick.width = width;
    brick.height = height;

    return brick;
}

void setBricks(Brick bricks[amountOfBricksRow][amountOfBricksCollumns], float startingX, float startingY, int width, int height)
{
    for (int j = 0; j < amountOfBricksCollumns; j++)
        for (int i = 0; i < amountOfBricksRow; i++)
            bricks[i][j] = createBrick(startingX + (100 * i), startingY - (50 * j), width, height);
}
