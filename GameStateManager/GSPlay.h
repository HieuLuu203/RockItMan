#pragma once
#include "GameStateBase.h"
#include "../GameObject/ParallelBackground.h"
#include "../GameObject/CollisionManager.h"
#include "../GameObject/Player.h"
#include "../GameObject/ObjectManager.h"
#include "../GameObject/ManaBar.h"

class GSPlay : public GameStateBase {
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	ObjectManager m_objectManager;
	Player m_Player;
	int m_currentScore;
	float m_currentTime;
	sf::Text m_Score;
	ParallexBackground m_Background;
	sf::Sprite Ground;
	CollisionManager m_CollisionManager;
	ManaBar manaBar;
	Sprite outsideBar;
	Vector2i m_rectSize;

};