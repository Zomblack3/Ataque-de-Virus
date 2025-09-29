#pragma once

#include "gameManager.h"
#include "player.h"
#include "ball.h"
#include "brick.h"

void pause(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns]);

void updatePause(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns]);
void drawPause();