#pragma once
#include "IPState.h"
#include "Player.h"

class PSFall :public IPState {
public:
	PSFall(Player* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	Player* m_Player;
	Animation* m_Animation;
	Vector2i m_rectSize;
	float m_currentTime;

};