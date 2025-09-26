#include "game.h"

#include "gameManager.h"

#include "gameplay.h"

#include "player.h"
#include "ball.h"

namespace run
{
	void game()
	{
		SCREENS actualScreen = GAMEPLAY;

		Player player = createPlayer(windowWidth / 2, 30, 75, 25);
		Ball ball = { };

		slWindow(windowWidth, windowHeight, "BREAKOUT", 0);

		//slSetFontSize(24);
		int font = slLoadFont("res/fonts/Bitcount_Single_Ink/BitcountSingleInk-VariableFont_CRSV,ELSH,ELXP,SZP1,SZP2,XPN1,XPN2,YPN1,YPN2,slnt,wght.ttf");

		slSetFont(font, 24);

		while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
		{
			switch (actualScreen)
			{
			case MAIN_MENU:



				break;
			case OPTIONS:
				
				
				
				break;
			case GAMEPLAY:
			
				gameplay(actualScreen, player, ball, font);
				
				break;
			case EXIT:
				
				
				
				break;
			default:
				break;
			}
		}
	}
}
