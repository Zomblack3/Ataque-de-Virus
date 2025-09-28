#pragma once

#include "gameManager.h"
#include "player.h"
#include "ball.h"
#include "brick.h"

void loseScreen(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns]);

void updateLoseScreen(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns]);
void drawLoseScreen(Player player);