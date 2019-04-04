#pragma once

// Project Includes
#include "MovingObject.h"

class Player : public MovingObject
{

public:

	Player();

	// Overriding Methods
	void Update(sf::Time _frameTime);
	//virtual void Collide(GameObject& _collider);
	virtual sf::Vector2f GetPlayerPos();

private:

	sf::Vector2i m_move;
	int m_hull;
};