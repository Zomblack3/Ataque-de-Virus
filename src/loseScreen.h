#pragma once

#include "gameManager.h"
#include "player.h"
#include "ball.h"

void loseScreen(SCREENS& actualScreen, Player& player, Ball& ball);

void updateLoseScreen(SCREENS& actualScreen, Player& player, Ball& ball);
void drawLoseScreen(Player player);