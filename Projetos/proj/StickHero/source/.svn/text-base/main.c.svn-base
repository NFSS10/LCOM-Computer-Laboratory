/**
 * @file main.c
 * @author Jorge Ferreira, Nuno Silva
 * @version 1.0
 *
 * @section DESCRIPTION
 * 		Stick Hero project, version 1
 */
#include "Menu.h"


int main()
{
	/* Initialize service - Don't remove*/
	sef_startup();

	startGame();
	Menu * m = newMenu();
	menuInicial(m);

	deleteMenu(m);
	endGame();

    return 0;
}
