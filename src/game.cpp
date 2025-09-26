#include "game.h"

#include "gameManager.h"

#include "gameplay.h"
#include "loseScreen.h"

#include "player.h"
#include "ball.h"
#include "brick.h"

namespace run
{
	void game()
	{
		SCREENS actualScreen = GAMEPLAY;

		Player player = createPlayer(windowWidth / 2, 30, 75, 25);
		Ball ball = { };
		Brick bricks[amountOfBricksRow][amountOfBricksCollumns] = { };

		setBricks(bricks, 175, windowHeight - 100, 50, 25);

		slWindow(windowWidth, windowHeight, "BREAKOUT PROJECT", 0);

		int font = slLoadFont("res/fonts/Bitcount_Single_Ink/BitcountSingleInk-VariableFont_CRSV,ELSH,ELXP,SZP1,SZP2,XPN1,XPN2,YPN1,YPN2,slnt,wght.ttf");

		slSetFont(font, 24);

		while (!slShouldClose())
		{
			switch (actualScreen)
			{
			case MAIN_MENU:



				break;
			case OPTIONS:
				
				
				
				break;
			case GAMEPLAY:
			
				gameplay(actualScreen, player, ball, bricks);
				
				break;
			case LOSE_SCREEN:

				loseScreen(actualScreen, player, ball);

				break;
			case WIN_SCREEN:



				break;
			case EXIT:
				
				
				
				break;
			default:
				break;
			}
		}
	}
}
