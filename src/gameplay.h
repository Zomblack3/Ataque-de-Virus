#pragma once

#include "gameManager.h"

#include "player.h"
#include "ball.h"

void gameplay(SCREENS& actualScreen, Player& player, Ball& ball);

void updateGameplay(SCREENS& actualScreen, Player& player, Ball& ball);
void drawGameplay(Player player, Ball ball);

void ballPlayerCollition(Player player, Ball& ball);