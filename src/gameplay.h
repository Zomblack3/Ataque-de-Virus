#pragma once

#include "gameManager.h"

#include "player.h"
#include "ball.h"

void gameplay(SCREENS& actualScreen, Player& player, Ball& ball, int font);

static void updateGameplay(SCREENS& actualScreen, Player& player, Ball& ball);
static void drawGameplay(Player player, Ball ball, int font);

static void ballRecCollition(Player player, Ball& ball);

static bool loseCondition(Player player);