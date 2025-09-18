#pragma once

struct Ball
{
	int x = 0;
	int y = 0;

	int startSpeedX = 5;
	int startSpeedY = 5;

	int speedX = 5;
	int speedY = 5;

	int radius = 10;

	int untouchableTimer = 0;

	bool hasCollide = false;

	bool isActive = false;
};