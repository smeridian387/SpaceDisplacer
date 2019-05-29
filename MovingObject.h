#pragma once
// Project Includes
#include "Framework/SpriteObject.h"

class MovingObject : public SpriteObject
{

public:

	MovingObject();

	// Overriding Methods
	void Update(sf::Time _frameTime);

protected:

	sf::Vector2f m_velocity; // pixels per second
	sf::Vector2f m_previousPosition;
};