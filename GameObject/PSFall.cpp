#include "PSFall.h"

PSFall::PSFall(Player* player)
{
	m_Player = player;
}

void PSFall::Init()
{
	m_Animation = new Animation("fall", 0.1f, 4);
	//m_Animation->setModeEndFrame(true);
	m_rectSize = sf::Vector2i(m_Animation->getTexture()->getSize().x, m_Animation->getTexture()->getSize().y);
	m_Animation->setOrigin((sf::Vector2f)m_rectSize * 0.5f);
}

void PSFall::Update(float deltaTime)
{
	if (m_Animation->getCurrentFrame() < 3)
		m_Animation->Update(deltaTime);
	if (m_Player->getHitBox()->getAddScore()) {
		m_Player->addScore();
		m_Player->getHitBox()->setAddScore(false);
	}
	if (m_Player->getHitBox()->getAddMana()) {
		m_Player->addMana();
		m_Player->getHitBox()->setAddMana(false);
	}
	m_currentTime += deltaTime;
	if (m_Player->faceRight) m_Animation->setScale(1.0f, 1.0f);
	else m_Animation->setScale(-1.0f, 1.0f);
	float v = 10 * m_currentTime;
	m_Player->getHitBox()->move(0, v);
	if (!m_Player->getHitBox()->isAlive()) m_Player->changeNextState(IPState::DEATH);
	if (m_Player->getHitBox()->getPosition().y >= ground) {
		m_Player->changeNextState(RUN);
		m_currentTime = 0.f;
	}

	if (m_Player->getHitBox()->isAlive()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			m_Player->getHitBox()->move(-m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			m_Player->getHitBox()->move(m_Player->getHitBox()->getVelocity().x * deltaTime, 0);
		}
	}
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSFall::Render(sf::RenderWindow* window)
{
	window->draw(*m_Animation);
}

void PSFall::Reset()
{
	m_currentTime = 0;
	m_Animation->Reset();
}