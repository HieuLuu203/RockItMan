#include "GameButton.h"

GameButton::GameButton()
{
	currentTime = 0.f;
	m_isHandling = false;
	isMusic = false;
}

GameButton::~GameButton()
{
}

void GameButton::Init(std::string name)
{
	this->setTexture(DATA->getTexture(name));
	this->setSize(sf::Vector2f(100, 100));
}

void GameButton::Update(float deltaTime)
{
	currentTime += deltaTime;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && currentTime > 0.f) {
		currentTime = -0.5f;
		HandleTouchEvent();
	}
}

void GameButton::Render(sf::RenderWindow* window)
{
	window->draw(*this);
}

void GameButton::HandleTouchEvent()
{
	m_isHandling = false;
	if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow())))
	{
		m_btnClickFunc();
		m_isHandling = true;
		//std::cout << DATA->getAllowSound();
	}
}

bool GameButton::isHandle()
{
	return m_isHandling;
}

void GameButton::setOnClick(void(*Func)())
{
	m_btnClickFunc = Func;
}


