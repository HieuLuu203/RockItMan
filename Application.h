#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Sources/GameManager/ResourceManager.h"
#include "../Sources/GameStateManager/GameStateBase.h"
#include "../Sources/GameObject/Animation.h"

using namespace sf;
class Application
{
public:
	void Run();
	~Application();
	RenderWindow* getWindow();
private:
	void Init();
	void Update(float deltaTime);
	void Render();
	Animation sprite;
	Clock clock;
	RectangleShape shape;
	Vector2i rectSize;
	RenderWindow* m_window;
};

