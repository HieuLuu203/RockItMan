#include "Player.h"
#include "PSRun.h"
#include "PSFly.h"
#include "PSFall.h"
#include "PSDeath.h"
#include"PSIdle.h"

Player::Player()
{
	currentScore = 0;
	mana = 10;
	faceRight = true;
	m_nextState = IPState::SNULL;
	m_runState = new PSRun(this);
	m_flyState = new PSFly(this);
	m_fallState = new PSFall(this);
	m_deathState = new PSDeath(this);
	m_idleState = new PSIdle(this);
	m_currentState = m_idleState;
}


Player::~Player()
{
	if (m_runState != nullptr) {
		delete m_runState;
	}
	if (m_flyState != nullptr) {
		delete m_flyState;
	}
	if (m_fallState != nullptr) {
		delete m_fallState;
	}
	if (m_deathState != nullptr) {
		delete m_deathState;
	}
	if (m_idleState != nullptr) {
		delete m_idleState;
	}
	m_currentState = nullptr;

}

void Player::changeNextState(IPState::STATE nextState)
{
	m_nextState = nextState;
}

float Player::getMana()
{
	return mana;
}
void Player::manaSubstract(float deltaTime)
{
	mana -= deltaTime;
}

void Player::Init()
{
	checkFly = 1;
	mana = 10;
	m_runState->Init();
	m_flyState->Init();
	m_fallState->Init();
	m_deathState->Init();
	m_idleState->Init();

	m_HitBox = new HitBox(sf::Vector2i(50, 130));
	m_HitBox->setPosition(400, ground);
	m_HitBox->Init(sf::Vector2f(200, 500));
	m_HitBox->SetTag(PLAYER);
}

void Player::Update(float deltaTime)
{
	performStateChange();
	m_currentState->Update(deltaTime);

}

void Player::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	//window->draw(*m_HitBox);
}

void Player::addMana()
{
	if (mana + 3 > 10) mana = 10;
	else mana += 3;
}

HitBox* Player::getHitBox()
{
	return m_HitBox;
}

void Player::performStateChange()
{
	if (m_nextState != IPState::SNULL) {
		switch (m_nextState)
		{
		case IPState::RUN:
			m_currentState = m_runState;
			break;
		case IPState::FLY:
			m_currentState = m_flyState;
			break;
		case IPState::FALL:
			m_currentState = m_fallState;
			break;
		case IPState::IDLE:
			m_currentState = m_idleState;
			break;
		case IPState::DEATH:
			m_currentState = m_deathState;
			break;
		default:
			break;
		}
		m_nextState = IPState::SNULL;
		m_currentState->Reset();
	}
}