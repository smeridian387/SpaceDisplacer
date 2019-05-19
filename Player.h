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

	// Overriding Methods
	void Update(sf::Time _frameTime);
	void Draw(sf::RenderTarget& _target);
	void SetHullIntegrity(int _int);
	int GetHullIntergity();
	//virtual void Collide(GameObject& _collider);
	virtual sf::Vector2f GetPlayerPos();

private:

	sf::Vector2i m_move;
	sf::Text m_text;
	int m_hull;
	sf::Sprite m_bankLeft;
	sf::Sprite m_bankRight;
	AnimationSystem m_animation;
	Animation& m_playerBankLeft;
	Animation& m_playerBankRight;
};