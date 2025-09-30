#include "mainMenu.h"

#include "sl.h"

bool areTheControlesShown = false;
bool areTheRulesShown = false;

void mainMenu(SCREENS& actualScreen)
{
	updateMainMenu(actualScreen);

	drawMainMenu();
}

void updateMainMenu(SCREENS& actualScreen)
{
	if (!areTheControlesShown && !areTheRulesShown)
	{
		if (slGetKey('d') || slGetKey('D'))
			actualScreen = GAMEPLAY;

		if (slGetKey('c') || slGetKey('C'))
			areTheControlesShown = true;

		if (slGetKey('r') || slGetKey('R'))
			areTheRulesShown = true;
	}
	else
	{
		if (slGetKey('v') || slGetKey('V'))
		{
			if (areTheControlesShown)
				areTheControlesShown = false;

			if (areTheRulesShown)
				areTheRulesShown = false;
		}
	}
}

void drawMainMenu()
{
	slSetBackColor(0, 0, 0.5f);

	slSetForeColor(1, 1, 1, 100);

	if (!areTheControlesShown && !areTheRulesShown)
	{
		slRectangleFill((windowWidth / 2.0f) + 20, (windowHeight / 2.0f) + 110, (16.0f * 20.0f), 30);

		slSetForeColor(1, 0, 0, 100);

		slText(windowWidth / 2.0f - (12.5f * 20.0f), (windowHeight / 2.0f) + 200, "Se a producido un error en el sistema");
		slText(windowWidth / 2.0f - (9.5f * 20.0f), (windowHeight / 2.0f) + 150, "parece que esta sufriendo un");
		
		slSetForeColor(0, 0, 0.5f, 100);

		slText(windowWidth / 2.0f - (4.0f * 20.0f), (windowHeight / 2.0f) + 100, "ATAQUE DE VIRUS");
		
		slSetForeColor(1, 1, 1, 100);
		
		slText(windowWidth / 2.0f - (10.5f * 20.0f), windowHeight / 2.0f, "Presione la tecla D para defenderse");
		slText(windowWidth / 2.0f - (14.0f * 20.0f), (windowHeight / 2.0f) - 50, "Presione la tecla C para ver los controles");
		slText(windowWidth / 2.0f - (13.0f * 20.0f), (windowHeight / 2.0f) - 100, "Presione la tecla R para ver las reglas");
		slText(windowWidth / 2.0f - (14.5f * 20.0f), (windowHeight / 2.0f) - 150, "Presione la tecla S para cerrar el programa");
		
		slSetForeColor(0.3f, 1, 0, 100);
		
		slSetFontSize(20);

		slText(10, 50, "Hecho por Zomblack3 (Santiago Britos)");
		slText(10, 10, "Fondo personalizado: semen.bababrykin (Wallpapers.com)");

		slSetFontSize(24);
	}
	else if (areTheControlesShown)
	{
		slText(windowWidth / 2.0f - (14.0f * 20.0f), (windowHeight / 2.0f) + 150, "Moverse (izquierda): A / Flecha izquierda");
		slText(windowWidth / 2.0f - (12.0f * 20.0f), (windowHeight / 2.0f) + 100, "Moverse (derecha): D / Flecha derecha");
		slText(windowWidth / 2.0f - (11.0f * 20.0f), (windowHeight / 2.0f) + 50, "Iniciar partida; Barra espaciadora");
		slText(windowWidth / 2.0f - (3.0f * 20.0f), windowHeight / 2.0f, "Pausa: P");
		
		slSetForeColor(0, 1, 0.25f, 100);
		
		slText(windowWidth / 2.0f - (10.0f * 20.0f), (windowHeight / 2.0f) - 100, "Presione V para volver al menu");
	}
	else
	{
		slText(windowWidth / 2.0f - (9.0f * 20.0f), (windowHeight / 2.0f) + 250, "El jugador debera eliminar a");
		slText(windowWidth / 2.0f - (10.0f * 20.0f), (windowHeight / 2.0f) + 200, "todos los virus de la pantalla");
		slText(windowWidth / 2.0f - (11.0f * 20.0f), (windowHeight / 2.0f) + 150, "haciendo rebotar un escudo en el,");
		slText(windowWidth / 2.0f - (12.0f * 20.0f), (windowHeight / 2.0f) + 100, "cada vez que el escudo rebote contra");
		slText(windowWidth / 2.0f - (12.0f * 20.0f), (windowHeight / 2.0f) + 50, "los virus, estos seran eliminados.");
		slText(windowWidth / 2.0f - (11.0f * 20.0f), (windowHeight / 2.0f) - 50, "En caso de que el escudo salga de");
		slText(windowWidth / 2.0f - (11.0f * 20.0f), (windowHeight / 2.0f) - 100, "la pantalla por el lado inferior");
		slText(windowWidth / 2.0f - (9.0f * 20.0f), (windowHeight / 2.0f) - 150, "el jugador perdera una vida,");
		slText(windowWidth / 2.0f - (13.0f * 20.0f), (windowHeight / 2.0f) - 200, "si pierde tres vidas pierde la partida");
		
		slSetForeColor(0, 1, 0.25f, 100);
		
		slText(windowWidth / 2.0f - (10.0f * 20.0f), (windowHeight / 2.0f) - 300, "Presione V para volver al menu");
	}


	slRender();
}
