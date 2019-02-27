#pragma once

// Project Includes
#include "MovingObject.h"

class Player : public MovingObject
{

public:

	Player();

	// Overriding Methods
	virtual void Update(sf::Time _frameTime);
	//virtual void Collide(GameObject& _collider);

private:

	sf::Vector2i m_move;
};