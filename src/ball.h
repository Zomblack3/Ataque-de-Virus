#pragma once

#include "sl.h"

struct Ball
{
	float x = 0;
	float y = 0;

	float startSpeedX = 5;
	float startSpeedY = 5;

	float speedX = 5;
	float speedY = 5;

	int radius = 20;

	int untouchableTimer = 0;

	bool isActive = false;

	int texture = 0;
};