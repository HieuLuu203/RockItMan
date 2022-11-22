#include "HitBoxBase.h"

HitBoxBase::HitBoxBase()
{
}



HitBoxBase::~HitBoxBase()
{
}

void HitBoxBase::Init(sf::Vector2f velocity)
{
	m_Velocity = velocity;
	m_isAlive = true;
}

sf::Vector2f HitBoxBase::getVelocity()
{
	return m_Velocity;
}

void HitBoxBase::setVelocity(sf::Vector2f velocity)
{
	m_Velocity = velocity;
}

bool HitBoxBase::checkCircle()
{
	return isCircle;
}