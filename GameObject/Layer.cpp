#include "Layer.h"

void Layer::Init(std::string name, float speed)
{
	sf::Texture* texture = DATA->getTexture(name);
	m_Image1.setTexture(*texture);
	m_Image1.setScale(1.5f, 1.5f);
	m_Image2.setTexture(*texture);
	m_Image2.setScale(1.5f, 1.5f);
	m_Image3.setTexture(*texture);
	m_Image3.setScale(1.5f, 1.5f);

	m_Speed = speed;

	m_SizeImage = sf::Vector2i (texture->getSize().x * 1.5f, texture->getSize().y * 1.5f);
	m_Image1.setPosition(sf::Vector2f(screenWidth / 3, m_SizeImage.y + 100));
	m_Image2.setPosition(sf::Vector2f(screenWidth, m_Image1.getPosition().y));
	m_Image3.setPosition(m_SizeImage.x * 2.5f, m_Image1.getPosition().y);

	m_Image1.setOrigin((sf::Vector2f)m_SizeImage * 0.5f );
	m_Image2.setOrigin((sf::Vector2f)m_SizeImage * 0.5f);
	m_Image3.setOrigin((sf::Vector2f)m_SizeImage * 0.5f );
}

void Layer::Update(float deltaTime)
{
	m_Image1.move(-m_Speed * deltaTime, 0);
	m_Image2.move(-m_Speed * deltaTime, 0);
	m_Image3.move(-m_Speed * deltaTime, 0);

	if (m_Image2.getPosition().x <= (float)screenWidth / 3 && m_Image1.getPosition().x <= (float)screenWidth / 3) {
		m_Image1.setPosition(m_SizeImage.x * 2.5f, m_Image1.getPosition().y);
		m_Image3.setPosition(sf::Vector2f(screenWidth, m_Image1.getPosition().y));
		//m_Image2.setPosition(sf::Vector2f(screenWidth / 3, 2 * m_SizeImage.y / 3));
	}

	if (m_Image3.getPosition().x <= (float)screenWidth / 3 && m_Image2.getPosition().x <= (float)screenWidth / 3) {
		m_Image2.setPosition(m_SizeImage.x * 2.5f, m_Image1.getPosition().y);
		m_Image1.setPosition(sf::Vector2f(screenWidth, m_Image1.getPosition().y));
		//m_Image3.setPosition(sf::Vector2f(screenWidth / 3, 2 * m_SizeImage.y / 3));
	}

	if (m_Image1.getPosition().x <= (float)screenWidth / 3 && m_Image3.getPosition().x <= (float)screenWidth / 3) {
		m_Image3.setPosition(m_SizeImage.x * 2.5f, m_Image1.getPosition().y);
		m_Image2.setPosition(sf::Vector2f(screenWidth, m_Image1.getPosition().y));
		//m_Image1.setPosition(sf::Vector2f(screenWidth / 3, m_SizeImage.y));
	}
	
}

void Layer::Render(sf::RenderWindow* window)
{
	window->draw(m_Image1);
	window->draw(m_Image2);
	window->draw(m_Image3);
}

void Layer::setPosition(sf::Vector2i pos)
{
	m_Image1.setPosition((sf::Vector2f)pos);
	m_Image2.setPosition(pos.x + m_SizeImage.x, pos.y);
}