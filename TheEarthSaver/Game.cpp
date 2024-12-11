#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 800;
	this->videoMode.width = 600;

	this->window = new sf::RenderWindow(this->videoMode, "The Eaarth Saver", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initBackground()
{
	if (!this->backGroundTex.loadFromFile("./images/BackGroundImage.png"))
		std::cout << "ERROR: Could not load BackGroundImage.png" << "\n";

	this->backGroundIMG.setTexture(backGroundTex);
}

void Game::initPlayer()
{
	if (!this->playerTex.loadFromFile("./images/PlayerImage.png"))
		std::cout << "ERROR: Could not load PlayerImage.png" << "\n";

	this->playerIMG.setTexture(playerTex);
}

//Constructors Destructors
Game::Game()
{
	this->initVariables();
	this->initBackground();
	this->initPlayer();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::getWindowIsOpen() const
{
	return this->window->isOpen();
}

//Functions
void Game::poolEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::updetePlayer()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		playerIMG.move(-0.1f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		playerIMG.move(0.1f, 0);
	}
}

void Game::update()
{
	this->poolEvents();

	this->updetePlayer();
}

//Renders
void Game::renderPlayer()
{
	this->window->draw(playerIMG);
}

void Game::renderBackground()
{
	this->window->draw(backGroundIMG);
}

void Game::render()
{
	this->window->clear();

	//Vykreslení pozadí
	this->renderBackground();

	//Vykreslení objektů
	this->renderPlayer();

	this->window->display();
}
