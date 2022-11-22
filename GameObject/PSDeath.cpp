#include "PSDeath.h"

PSDeath::PSDeath(Player* player)
{
	m_Player = player;
	m_timeRemain = 2.f;
	m_pullBackTime = 0.2f;
}

void PSDeath::Init()
{
	m_Animation = new Animation("die", 0.1f, 5);
	//m_Animation->setModeEndFrame(true);
	m_rectSize = sf::Vector2i(m_Animation->getTexture()->getSize().x, m_Animation->getTexture()->getSize().y);
	m_Animation->setOrigin(m_rectSize.x * 0.5f + 25, m_rectSize.y * 0.5f);
}

void PSDeath::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_Player->faceRight) m_Animation->setScale(1.0f, 1.0f);
	else m_Animation->setScale(-1.0f, 1.0f);
	float v = 10 * m_currentTime;
	if (m_Player->getHitBox()->getPosition().y < ground) m_Player->getHitBox()->move(0, v);
	if (m_currentTime >= m_timeRemain) {
		GSM->ChangeState(StateTypes::MENU);
		//DATA->getMusic("Uprising")->stop();
	}
	if (m_currentTime < m_pullBackTime) m_Player->getHitBox()->move(v*5, 0);
	if (m_Animation->getCurrentFrame() < 4) m_Animation->Update(deltaTime);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSDeath::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSDeath::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}