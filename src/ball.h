#pragma once

struct Ball
{
	int x = 0;
	int y = 0;

	int speedX = 5;
	int speedY = 5;

	int radius = 10;

	bool hasCollide = false;

	bool isActive = false;
};