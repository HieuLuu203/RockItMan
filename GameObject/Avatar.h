#pragma once
#include "../GameManager/ResourceManager.h"

class Avatar
{
public:
	Avatar();
	void Init();
	void Update();
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite cloud1;
	sf::Sprite cloud2;
	sf::Sprite cloud3;
	sf::Sprite cloud4;
	sf::Sprite trap;
};