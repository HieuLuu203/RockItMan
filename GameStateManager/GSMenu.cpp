#include "GSMenu.h"

GSMenu::GSMenu()
{
	m_BackgroundSize.x = screenWidth;
	m_BackgroundSize.y = screenHeight;
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	gameName.setFont(*DATA->getFont("GravityBold"));
	gameName.setString("RockItMan");
	gameName.setCharacterSize(65);
	gameName.setFillColor(sf::Color::White);
	//gameName.setOrigin(100, 0);
	gameName.setPosition(screenWidth / 2 - 260, screenHeight / 2 - 250);

	Texture* texture = DATA->getTexture("logo");
	logo.setTexture(*texture);
	logo.setScale(0.5f, 0.5f);
	logo.setOrigin(texture->getSize().x * 0.5f, texture->getSize().y * 0.25f);
	logo.setPosition(screenWidth / 2 , screenHeight / 2);

	GameButton* button;
	//PlayButton
	button = new GameButton();
	button->Init("Play_BTN");
	button->setOnClick([]() {GSM->ChangeState(StateTypes::PLAY); });
	button->setPosition(screenWidth / 2, 5 * screenHeight / 6 +50);
	button->setSize(sf::Vector2f(150, 150));
	button->setOrigin(button->getSize() / 2.f);
	m_ListBtn.push_back(button);

	//Exit Button
	button = new GameButton();
	button->Init("Close_BTN");
	button->setOrigin(button->getSize() / 2.f );
	button->setPosition(screenWidth / 2 + 230, 5 * screenHeight / 6 + 70);
	button->setOnClick([]() { WConnect->getWindow()->close(); });
	m_ListBtn.push_back(button);

	//Setting Button
	button = new GameButton();
	button->Init("Settings_BTN");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + 130, 5 * screenHeight / 6 + 70);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::SETTING); });
	m_ListBtn.push_back(button);

	//about Button
	button = new GameButton();
	button->Init("Info_BTN");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - 130, 5 * screenHeight / 6 + 70);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::ABOUT); });
	m_ListBtn.push_back(button);

	//HighScore Button
	button = new GameButton();
	button->Init("Rating_BTN");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - 230, 5*screenHeight/6 + 70);
	button->setOnClick([]() {GSM->ChangeState(StateTypes::HIGHSCORE); });
	m_ListBtn.push_back(button);


	//Background
	texture = DATA->getTexture("Background");
	m_Background.setTexture(*texture);
	m_Background.setScale(1.5f, 1.5f);
	m_Background.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
	m_Background.setPosition(screenWidth / 2, screenHeight - texture->getSize().y * 1.5 / 2);

	texture = DATA->getTexture("BG");
	m_Background2.setTexture(texture);
	m_Background2.setSize(sf::Vector2f(576*1.5*1.5, 1536*1.5));
	m_Background2.setOrigin(sf::Vector2f(screenWidth / 2, screenHeight / 2));
	m_Background2.setPosition(screenWidth / 2, screenHeight / 2);
	
	//ScoreManager::GetInstance()->readFile();
}

void GSMenu::Update(float deltaTime)
{
	for (auto btn : m_ListBtn) {
		btn->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->draw(m_Background2);
	window->draw(m_Background);
	window->draw(logo);
	window->draw(gameName);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
}