#include "GSSetting.h"

GSSetting::GSSetting()
{
}

GSSetting::~GSSetting()
{
}

void GSSetting::Exit()
{
}

void GSSetting::Pause()
{
}

void GSSetting::Resume()
{
}

void musicOn()
{

}

void GSSetting::Init()
{
	isMusicOn = true;
	GameButton* button;
	//close Button
	button = new GameButton();
	button->Init("Close_BTN");
	button->setOrigin(button->getSize() / 2.f);
	button->setSize(sf::Vector2f(50, 50));
	button->setPosition(screenWidth - screenWidth / 20, screenHeight / 8);
	button->setOnClick([]() {GSM->PopState(); });
	m_ListBtn.push_back(button);

	//set music
	musicButton = new GameButton();
	musicButton->Init("Music_BTN");
	musicButton->setIsMusic(true);
	musicButton->setOrigin(musicButton->getSize() / 2.f);
	musicButton->setSize(sf::Vector2f(100, 100));
	musicButton->setPosition(screenWidth / 2, screenHeight - screenHeight / 8);
	musicButton->setOnClick([]() {DATA->setAllowSound(!DATA->getAllowSound()); });
	m_ListBtn.push_back(musicButton);

	//change skin
	changeSkinCloud = new GameButton();
	changeSkinCloud->Init("changeSkin");
	changeSkinCloud->setOrigin(musicButton->getSize() / 2.f);
	changeSkinCloud->setSize(sf::Vector2f(60, 60));
	changeSkinCloud->setPosition(screenWidth / 2 - 20, screenHeight/2 - 100);
	changeSkinCloud->setOnClick([]() {DATA->changeCloud(); });
	m_ListBtn.push_back(changeSkinCloud);

	changeSkinTrap = new GameButton();
	changeSkinTrap->Init("changeSkin");
	changeSkinTrap->setOrigin(musicButton->getSize() / 2.f);
	changeSkinTrap->setSize(sf::Vector2f(60, 60));
	changeSkinTrap->setPosition(screenWidth / 2 - 20, screenHeight/2 + 150);
	changeSkinTrap->setOnClick([]() {DATA->changeTrap(); });
	m_ListBtn.push_back(changeSkinTrap);

	m_Text.setString("CLOUD\n\n\nTRAP");
	m_Text.setFont(*DATA->getFont("mago2"));
	m_Text.setPosition(screenWidth / 2 - 240, screenHeight / 2 - 200);
	m_Text.setCharacterSize(95);

	//avatar
	ava = new Avatar();
	ava->Init();

	/*musicButton = new GameButton();
	musicButton->Init("MusicOff_BTN");
	musicButton->setOrigin(musicButton->getSize() / 2.f);
	musicButton->setSize(sf::Vector2f(100, 100));
	musicButton->setPosition(screenWidth / 2, screenHeight - screenHeight / 8);
	musicButton->setOnClick([]() {DATA->setAllowSound(false); });
	m_ListBtn.push_back(musicButton);*/

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
	m_Title.setString("SETTINGS");
	m_Title.setFont(*DATA->getFont("1.1_Divinity.Regular"));
	m_Title.setPosition(screenWidth / 2 - 220, screenHeight / 8);
	m_Title.setCharacterSize(80);
}

void GSSetting::Update(float deltaTime)
{
	//musicButton = new GameButton();
	//m_ListBtn.push_back(musicButton);
	//musicButton->Update(deltaTime);
	for (auto btn : m_ListBtn) {
		if (btn->getIsMusic())
		{
			if (DATA->getAllowSound())
				btn->Init("Music_BTN");
			else btn->Init("MusicOff_BTN");
			
		}
		btn->Update(deltaTime);
	}
	ava->Update();

}

void GSSetting::Render(sf::RenderWindow* window)
{
	window->draw(m_Background2);
	window->draw(m_Background);
	window->draw(m_Title);
	window->draw(m_Text);
	for (auto btn : m_ListBtn) {
		btn->Render(window);
	}
	ava->Render(window);
}