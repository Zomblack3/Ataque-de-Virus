#pragma once

#include "gameManager.h"

#include "player.h"
#include "ball.h"
#include "brick.h"

void gameplay(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns]);

static void updateGameplay(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns]);
static void drawGameplay(Player player, Ball ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns]);

static void ballPlayerCollition(Player player, Ball& ball);
static void ballBrickCollition(Brick bricks[amountOfBricksRow][amountOfBricksCollumns], Ball& ball);

static bool loseCondition(Player player);