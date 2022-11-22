#include "PSRun.h"

PSRun::PSRun(Player* player)
{
	m_Player = player;
}

void PSRun::Init()
{
	m_Animation = new Animation("run", 0.05f, 15);
	m_rectSize = sf::Vector2i(m_Animation->getTexture()->getSize().x, m_Animation->getTexture()->getSize().y);
	m_Animation->setOrigin(m_rectSize.x * 0.5f + 25, m_rectSize.y * 0.5f);
	//m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSRun::Update(float deltaTime)
{
	//m_Animation->setOrigin(m_Player->getHitBox()->getVelocity());
	if (m_Player->getHitBox()->getAddMana()) {
		m_Player->addMana();
		m_Player->getHitBox()->setAddMana(false);
	}
	if (m_Player->getHitBox()->getAddScore()) {
		m_Player->addScore();
		m_Player->getHitBox()->setAddScore(false);
	}
	m_Animation->Update(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_Player->getMana() > 0) {
			if (m_Player->getCheckFly() == 0)
				m_Player->changeNextState(FLY);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_Player->getHitBox()->getPosition().x >= 10) {
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) m_Player->setCheckFly(0);
			m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
			m_Player->faceRight = false;
			m_Animation->setScale(-1.0f, 1.0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_Player->getHitBox()->getPosition().x <= screenWidth - 10) {
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) m_Player->setCheckFly(0);
			m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
			m_Animation->setScale(1.0f, 1.0f);
			m_Player->faceRight = true;
		}

	}
	else m_Player->changeNextState(IDLE);
	
	if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(IPState::DEATH);

	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSRun::Render(sf::RenderWindow* window)
{
	//m_sprite->setTexture(*m_Animation->getTexture());
	window->draw(*m_Animation);
}

void PSRun::Reset()
{
	m_Animation->Reset();
}