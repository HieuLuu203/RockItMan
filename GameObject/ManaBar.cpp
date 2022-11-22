#include "ManaBar.h"

ManaBar::ManaBar()
{
}

ManaBar::~ManaBar()
{
}

void ManaBar::Init()
{
	m_Anim = new Animation("manaBar", 0.07f, 11);
	for (int i = 0; i < 11; i++)
	{
		Texture* texture = m_Anim->getTexture(i);
		sprite[i].setTexture(*texture);
		m_rectSize = sf::Vector2i(texture->getSize());
		sprite[i].setScale(0.4f, 0.4f);
		sprite[i].setOrigin(m_rectSize.x * 0.2f, m_rectSize.y *0.4f);
	}
	sprite[9].setPosition(screenWidth - 60, 60);
	for (int i = 8; i >= 0; i--)
		sprite[i].setPosition(sprite[i + 1].getPosition().x - 49*0.8, 60);
	
}

void ManaBar::Update(float deltaTime)
{

}

void ManaBar::Render(RenderWindow* window)
{
	for (int i = 10 - frameNum; i < 11; i++)
		window->draw(sprite[i]);
}

void ManaBar::setFrameNum(int frameNum)
{
	this->frameNum = frameNum;
}
