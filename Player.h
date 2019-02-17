#pragma once

// Project Includes
#include "GameObject.h"

class Player : public GameObject
{

public:

	Player();

	// Overriding Methods
	virtual void Input(sf::Event _gameEvent);
	virtual void Update(sf::Time _frameTime);

private:

	sf::Vector2i m_move;
};