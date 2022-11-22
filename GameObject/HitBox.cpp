#include "HitBox.h"

HitBox::HitBox()
{
}

HitBox::HitBox(Vector2i size) : RectangleShape((sf::Vector2f)size), HitBoxBase()
{
	this->addScore = false;
	this->addMana = false;
	this->isCircle = false;
	this->setOrigin((sf::Vector2f)size * 0.5f);
	this->setFillColor(sf::Color(0, 0, 0, 0));
	this->setOutlineThickness(1.f);
	this->setOutlineColor(sf::Color::Red);
	m_Velocity = sf::Vector2f(0, 0);
	m_isAlive = true;
}

HitBox::~HitBox()
{
}