#include "Game.h"


//Private functions
void Game::initVariables()
{
	this->window = nullptr;

	this->gameOver = false;

	this->gamePaused = false;
	this->alreadyPaused = 0;

	this->playerSpeed = 3.5f;

	this->boombSpawnTime = 100;
	this->boombSpawnTimeUse = this->boombSpawnTime;
	this->boombSpeed = 2.5f;

	this->health = 5;
	this->points = 0;
}

void Game::initWindow()
{
	this->videoMode.height = 800;
	this->videoMode.width = 600;

	this->window = new sf::RenderWindow(this->videoMode, "The Eaarth Saver", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(144);
}

void Game::initBackground()
{
	if (!this->backGroundTex.loadFromFile("./images/BackGroundImage.png"))
		std::cout << "ERROR: Could not load BackGroundImage.png" << "\n";

	this->backGroundIMG.setTexture(this->backGroundTex);
}

void Game::initPlayer()
{
	if (!this->playerTex.loadFromFile("./images/PlayerImage.png"))
		std::cout << "ERROR: Could not load PlayerImage.png" << "\n";

	this->playerIMG.setTexture(this->playerTex);

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

void Game::initBoombs()
{
	if (!this->boombTex0.loadFromFile("./images/Boomb0.png"))
		std::cout << "ERROR: Could not load Boomb0.png" << "\n";
	this->boombIMG0.setTexture(this->boombTex0);

	if (!this->boombTex1.loadFromFile("./images/Boomb1.png"))
		std::cout << "ERROR: Could not load Boomb1.png" << "\n";
	this->boombIMG1.setTexture(this->boombTex1);

	if (!this->boombTex2.loadFromFile("./images/Boomb2.png"))
		std::cout << "ERROR: Could not load Boomb2.png" << "\n";
	this->boombIMG2.setTexture(this->boombTex2);

	if (!this->boombTex3.loadFromFile("./images/Boomb3.png"))
		std::cout << "ERROR: Could not load Boomb3.png" << "\n";
	this->boombIMG3.setTexture(this->boombTex3);
}

void Game::initFonts()
{
	if (!this->font.loadFromFile("./fonts/Dosis-VariableFont_wght.ttf"))
		std::cout << "ERROR: Could not load Dosis-VariableFont_wght.ttf" << "\n";
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(24);
	this->uiText.setFillColor(sf::Color::Black);
	this->uiText.setString("NONE");
}

void Game::initHearts()
{
	float pos = 600.f;
	if (!this->heartTex.loadFromFile("./images/Heart.png"))
		std::cout << "ERROR: Could not load Heart.png" << "\n";

	this->heartIMG.setTexture(this->heartTex);

	for (int i = 0; i < this->health; i++)
	{
		this->heartIMG.setPosition(pos - this->heartTex.getSize().x, 0.f);

		pos -= this->heartTex.getSize().x;

		this->hearts.push_back(this->heartIMG);
	}

}

void Game::initPause()
{
	if (!this->pauseTex.loadFromFile("./images/Pause.png"))
		std::cout << "ERROR: Could not load Pause.png" << "\n";

	this->pauseIMG.setTexture(this->pauseTex);
}

//Constructors Destructors
Game::Game()
{
	this->initVariables();
	this->initBackground();
	this->initBorder();
	this->initPlayer();
	this->initBoombs();
	this->initFonts();
	this->initText();
	this->initHearts();
	this->initPause();
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

const bool Game::gameEnd() const
{
	return this->gameOver;
}

const bool Game::gamePause() const
{
	return this->gamePaused;
}

//Functions
void Game::spawnBoombs()
{
	int type = rand() % 4;

	switch (type)
	{
	case 0:
		this->boombIMG0.setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->boombTex0.getSize().x)), 0.f);
		this->boombs.push_back(this->boombIMG0);
		break;

	case 1:
		this->boombIMG1.setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->boombTex1.getSize().x)), 0.f);
		this->boombs.push_back(this->boombIMG1);
		break;

	case 2:
		this->boombIMG2.setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->boombTex2.getSize().x)), 0.f);
		this->boombs.push_back(this->boombIMG2);
		break;

	case 3:
		this->boombIMG3.setPosition(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->boombTex3.getSize().x)), 0.f);
		this->boombs.push_back(this->boombIMG3);
		break;
	}
}

void Game::pollEvents()
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

			if (this->ev.key.code == sf::Keyboard::P)
			{
				if (this->alreadyPaused == 0)
				{
					this->gamePaused = true;
					this->alreadyPaused += 1;
				}
				else
				{
					this->gamePaused = false;
					this->alreadyPaused = 0;
				}
			}
			break;
		}
	}
}

//Updates
void Game::updetePlayer()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (!this->playerIMG.getGlobalBounds().intersects(border3.getGlobalBounds()))
		{
			this->playerIMG.move(-this->playerSpeed, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (!this->playerIMG.getGlobalBounds().intersects(border2.getGlobalBounds()))
		{
			this->playerIMG.move(this->playerSpeed, 0);
		}
	}
}

void Game::updateBoombs()
{
	if (this->boombSpawnTimeUse <= 0)
	{
		this->spawnBoombs();
		this->boombSpawnTimeUse = this->boombSpawnTime;
	}
	else
	{
		this->boombSpawnTimeUse -= 1;
	}

	//Check jestli je bomba dopadlá
	for (int i = 0; i < this->boombs.size(); i++)
	{
		this->boombs[i].move(0.f, this->boombSpeed);

		if (this->boombs[i].getPosition().y > this->window->getSize().y)
		{
			this->boombs.erase(this->boombs.begin() + i);
			this->health -= 1;
			std::cout << "Health: " << this->health << "\n";
		}

		if (this->playerIMG.getGlobalBounds().intersects(this->boombs[i].getGlobalBounds()))
		{
			this->boombs.erase(this->boombs.begin() + i);
			this->points += 1;
			std::cout << "Points: " << this->points << "\n";

		}
	}
}

void Game::updateText()
{
	std::stringstream ss;

	ss << "Points: " << this->points << "\n";

	this->uiText.setString(ss.str());
}

void Game::updateHears()
{
	int healthUse = this->health;

	if (this->hearts.size() > healthUse)
	{
		this->hearts.erase(this->hearts.begin() + healthUse);
	}
}

void Game::update()
{
	this->pollEvents();

	if (this->gameOver == false && this->gamePaused == false)
	{
		this->updetePlayer();
		this->updateBoombs();
		this->updateText();
		this->updateHears();
	}	

	if (this->health <= 0)
	{
		this->gameOver = true;
	}
}

//Renders
void Game::renderBorder()
{
	this->window->draw(border);
	this->window->draw(border2);
	this->window->draw(border3);

}

void Game::renderBoombs(sf::RenderTarget& target)
{
	for (auto& e : this->boombs)
	{
		target.draw(e);
	}
}

void Game::renderPlayer()
{
	this->window->draw(playerIMG);
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
}

void Game::renderHearts(sf::RenderTarget& target)
{
	for (auto& e : this->hearts)
	{
		target.draw(e);
	}
}

void Game::renderPause()
{
	this->window->draw(this->pauseIMG);
}

void Game::renderBackground()
{
	this->window->draw(this->backGroundIMG);
}

void Game::render()
{
	this->window->clear();

	//Vykreslení pozadí
	this->renderBackground();

	this->renderBorder();

	//Vykreslení objektů
	this->renderBoombs(*this->window);
	this->renderPlayer();
	this->renderText(*this->window);
	this->renderHearts(*this->window);

	if (this->gamePaused)
		this->renderPause();

	this->window->display();
}
