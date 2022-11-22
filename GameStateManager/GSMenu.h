#pragma once
#include "GameStateBase.h"
#include "../GameObject/GameButton.h"
#include "../Application.h"

class GSMenu : public GameStateBase, public Application {
public:
	GSMenu();
	virtual ~GSMenu();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::list<GameButton*> m_ListBtn;
	sf::Sprite m_Background;
	sf::RectangleShape m_Background2;
	Vector2f m_BackgroundSize;
	sf::Sprite logo;
	sf::Text gameName;
};