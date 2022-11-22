#include "Trap.h"

Trap::Trap()
{
	m_stop = true;
	m_soundDeadisPlay = false;
}

Trap::~Trap()
{
	m_currentAni = nullptr;
	if (m_deathAni != nullptr) {
		delete m_deathAni;
	}
	if (m_runAni != nullptr) {
		delete m_runAni;
	}
	if (m_HitBox != nullptr) {
		delete m_HitBox;
	}
}

void Trap::Init()
{
	m_currentAni = new Animation("trap/" + DATA->getSkinTrap(), 0.07f, 4);
	m_rectSize = sf::Vector2i(m_currentAni->getTexture()->getSize().x, m_currentAni->getTexture()->getSize().y);
	m_currentAni->setOrigin((sf::Vector2f)m_rectSize * 0.5f);

	m_HitBox = new HitBox2(70.f);
	//m_HitBox->setPosition(200, ground - 100);
	//m_HitBox->Init(sf::Vector2f(150, 500));
	m_HitBox->SetTag(TRAP);
}

void Trap::Update(float deltaTime)
{
	if (m_stop == true) return;
	if (m_HitBox->isAlive()) {
		if (m_startRight) m_HitBox->move(-m_HitBox->getVelocity().x * deltaTime, m_HitBox->getVelocity().y * deltaTime);
		else m_HitBox->move(m_HitBox->getVelocity() * deltaTime);
		if (m_HitBox->getPosition().x <= -200 || m_HitBox->getPosition().x >= screenWidth + 200) {
			m_HitBox->setPosition(m_startPoint);
			m_stop = true;
			m_HitBox->setAlive(false);
		}
		m_currentAni->Update(deltaTime);
		m_currentAni->setPosition(getHitBox()->getPosition());
	}
	else
	{
		/*if (m_soundDeadisPlay == false) {
			DATA->playSound("monster-hurt");
			m_soundDeadisPlay = true;
		}*/
		//m_currentAni = m_deathAni;
		if (m_currentAni->getCurrentFrame()!= m_currentAni->getFrameNum() - 1) {
			m_currentAni->Update(deltaTime);
			m_currentAni->setPosition(getHitBox()->getPosition());
		}
		//else m_stop = true;

	}
}

void Trap::Render(sf::RenderWindow* window)
{
	//if (m_stop) return;
	window->draw(*m_currentAni);
	//window->draw(*m_HitBox);
}

void Trap::Reset()
{
	m_stop = false;
	//m_deathAni->Reset();
	//m_runAni->Reset();
	//m_currentAni = m_runAni;
	m_HitBox->setPosition(m_startPoint);
	m_soundDeadisPlay = false;
}