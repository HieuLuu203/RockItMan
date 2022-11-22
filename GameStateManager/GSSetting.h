#pragma once
#include "GameStateBase.h"
#include "../GameManager/Singleton.h"
#include "../GameObject/Avatar.h"

class GSSetting : public GameStateBase, public CSingleton<GSSetting> {
public:
	GSSetting();
	virtual ~GSSetting();

	void Exit();
	void Pause();
	void Resume();
	void setMusic();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	bool isMusicOn;
private:
	sf::RectangleShape m_Background2;
	sf::Sprite m_Background;
	sf::Text m_Title;
	std::list<GameButton*> m_ListBtn;
	GameButton* musicButton;
	GameButton* changeSkinTrap;
	GameButton* changeSkinCloud;
	Avatar* ava;
	sf::Text m_Text;
};