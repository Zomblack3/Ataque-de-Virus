#include "game.h"

#include "gameManager.h"

namespace run
{
	void game()
	{
		SCREENS actualScreen = MAIN_MENU;

		slWindow(windowWidth, windowHeight, "BREAKOUT", 0);

		while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
		{
			switch (actualScreen)
			{
			case MAIN_MENU:



				break;
			case OPTIONS:
				
				
				
				break;
			case GAMEPLAY:
				
				
				
				break;
			case EXIT:
				
				
				
				break;
			default:
				break;
			}
		}
	}
}
