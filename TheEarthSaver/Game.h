#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
	Zastřešující classa
*/

class Game
{
private:
	//Variables
		//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	void initVariables();
	void initWindow();

public:
	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;

	//Functions
	void poolEvents();
	void update();
	void render();
};

