#pragma once

#include "gameManager.h"

#include "player.h"
#include "ball.h"
#include "brick.h"

void gameplay(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns], int ballTexture);

static void updateGameplay(SCREENS& actualScreen, Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns]);
static void drawGameplay(Player player, Ball ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns], int ballTexture);

static void ballPlayerCollition(Player player, Ball& ball);
static void ballBrickCollition(Brick bricks[amountOfBricksRow][amountOfBricksCollumns], Ball& ball, Player& player);

static void resetGameplay(Player& player, Ball& ball, Brick bricks[amountOfBricksRow][amountOfBricksCollumns]);

static bool loseCondition(Player player);


static bool haveToResetBricks(Brick bricks[amountOfBricksRow][amountOfBricksCollumns]);