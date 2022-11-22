#pragma once
#include "IPState.h"
#include "Player.h"

class PSIdle :public IPState {
public:
	PSIdle(Player* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	Player* m_Player;
	Animation* m_Animation;
	Sprite* m_sprite;
	Vector2i m_rectSize;
};