#include "GSPlay.h"

GSPlay::GSPlay()
{
	m_currentScore = 0;
	m_currentTime = 0.f;
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Init()
{
	printf("Play game");
	m_Player.Init();
	m_Background.Init();
	m_CollisionManager.addObj(m_Player.getHitBox());
	m_objectManager.Init(m_CollisionManager);
	//m_CollisionManager.addObj(m_trap.getHitBox());

	Texture* texture = DATA->getTexture("Ground/PNG/game_background_1/game_background_1");
	Ground.setTexture(*texture);
	Ground.setScale(0.25f * 1.5f, 0.3f);
	Ground.setOrigin(sf::Vector2f(texture->getSize().x * 0.5f, texture->getSize().y * 0.15f));
	Ground.setPosition(screenWidth / 2, screenHeight - 129);

	manaBar.Init();
	texture = DATA->getTexture("outsideBar");
	outsideBar.setTexture(*texture);
	m_rectSize = Vector2i(texture->getSize());
	outsideBar.setOrigin(Vector2f(m_rectSize.x*0.8f, m_rectSize.y*0.8f));
	outsideBar.setScale(0.255f*0.8f, 0.24f*0.8f);
	outsideBar.setPosition(screenWidth-108, 81);

	m_Score.setFont(*DATA->getFont("mago1"));
	m_Score.setString("0");
	m_Score.setFillColor(sf::Color::Yellow);
	m_Score.setScale(3.0f, 3.0f);
	m_Score.setPosition(50, 10);

	//DATA->playMusic("Uprising");
	//DATA->getMusic("Uprising")->setLoop(true);;
	//DATA->getMusic("Uprising")->setVolume(30);

}

void GSPlay::Update(float deltaTime)
{
	if (m_Player.getHitBox()->isAlive()) 
	{
		m_Background.Update(deltaTime);
		m_CollisionManager.Update();
	}
	manaBar.setFrameNum(m_Player.getMana());
	m_Player.Update(deltaTime);
	m_objectManager.Update(deltaTime);
	m_currentScore = m_Player.getScore();
	m_Score.setString(std::to_string(m_currentScore));
}

void GSPlay::Render(sf::RenderWindow* window)
{
	m_Background.Render(window);
	window->draw(Ground);
	m_Player.Render(window);
	m_objectManager.Render(window);
	window->draw(outsideBar);
	manaBar.Render(window);
	window->draw(m_Score);
}