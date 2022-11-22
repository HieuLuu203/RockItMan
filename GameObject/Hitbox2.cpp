#include "HitBox2.h"

HitBox2::HitBox2()
{
}

HitBox2::HitBox2(float size) :CircleShape(size), HitBoxBase()
{
	this->isCircle = true;
	this->setOrigin(size, size);
	this->setFillColor(sf::Color(0, 0, 0, 0));
	this->setOutlineThickness(1.f);
	this->setOutlineColor(sf::Color::Red);
	m_Velocity = sf::Vector2f(0, 0);
	m_isAlive = true;
}

HitBox2::~HitBox2()
{
}
