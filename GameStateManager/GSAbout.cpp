#include "GSAbout.h"

GSAbout::GSAbout()
{
}

GSAbout::~GSAbout()
{
}

void GSAbout::Exit()
{
}

void GSAbout::Pause()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Init()
{
	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("Close_BTN");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->PopState(); });
	m_ListBtn.push_back(button);

	//Background
	Texture* texture;
	texture = DATA->getTexture("Background");
	m_Background.setTexture(*texture);
	m_Background.setScale(1.5f, 1.5f);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y * 1.5 / 2);

	texture = DATA->getTexture("BG");
	m_Background2.setTexture(texture);
	m_Background2.setSize(sf::Vector2f(576 * 1.5 * 1.5, 1536 * 1.5));
	m_Background2.setOrigin(sf::Vector2f(screenWidth / 2, screenHeight / 2));
	m_Background2.setPosition(screenWidth / 2, screenHeight / 2);

	//Tile Game
	m_Title.setString("ABOUT");
	m_Title.setFont(*DATA->getFont("1.1_Divinity.Italic"));
	m_Title.setPosition(screenWidth / 2, screenHeight / 5);
}

void GSAbout::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSAbout::Render(sf::RenderWindow* window)
{
	window->draw(m_Background2);
	window->draw(m_Background);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	window->draw(m_Title);
}