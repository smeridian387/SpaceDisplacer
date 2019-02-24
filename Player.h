#pragma once

// Project Includes
#include "MovingObject.h"

class Player : public MovingObject
{

public:

	Player();

	// Overriding Methods
	virtual void Update(sf::Time _frameTime);

private:

	sf::Vector2i m_move;
};