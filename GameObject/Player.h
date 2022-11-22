#pragma once
#include "IPlayer.h"

class Player : public IPlayer
{
public:
	Player();
	~Player();
	void changeNextState(IPState::STATE nextState);

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	float getMana();
	void manaSubstract(float deltaTime);
	int getCheckFly() { return checkFly; }
	void setCheckFly(int checkFly) { this->checkFly = checkFly; }
	void addMana();
	void addScore() { currentScore++; }
	int getScore() { return currentScore; }

	HitBox* getHitBox();
	bool faceRight;

private:
	void performStateChange();
	float mana;
	int checkFly;
	int currentScore;

	HitBox* m_HitBox;

	IPState::STATE m_nextState;

	IPState* m_currentState;
	IPState* m_runState;
	IPState* m_idleState;
	IPState* m_fallState;
	IPState* m_deathState;
	IPState* m_flyState;
};