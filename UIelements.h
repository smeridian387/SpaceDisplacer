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
	void SetSpaceDisplacer(SpaceDisplacer* _SD);//main passes in a pointer to the space displacer object
	void SetMillisecondsSinceGameStart(float _time);//main passes the time since the game screen started in milliseconds
	void SetGameTimer(int _timeSinceStart);//main passes the time since the game screen started in seconds
	void SetGameOverTime(float _gameovertime);//main passes how long the player survived 
	void Draw(sf::RenderTarget& _target);//main passes in the render target
	void Update(sf::Time _frameTime);//main passes in the frameTime
	void SetPlayer(Player* _player);//main passes in a pointer to the player object
	void IsGameOver(bool _gameover);//main passes wheather or not the game is over
	void IsSplashScreenActive(bool _splash);//main passes wheather or not the splash screen is active
	void IsMainMenuActive(bool _mainmenu);//main passes wheather or not the mainmenu is active

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