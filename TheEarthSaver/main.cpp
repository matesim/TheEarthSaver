#include <iostream>
#include "Game.h"

int main()
{
	Game game;

	while (game.getWindowIsOpen())
	{
		//Update
		game.update();

		//Render
		game.render();
	}
}