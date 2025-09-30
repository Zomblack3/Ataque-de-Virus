#pragma once

#include "gameManager.h"
#include "player.h"
#include "ball.h"
#include "brick.h"

void winScreen(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns], int backgroundTexture);

void updateWinScreen(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns]);
void drawWinScreen(Player player, int backgroundTexture);