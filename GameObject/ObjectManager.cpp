#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	m_bombNum = 10;
	m_TimeSpawnBomb = 3.0;
	m_trapNum = 3;
	m_TimeSpawnTrap = 6.0;
	m_currentTimeTrap = 0.f;
	m_currentTimeBomb = 0.f;
	m_manaNum = 4;
	m_TimeSpawnMana = 2.5f;
	m_coinNum = 3;
	m_TimeSpawnCoin = 1.5f;
}

ObjectManager::~ObjectManager()
{
	for (auto it : m_listTrap) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listTrap.clear();

	for (auto it : m_listBomb) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listBomb.clear();

	for (auto it : m_listMana) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listMana.clear();

	for (auto it : m_listCoin) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_listCoin.clear();
}

void ObjectManager::Init(CollisionManager& collisionManager)
{
	for (int i = 0; i < m_trapNum; i++) {
		Trap* trap = new Trap();
		trap->Init();
		trap->getHitBox()->setAlive(false);
		m_listTrap.push_back(trap);
		collisionManager.addObj(trap->getHitBox());
	}

	for (int i = 0; i < m_bombNum; i++) {
		Bomb* bomb = new Bomb();
		bomb->Init();
		bomb->getHitBox()->setAlive(false);
		m_listBomb.push_back(bomb);
		collisionManager.addObj(bomb->getHitBox());
	}

	for (int i = 0; i < m_manaNum; i++) {
		Mana* mana = new Mana();
		mana->Init();
		mana->getHitBox()->setAlive(false);
		m_listMana.push_back(mana);
		collisionManager.addObj(mana->getHitBox());
	}

	for (int i = 0; i < m_coinNum; i++) {
		Coin* coin = new Coin();
		coin->Init();
		coin->getHitBox()->setAlive(false);
		m_listCoin.push_back(coin);
		collisionManager.addObj(coin->getHitBox());
	}
}

void ObjectManager::Update(float deltaTime)
{
	m_currentTimeTrap += deltaTime;
	if (m_currentTimeTrap > m_TimeSpawnTrap) {
		SpawnTrap();
		SpawnTrap();
		m_currentTimeTrap = 0.f;
		if (m_TimeSpawnTrap > 0.5) m_TimeSpawnTrap -= 0.1;
	}

	m_currentTimeBomb += deltaTime;
	if (m_currentTimeBomb > m_TimeSpawnBomb) {
		SpawnBomb();
		m_currentTimeBomb = 0.f;
		if (m_TimeSpawnBomb > 0.5) m_TimeSpawnBomb -= 0.05;
	}

	m_currentTimeMana += deltaTime;
	if (m_currentTimeMana > m_TimeSpawnMana) {
		SpawnMana();
		m_currentTimeMana = 0.f;
	}

	m_currentTimeCoin += deltaTime;
	if (m_currentTimeCoin > m_TimeSpawnCoin) {
		SpawnCoin();
		m_currentTimeCoin = 0.f;
	}
	/*if (m_listTrap.size())
		if (m_listTrap.back()->getHitBox()->getPosition().x > screenWidth + 200 || m_listTrap.back()->getHitBox()->getPosition().x < -200)
			m_listTrap.back()->getHitBox()->setAlive(false);*/
	for (auto trap : m_listTrap) {
		trap->Update(deltaTime);
	}

	for (auto bomb : m_listBomb)
		bomb->Update(deltaTime);

	for (auto mana : m_listMana)
		mana->Update(deltaTime);

	for (auto coin : m_listCoin)
		coin->Update(deltaTime);

}

void ObjectManager::Render(sf::RenderWindow* window)
{
	for (auto trap : m_listTrap) {
		trap->Render(window);
	}

	for (auto bomb : m_listBomb) {
		bomb->Render(window);
	}

	for (auto mana : m_listMana) {
		mana->Render(window);
	}

	for (auto coin : m_listCoin)
		coin->Render(window);
}

void ObjectManager::SpawnTrap()
{
	//std::cout << 1;
	Trap* trap = nullptr;
	for (auto it : m_listTrap) {
		if (it->getHitBox()->isAlive() == false) {
			trap = it;
			break;
		}
	}
	if (trap == nullptr) return;
	trap->getHitBox()->setAlive(true);
	int random = rand() % 2 + 1;
	//std::cout << random;
	if (random & 1)
	{
		trap->setStartPoint(sf::Vector2f(screenWidth + 150, ground - (rand() % (1000 - 50 + 1) + 50)));
		trap->setStartRight(true);
		trap->setStartLeft(false);
	}
	else
	{
		trap->setStartPoint(sf::Vector2f(-150, ground - (rand() % (1000 - 50 + 1) + 50)));
		trap->setStartRight(false);
		trap->setStartLeft(true);
	}
	trap->getHitBox()->setVelocity(sf::Vector2f(200 + rand() % 100, 0));
	trap->Reset();
}

void ObjectManager::SpawnBomb()
{
	//std::cout << 1;
	Bomb* bomb = nullptr;
	for (auto it : m_listBomb) {
		if (it->getHitBox()->isAlive() == false) {
			bomb = it;
			break;
		}
	}
	if (bomb == nullptr) return;
	bomb->getHitBox()->setAlive(true);
	bomb->setStartPoint(sf::Vector2f(0 + rand() % (1600 - 10 + 1) + 10, 0));
	//std::cout << random;
	bomb->getHitBox()->setVelocity(sf::Vector2f(0,50 + rand() % 100));
	bomb->Reset();
}

void ObjectManager::SpawnMana()
{
	Mana* mana = nullptr;
	for (auto it : m_listMana) {
		if (it->getHitBox()->isAlive() == false) {
			mana = it;
			break;
		}
	}
	if (mana == nullptr) return;
	mana->getHitBox()->setAlive(true);
	mana->setStartPoint(sf::Vector2f(0 + rand() % (1600 - 60 + 1) + 60, ground - (rand() % (900 - 50 + 1) + 50)));
	//std::cout << random;
	mana->getHitBox()->setVelocity(sf::Vector2f(0, 30));
	mana->Reset();
}

void ObjectManager::SpawnCoin()
{
	Coin* coin = nullptr;
	for (auto it : m_listCoin) {
		if (it->getHitBox()->isAlive() == false) {
			coin = it;
			break;
		}
	}
	if (coin == nullptr) return;
	coin->getHitBox()->setAlive(true);
	coin->setStartPoint(sf::Vector2f(0 + rand() % (1600 - 60 + 1) + 60, ground - (rand() % (900 - 50 + 1) + 50)));
	//std::cout << random;
	coin->getHitBox()->setVelocity(sf::Vector2f(0, 30));
	coin->Reset();
}