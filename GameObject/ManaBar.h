#pragma once
#include "Animation.h"
#include "../GameConfig.h"
#include "../GameManager/ResourceManager.h"

class ManaBar {
public:
	ManaBar();
	~ManaBar();
	void Init();
	void Update(float deltaTime);
	void Render(RenderWindow* window);
	void setFrameNum(int frameNum);

private:
	int frameNum;
	int currentFrame;

	Animation* m_Anim;
	Sprite sprite[11];
	Vector2i m_rectSize;

};