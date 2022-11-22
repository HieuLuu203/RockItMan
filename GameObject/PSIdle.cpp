#include "PSIdle.h"

PSIdle::PSIdle(Player* player)
{
	m_Player = player;
}

void PSIdle::Init()
{
	m_Animation = new Animation("idle", 0.07f, 15);
	//m_Animation->setModeEndFrame(true);
	m_rectSize = sf::Vector2i(m_Animation->getTexture()->getSize().x, m_Animation->getTexture()->getSize().y);
	m_Animation->setOrigin(m_rectSize.x * 0.5f + 25, m_rectSize.y * 0.5f);
}

void PSIdle::Update(float deltaTime)
{
	m_Animation->Update(deltaTime);
	if (m_Player->getHitBox()->getAddMana()) {
		m_Player->addMana();
		m_Player->getHitBox()->setAddMana(false);
	}
	if (m_Player->getHitBox()->getAddScore()) {
		m_Player->addScore();
		m_Player->getHitBox()->setAddScore(false);
	}
	if (m_Player->faceRight) m_Animation->setScale(1.0f, 1.0f);
	else m_Animation->setScale(-1.0f, 1.0f);
	if (m_Player->getHitBox()->isAlive()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			m_Player->changeNextState(RUN);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_Player->getMana() > 0)
		{
			if (m_Player->getCheckFly() == 0)
				m_Player->changeNextState(FLY);
		}
		else m_Player->setCheckFly(0);
	}
	else m_Player->changeNextState(DEATH);
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSIdle::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSIdle::Reset()
{
	//m_currentTime = 0;
	m_Animation->Reset();
}