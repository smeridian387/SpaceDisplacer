#pragma once

// Project Includes
#include "MovingObject.h"
#include "Framework/TextObject.h"

class Player : public MovingObject
{

public:

	Player();

	// Overriding Methods
	void Update(sf::Time _frameTime);
	void Draw(sf::RenderTarget& _target);
	void SetHullIntegrity(int _int);
	//virtual void Collide(GameObject& _collider);
	virtual sf::Vector2f GetPlayerPos();

private:

	sf::Vector2i m_move;
	sf::Text m_text;
	int m_hull;
};