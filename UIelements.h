#pragma once

#include "Framework/SpriteObject.h"
#include "Framework/AssetManager.h"
#include "Framework/TextObject.h"
#include "Framework/AnimationSystem.h"
#include "Framework/Animation.h"
#include "Player.h"
#include "MovingObject.h"
#include "SpaceDisplacer.h"

class UIelements : MovingObject
{

public:

	UIelements();
	void SetSpaceDisplacer(SpaceDisplacer* _SD);
	void SetMillisecondsSinceGameStart(float _time);
	void SetGameTimer(int _timeSinceStart);
	void SetGameOverTime(float _gameovertime);
	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	void SetPlayer(Player* _player);
	void IsGameOver(bool _gameover);
	void IsSplashScreenActive(bool _splash);
	void IsMainMenuActive(bool _mainmenu);
	//void SetGameTimer(int _gametime);

private:

	sf::Sprite m_LeftPanel;
	sf::Sprite m_RightPanel;
	sf::Sprite m_WarningRect;
	sf::Sprite m_healthBar;
	sf::Sprite m_starsn;
	sf::Sprite m_starsn2;
	sf::Sprite m_starsf;
	sf::Sprite m_starsf2;
	sf::Sprite m_tutorial;
	sf::Sprite m_gameoverScreen;
	sf::Sprite m_mainmenu;
	sf::Sprite m_UIship;
	sf::Sprite m_UIship2;
	sf::Text m_gametime;
	sf::Text m_timeText;
	sf::Text m_enemyShips;
	sf::Text m_noOfShips;
	sf::Text m_gameOverTime;
	Player* m_player;
	SpaceDisplacer* m_SD;
	AnimationSystem m_animationSystem;
	AnimationSystem m_animationSystem2;
	float m_healthBarsize;
	float currentTime;
	float gameovertime;
	int m_secondsSinceGameStart;
	bool m_gameover;
	bool m_splashScreenActive;
	bool m_mainmenuActive;

};