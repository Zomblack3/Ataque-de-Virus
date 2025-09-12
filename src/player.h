#pragma once

#include "sl.h"

struct Player
{
	int x = 0;
	int y = 0;
	int baseX = 0;
	int baseY = 0;

	int width = 0;
	int height = 0;

	int points = 0;
};

Player createPlayer(int x, int y, int width, int height);
void resetPlayer(Player& player);