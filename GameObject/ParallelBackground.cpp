#include "ParallelBackground.h"

void ParallexBackground::Init()
{
	Texture* texture = DATA->getTexture("Clouds/Clouds " + DATA->getSkinCloud() + "/1");
	//texture->setScale(1.5f, 1.0f);
	m_background.setTexture(*texture);
	m_background.setScale(1.5f * 1.5f, 1.5f * 1.5f);
	Layer* layer;
	std::string path = "Clouds/Clouds " + DATA->getSkinCloud() + "/";
	//Layer 1
	layer = new Layer();
	layer->Init(path + "1", 5);
	//m_Background.push_back(layer);
	//Layer 2
	layer = new Layer();
	layer->Init(path + "2", 10);
	m_Background.push_back(layer);
	//Layer 3
	layer = new Layer();
	layer->Init(path + "3", 15);
	m_Background.push_back(layer);
	//Layer 4
	layer = new Layer();
	layer->Init(path + "4", 20);
	m_Background.push_back(layer);
	
}

void ParallexBackground::Update(float deltaTime)
{
	for (auto layer : m_Background) {
		layer->Update(deltaTime);
	}
}

void ParallexBackground::Render(sf::RenderWindow* window)
{
	window->draw(m_background);
	for (auto layer : m_Background) {
		layer->Render(window);
	}
}