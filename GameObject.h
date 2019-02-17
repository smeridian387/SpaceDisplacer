#pragma once

// Project Includes
#include "Framework/SpriteObject.h"

class Level;

class GameObject : public SpriteObject
{

public:

	GameObject();

	void SetGridPosition(sf::Vector2i _newPosition);
	void SetGridPosition(int _x, int _y);

	sf::Vector2i GetGridPosition();

protected:

	sf::Vector2i m_gridPosition;
};