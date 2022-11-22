#pragma once
#include "../GameManager/ResourceManager.h"
#include "Trap.h"
#include "Bomb.h"
#include "Mana.h"
#include "Coin.h"
#include "CollisionManager.h"
#include "../GameConfig.h"


class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

private:
	void SpawnCoin();
	void SpawnBomb();
	void SpawnTrap();
	void SpawnMana();
	std::list<Mana*> m_listMana;
	std::list<Trap*> m_listTrap;
	std::list<Bomb*> m_listBomb;
	std::list<Coin*> m_listCoin;
	float m_bombNum;
	float m_TimeSpawnBomb;
	float m_trapNum;
	float m_currentTimeBomb;
	float m_currentTimeTrap;
	float m_TimeSpawnTrap;
	float m_manaNum;
	float m_coinNum;
	float m_TimeSpawnMana;
	float m_TimeSpawnCoin;
	float m_currentTimeMana;
	float m_currentTimeCoin;
};