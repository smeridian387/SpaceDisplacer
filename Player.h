#pragma once

// Project Includes
#include "MovingObject.h"
#include "Framework/TextObject.h"
#include "Framework/AnimationSystem.h"
#include "Framework/Animation.h"

class Player : public MovingObject
{

public:

	Player();

	void Update(sf::Time _frameTime);//main passes in the frameTime
	void Draw(sf::RenderTarget& _target);//main passes in the render target
	void SetHullIntegrity(int _int);//setter for player health
	int GetHullIntergity();//getter for player health
	virtual sf::Vector2f GetPlayerPos();//getter for player position
	void IsMainMenuActive(bool _mainmenu);//main passes the bool for wheather the mainmenu us active or not

private:

	sf::Vector2i m_move;
	sf::Text m_text;
	int m_hull;
	sf::Sprite m_UIship;
	AnimationSystem m_animationSystem;
	AnimationSystem m_animationSystem2;
	bool m_mainmenuActive;
};