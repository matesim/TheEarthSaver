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

	this->window->setFramerateLimit(60);
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

	this->playerIMG.setPosition(270.f, 700.f);
}

//Nastavení borderu
void Game::initBorder()
{
	//Levý border
	this->border3.setSize(sf::Vector2f(10.f, 800.f));
	this->border3.setPosition(0, 0);
	this->border3.setFillColor(sf::Color::Color(0, 0, 0, 0));

	//Pravý border
	this->border2.setSize(sf::Vector2f(10.f, 800.f));
	this->border2.setPosition(590.f, 0);
	this->border2.setFillColor(sf::Color::Color(0, 0, 0, 0));

	//Spodní border
	this->border.setSize(sf::Vector2f(600.f, 40.f));
	this->border.setPosition(0, 760.f);
	this->border.setFillColor(sf::Color::Color(0, 0, 0, 0));

	/*
	Barva pro vizualizaci:
	border.setFillColor(sf::Color::Magenta), border2.setFillColor(sf::Color::Magenta), border3.setFillColor(sf::Color::Magenta);
	*/
}

//Constructors Destructors
Game::Game()
{
	this->initVariables();
	this->initBackground();
	this->initBorder();
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

//Updates
void Game::updetePlayer()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->playerIMG.move(-5.f, 0);

		if (this->playerIMG.getGlobalBounds().intersects(border3.getGlobalBounds()))
		{
			this->playerIMG.move(5.f, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->playerIMG.move(5.f, 0);

		if (this->playerIMG.getGlobalBounds().intersects(border2.getGlobalBounds()))
		{
			this->playerIMG.move(-5.f, 0);
		}
	}
}

void Game::update()
{
	this->poolEvents();

	this->updetePlayer();
}

//Renders
void Game::renderBorder()
{
	this->window->draw(border);
	this->window->draw(border2);
	this->window->draw(border3);

}

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

	this->renderBorder();

	//Vykreslení objektů
	this->renderPlayer();

	this->window->display();
}
