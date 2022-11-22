#include "PSFly.h"

PSFly::PSFly(Player* player)
{
	m_Player = player;
	m_currentTime = 0.f;
}


void PSFly::Init()
{
	m_Animation = new Animation("fly", 0.07f, 15);
	m_rectSize = sf::Vector2i(m_Animation->getTexture()->getSize().x, m_Animation->getTexture()->getSize().y);
	m_Animation->setOrigin(m_rectSize.x * 0.5f + 25, m_rectSize.y * 0.5f);
	//m_Player->getHitBox()->setPosition()
	//m_Animation->move(0, 20.0f);
}

void PSFly::Update(float deltaTime)
{
	if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(IPState::DEATH);
	if (m_Player->getHitBox()->getAddMana()) {
		m_Player->addMana();
		m_Player->getHitBox()->setAddMana(false);
	}
	if (m_Player->getHitBox()->getAddScore()) {
		m_Player->addScore();
		m_Player->getHitBox()->setAddScore(false);
	}
	if (m_Player->getHitBox()->getPosition().y > 50) m_Player->getHitBox()->move(0, -m_Player->getHitBox()->getVelocity().y * deltaTime / 2);
	m_Animation->Update(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_Player->setCheckFly(1);
		m_Player->manaSubstract(deltaTime);
		if (m_Player->getMana() <= 0) {
			m_Player->changeNextState(FALL);
			m_currentTime = 0.f;
		//if (m_Player->getHitBox()->getPosition().y <= 1)
		}
		//else m_Player->getHitBox()->move(0, -m_Player->getHitBox()->getVelocity().y * deltaTime + v);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_Player->getHitBox()->getPosition().x > 10) {
			m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
			m_Animation->setScale(-1.0f, 1.0f);
			m_Player->faceRight = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_Player->getHitBox()->getPosition().x < screenWidth - 10) {
			m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
			m_Animation->setScale(1.0f, 1.0f);
			m_Player->faceRight = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_Player->getHitBox()->getPosition().y < ground)
		{
			m_Player->getHitBox()->move(0, m_Player->getHitBox()->getVelocity().y * deltaTime);
			if (m_Player->getHitBox()->getPosition().y >= ground) {
				m_Player->setCheckFly(1);
				m_Player->changeNextState(IDLE);
			}
		}
		if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(IPState::FALL);
		m_Animation->setPosition(m_Player->getHitBox()->getPosition());
	}
	else m_Player->changeNextState(FALL);
}

void PSFly::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSFly::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}