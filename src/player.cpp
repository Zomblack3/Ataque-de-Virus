#include "player.h"

Player createPlayer(int x, int y, int width, int height)
{
    Player player = { };

    player.x = x;
    player.y = y;
    player.baseX = x;
    player.baseY = y;

    player.width = width;
    player.height = height;

    return player;
}

void resetPlayer(Player& player)
{
    player.x = player.baseX;
    player.y = player.baseY;

    player.points = 0;
}
