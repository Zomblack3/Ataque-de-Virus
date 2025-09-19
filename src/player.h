#pragma once

struct Player
{
	float x = 0;
	float y = 0;
	float baseX = 0;
	float baseY = 0;

	int width = 0;
	int height = 0;

	int points = 0;
};

Player createPlayer(int x, int y, int width, int height);
void resetPlayer(Player& player);