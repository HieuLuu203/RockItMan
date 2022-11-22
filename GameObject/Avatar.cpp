#include "Avatar.h"

Avatar::Avatar()
{
}

void Avatar::Init()
{
	cloud1.setTexture(*DATA->getTexture("Clouds/Clouds 1/1"));
	cloud1.setPosition(screenWidth/2 + 30, screenHeight / 2 - 180);
	cloud1.setScale(0.35f, 0.35f);
	cloud2.setTexture(*DATA->getTexture("Clouds/Clouds 1/2"));
	cloud2.setPosition(screenWidth/2 + 30, screenHeight / 2 - 180);
	cloud2.setScale(0.35f, 0.35f);
	cloud3.setTexture(*DATA->getTexture("Clouds/Clouds 1/3"));
	cloud3.setPosition(screenWidth/2 + 30, screenHeight / 2 - 180);
	cloud3.setScale(0.35f, 0.35f);
	cloud4.setTexture(*DATA->getTexture("Clouds/Clouds 1/4"));
	cloud4.setPosition(screenWidth/2 + 30, screenHeight / 2 - 180);
	cloud4.setScale(0.35f, 0.35f);

	trap.setTexture(*DATA->getTexture("trap/1/tile0"));
	trap.setPosition(screenWidth/2 + 30, screenHeight / 2 + 30);
}

void Avatar::Update()
{
	std::string path = DATA->getSkinCloud();
	cloud1.setTexture(*DATA->getTexture("Clouds/Clouds " + path + "/1"));
	cloud2.setTexture(*DATA->getTexture("Clouds/Clouds " + path + "/2"));
	cloud3.setTexture(*DATA->getTexture("Clouds/Clouds " + path + "/3"));
	cloud4.setTexture(*DATA->getTexture("Clouds/Clouds " + path + "/4"));

	path = DATA->getSkinTrap();
	trap.setTexture(*DATA->getTexture("trap/" + path + "/tile0"));

}

void Avatar::Render(sf::RenderWindow* window)
{
	window->draw(trap);
	window->draw(cloud1);
	window->draw(cloud2);
	window->draw(cloud3);
	window->draw(cloud4);
}
