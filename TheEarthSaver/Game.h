#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>

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
		
		//Background
	sf::Texture backGroundTex;
	sf::Sprite backGroundIMG;

		//Player
	sf::Texture playerTex;
	sf::Sprite playerIMG;

	void initVariables();
	void initWindow();
	void initBackground();
	void initPlayer();

public:
	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;

	//Functions
	void poolEvents();

	void updetePlayer();
	void update();
	
	void renderPlayer();
	void renderBackground();
	void render();
};

