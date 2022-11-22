#pragma once
#include "IPState.h"
#include "Player.h"
#include "../GameStateManager/GameStateMachine.h"

class PSDeath :public IPState {
public:
	PSDeath(Player* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	Player* m_Player;
	Animation* m_Animation;
	float m_currentTime;
	float m_timeRemain;
	float m_pullBackTime;
	Vector2i m_rectSize;

};