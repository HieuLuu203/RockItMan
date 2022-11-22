#include "Animation.h"

Animation::Animation()
{
}

Animation::Animation(std::string name, float frameTime, int frameNum)
{
	//m_SizeImage = Vector2i(this->getTexture()->getSize().x, this->getTexture()->getSize().y);
	this->frameNum = frameNum;
	this->frameTime = frameTime;
	currentFrame = 0;
	timer = 0;
	for (int i = 0; i < this->frameNum; i++)
	{
		Texture* texture = new Texture();
		std::string path = "C:/Documents/code/RockItMan.cpp/Sources/Data/Textures/" + name + "/tile" + std::to_string(i) + ".png";
		texture->loadFromFile(path);
		textures.push_back(texture);
	}
}

void Animation::Update(float deltaTime)
{
	timer += deltaTime;
	if (timer >= frameTime)
	{
		timer -= frameTime;
		currentFrame++;
		if (currentFrame == frameNum)
			currentFrame = 0;
	}
	this->setTexture(*textures[currentFrame]);
}

Texture* Animation::getTexture()
{
	//printf("%d", currentFrame);
	return textures[currentFrame];
}

Texture* Animation::getTexture(int frameNum)
{
	return textures[frameNum];
}

void Animation::Reset()
{
	currentFrame = 0;
	timer = 0.f;
}

int Animation::getCurrentFrame()
{
	return currentFrame;
}

int Animation::getFrameNum()
{
	return frameNum;
}
