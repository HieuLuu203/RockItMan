#pragma once
#include <SFML/Graphics.hpp>
#include "../GameConfig.h"
#include <iostream>
#include <vector>
#include <string>
using namespace sf;

class Animation : public Sprite
{
private:
	std::vector<Texture*> textures;
	int currentFrame;
	float frameTime;
	int frameNum;
	float timer;
public:
	Animation();
	Animation(std::string name, float frameTime, int frameNum);
	void Update(float deltaTime);
	Texture* getTexture();
	Texture* getTexture(int frameNum);
	void Reset();
	int getCurrentFrame();
	int getFrameNum();

	sf::Vector2i m_SizeImage;
};

