#pragma once
#include <map>
#include <list>
#include <string>
#include "../GameObject/GameButton.h"
//#include "../GameObjects/Animation2.h"
#include "../GameManager/Singleton.h"
#include "../GameConfig.h"
#include "SFML/Audio.hpp"
#include <cstdlib>
#include <ctime>

#define DATA ResourceManager::GetInstance()

class ResourceManager :public CSingleton<ResourceManager> {
public:
	ResourceManager();
	~ResourceManager();

	void addTexture(std::string name);
	void removeTexture(std::string name);
	sf::Texture* getTexture(std::string name);

	void addFont(std::string name);
	void removeFont(std::string name);
	sf::Font* getFont(std::string name);

	void addSound(std::string name);
	void removeSound(std::string name);
	sf::Sound* getSound(std::string name);

	void addMusic(std::string name);
	void removeMusic(std::string name);
	sf::Music* getMusic(std::string name);

	void playMusic(std::string name);
	void playSound(std::string name);
	void setAllowSound(bool allow);
	bool getAllowSound();
	void changeTrap();
	void changeCloud();
	std::string getSkinCloud() { return std::to_string(skinCloud); }
	std::string getSkinTrap() { return std::to_string(skinTrap); }



private:
	std::map<std::string, sf::Texture*> m_MapTexture;
	std::map<std::string, sf::Font*> m_MapFont;
	std::map<std::string, sf::Sound*> m_MapSound;
	std::map<std::string, sf::Music*> m_MapMusic;

	std::string m_Path;
	std::string m_TexturePath;
	std::string m_FontPath;
	std::string m_SoundPath;

	bool m_allowSound;
	
	int skinTrap;
	int skinCloud;
};