#include "Bomb.h"

Bomb::Bomb()
{
	m_stop = true;
	m_soundDeadisPlay = false;
	m_exploseTime = 2.0f;
	m_currentTime = 0;
}

Bomb::~Bomb()
{
	m_currentAni = nullptr;
	if (m_exploseAni != nullptr) {
		delete m_exploseAni;
	}
	if (m_HitBox != nullptr) {
		delete m_HitBox;
	}
}

void Bomb::Init()
{
	m_bombAni = new Animation("Bomb", 0.07f, 1);
	m_rectSize = sf::Vector2i(m_bombAni->getTexture()->getSize().x, m_bombAni->getTexture()->getSize().y);
	m_bombAni->setOrigin((sf::Vector2f)m_rectSize * 0.5f);

	m_exploseAni = new Animation("explosion", 0.07f, 8);
	m_rectSize = sf::Vector2i(m_exploseAni->getTexture()->getSize().x, m_exploseAni->getTexture()->getSize().y);
	m_exploseAni->setOrigin(m_rectSize.x * 0.5f, m_rectSize.y * 0.7f);

	m_currentAni = m_bombAni;

	m_HitBox = new HitBox2(40.f);
	//m_HitBox->setPosition(200, ground - 100);
	m_HitBox->Init(sf::Vector2f(0, 50));
	m_HitBox->SetTag(BOMB);
}

void Bomb::Update(float deltaTime)
{
	if (m_stop == true) return;
	if (m_HitBox->isAlive()) {
		if (m_HitBox->getPosition().y < ground) m_HitBox->move(m_HitBox->getVelocity() * deltaTime);
		else
		{
			m_currentTime += deltaTime;
			if (m_currentTime > m_exploseTime)
			{
				m_currentAni = m_exploseAni;
				if (m_currentAni->getCurrentFrame() == m_currentAni->getFrameNum() - 1)
					m_HitBox->setAlive(false);
			}
		}
	}
	if (m_HitBox->isAlive())
	{
		m_currentAni->setPosition(getHitBox()->getPosition());
		m_currentAni->Update(deltaTime);

	}
	else
	{
		m_currentAni = m_exploseAni;
		if (m_currentAni->getCurrentFrame() != m_currentAni->getFrameNum() - 1)
		{
			m_currentAni->setPosition(getHitBox()->getPosition());
			m_currentAni->Update(deltaTime);
		}
		else m_stop = true;
	}


}

void Bomb::Render(sf::RenderWindow* window)
{
	//if (m_stop) return;
	window->draw(*m_currentAni);
	//window->draw(*m_HitBox);
}

void Bomb::Reset()
{
	m_stop = false;
	m_bombAni->Reset();
	m_exploseAni->Reset();
	m_currentAni = m_bombAni;
	m_HitBox->setPosition(m_startPoint);
	m_soundDeadisPlay = false;
	m_currentTime = 0;
}