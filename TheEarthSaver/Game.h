#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <sstream>
#include <vector>

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

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
		
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

	sf::Texture heartTex;
	sf::Sprite heartIMG;
	std::vector<sf::Sprite> hearts;

	sf::Texture pauseTex;
	sf::Sprite pauseIMG;

	sf::Texture endTex;
	sf::Sprite endIMG;

	sf::Texture endButtonTex;
	sf::Sprite endButtonIMG;

		//Fonts
	sf::Font font;
	sf::Text uiText;
	sf::Text maxScore;

	//Stats + logic
	int health;
	int points;
	int alreadyPaused;
	bool gamePaused;
	bool gameOver;
	bool gameToEnd;

	void initVariables();
	void initWindow();
	void initBackground();
	void initPlayer();
	void initBorder();
	void initBoombs();
	void initFonts();
	void initText();
	void initHearts();
	void initPause();
	void initEndScreen();
	void initMaxScore();
	void initEndButton();

public:
	Game();
	virtual ~Game();

	//Accessors
	const bool getWindowIsOpen() const;
	const bool gamePause() const;
	const bool gameEnd() const;

	//Functions
	void spawnBoombs();

	void pollEvents();

	void checkIfButtonPressed();

	void updetePlayer();
	void updateBoombs();
	void updateText();
	void updateHears();
	void update();

	
	void renderBackground();
	void renderBorder();
	void renderBoombs(sf::RenderTarget& target);
	void renderPlayer();
	void renderText(sf::RenderTarget& target);
	void renderHearts(sf::RenderTarget& target);
	void renderPause();

	void renderEnd(sf::RenderTarget& target);

	void render();
};

