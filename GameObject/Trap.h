#pragma once
#include "../GameManager/ResourceManager.h"
#include "HitBox2.h"

class Trap {
public:
	Trap();
	~Trap();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render(sf::RenderWindow* window);

	HitBox2* getHitBox() { return m_HitBox; }
	void setStartPoint(sf::Vector2f point) { m_startPoint = point; }
	void setStartRight(bool startRight) { m_startRight = startRight; }
	void setStartLeft(bool startLeft) { m_startLeft = startLeft; }

	void Reset();
	bool isStop() { return m_stop; }
protected:
	sf::Vector2f m_startPoint;
	HitBox2* m_HitBox;
	Animation* m_currentAni;
	Animation* m_deathAni;
	Animation* m_runAni;
	Vector2i m_rectSize;

	bool m_stop;
	bool m_soundDeadisPlay;
	bool m_startRight;
	bool m_startLeft;
};