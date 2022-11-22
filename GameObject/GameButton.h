#pragma once
#include <SFML/Graphics.hpp>
#include "../GameManager/ResourceManager.h"
#include "../Application.h"
#include "../GameManager/WindowConnector.h"

class GameButton :public sf::RectangleShape
{
public:
	GameButton();
	~GameButton();

	void Init(std::string name);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);

	void HandleTouchEvent();
	bool isHandle();
	void setOnClick(void (*Func)());
	bool getIsMusic() { return isMusic; }
	void setIsMusic(bool isMusic) { this->isMusic = isMusic; }
private:
	void (*m_btnClickFunc)();
	bool m_isHandling;
protected:
	bool isMusic;
	float currentTime;
};
