#pragma once
#include "../GameManager/ResourceManager.h"
enum TAG
{
	PLAYER,
	TRAP,
	BOMB,
	MANA,
	COIN,
};
class HitBoxBase {
public:
	HitBoxBase();
	//HitBoxBase(float size);
	~HitBoxBase();
	void Init(sf::Vector2f velocity);

	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f velocity);
	TAG getTag() { return m_Tag; };
	void SetTag(TAG tag) { m_Tag = tag; }

	bool isAlive() { return m_isAlive; }
	void setAlive(bool alive) { m_isAlive = alive; }
	bool checkCircle();

	void setAddMana(bool addMana) { this->addMana = addMana; }
	bool getAddMana() { return addMana; }
	void setAddScore(bool addScore) { this->addScore = addScore; }
	bool getAddScore() { return addScore; }
protected:
	bool addScore;
	bool addMana;
	bool isCircle;
	sf::Vector2f m_Velocity;
	bool m_isAlive;
	TAG m_Tag;
};