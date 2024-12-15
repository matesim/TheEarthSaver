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
	float playerSpeed;

		//Game objects
	sf::RectangleShape border;
	sf::RectangleShape border2;
	sf::RectangleShape border3;

	sf::Texture boombTex0;
	sf::Texture boombTex1;
	sf::Texture boombTex2;
	sf::Texture boombTex3;
	sf::Sprite boombIMG0;
	sf::Sprite boombIMG1;
	sf::Sprite boombIMG2;
	sf::Sprite boombIMG3;
	std::vector<sf::Sprite> boombs;
	float boombSpeed;
	int boombSpawnTime;
	int boombSpawnTimeUse;

	//Stats + logic
	int health;
	int points;
	bool gameOver;

	void initVariables();
	void initWindow();
	void initBackground();
	void initPlayer();
	void initBorder();
	void initBoombs();

public:
	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;
	const bool gameEnd() const;

	//Functions
	void spawnBoombs();

	void poolEvents();

	void updetePlayer();
	void updateBoombs();
	void update();
	
	void renderBackground();
	void renderBorder();
	void renderBoombs(sf::RenderTarget& target);
	void renderPlayer();
	void render();
};

