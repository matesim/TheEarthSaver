#include <iostream>
#include "Game.h"

int main()
{
	Game game;

	while (game.getWindowIsOpen() && !game.gameEnd())
	{
		//Update
		game.update();

		//Render
		game.render();
	}
	//konec-zavření
	return 0;
}