#pragma once

// Project Includes
#include"MovingObject.h"

// Library Includes
#include <SFML/Graphics.hpp>

class Level
{
public:

	Level();

	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	void Input(sf::Event _gameEvent);

	bool DeleteObject(MovingObject* _toDelete);




};
