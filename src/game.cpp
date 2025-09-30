#include "game.h"

#include "gameManager.h"

#include "mainMenu.h"
#include "gameplay.h"
#include "pause.h"
#include "loseScreen.h"
#include "winScreen.h"

#include "player.h"
#include "ball.h"
#include "brick.h"

namespace run
{
	void game()
	{
		SCREENS actualScreen = MAIN_MENU;

		slWindow(windowWidth, windowHeight, "BREAKOUT PROJECT", 0);
		
		Player player = createPlayer(windowWidth / 2, 30, 75, 25);
		Ball ball = { };
		Brick bricks[amountOfBricksRow][amountOfBricksCollumns] = { };

		int ballTexture = slLoadTexture("res/textures/ball.png");
		int playerTexture = slLoadTexture("res/textures/player.png");
		int brickTexture = slLoadTexture("res/textures/brick.png");
		int backgroundTexture = slLoadTexture("res/textures/background.png");

		player.texture = playerTexture;
		ball.texture = ballTexture;

		setBricks(bricks, 175, windowHeight - 100, 50, 25, brickTexture);

		int font = slLoadFont("res/fonts/Bitcount_Single_Ink/BitcountSingleInk-VariableFont_CRSV,ELSH,ELXP,SZP1,SZP2,XPN1,XPN2,YPN1,YPN2,slnt,wght.ttf");

		slSetFont(font, 24);

		while (!slShouldClose() && !slGetKey('s') && !slGetKey('S'))
		{
			switch (actualScreen)
			{
			case MAIN_MENU:

				mainMenu(actualScreen);

				break;
			case GAMEPLAY:
			
				gameplay(actualScreen, player, ball, bricks, backgroundTexture);
				
				break;
			case PAUSE:

				pause(actualScreen, player, ball, bricks);

				break;
			case LOSE_SCREEN:

				loseScreen(actualScreen, player, ball, bricks);

				break;
			case WIN_SCREEN:

				winScreen(actualScreen, player, ball, bricks);

				break;
			default:
				break;
			}
		}

		slClose();
	}
}
