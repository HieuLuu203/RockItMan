#include "Mana.h"

Mana::Mana()
{
	m_stop = true;
	m_soundDeadisPlay = false;
	currentCheck = 0;
	m_TimeExistMana = 4.0;
	currentTime = 0;
}

Mana::~Mana()
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

void Mana::Init()
{
	m_currentAni = new Animation("Mana", 0.5f, 2);
	m_rectSize = sf::Vector2i(m_currentAni->getTexture()->getSize().x, m_currentAni->getTexture()->getSize().y);
	m_currentAni->setOrigin((sf::Vector2f)m_rectSize * 0.5f);

	m_HitBox = new HitBox2(50.f);
	//m_HitBox->setPosition(200, ground - 100);
	//m_HitBox->Init(sf::Vector2f(150, 500));
	m_HitBox->SetTag(MANA);
}

void Mana::Update(float deltaTime)
{
	currentTime += deltaTime;
	if (currentTime > m_TimeExistMana)
		m_HitBox->setAlive(false);
	if (m_stop == true) return;
	if (m_HitBox->isAlive()) {
		currentCheck += deltaTime;
		if ((int)currentCheck & 1)
			m_HitBox->move(m_HitBox->getVelocity() * deltaTime);
		else m_HitBox->move(-m_HitBox->getVelocity() * deltaTime);
		m_currentAni->Update(deltaTime);
		m_currentAni->setScale(0.5f, 0.5f);
		m_currentAni->setPosition(m_HitBox->getPosition());
	}
	else m_stop = true;
	//else
	//{
	//	/*if (m_soundDeadisPlay == false) {
	//		DATA->playSound("monster-hurt");
	//		m_soundDeadisPlay = true;
	//	}*/
	//	//m_currentAni = m_deathAni;
	//	if (m_currentAni->getCurrentFrame() != m_currentAni->getFrameNum() - 1) {
	//		m_currentAni->Update(deltaTime);
	//		m_currentAni->setPosition(getHitBox()->getPosition());
	//	}
	//	//else m_stop = true;

	//}
}

void Mana::Render(sf::RenderWindow* window)
{
	if (m_stop) return;
	window->draw(*m_currentAni);
	//window->draw(*m_HitBox);
}

void Mana::Reset()
{
	m_stop = false;
	//m_deathAni->Reset();
	//m_runAni->Reset();
	//m_currentAni = m_runAni;
	m_HitBox->setPosition(m_startPoint);
	m_soundDeadisPlay = false;
	currentCheck = 0;
	currentTime = 0;
}