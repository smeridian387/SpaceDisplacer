#pragma once

// Project Includes
#include "GameObject.h"

// Library Includes
#include <SFML/Graphics.hpp>

class Level
{
public:

	Level();

	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	void Input(sf::Event _gameEvent);

	bool DeleteObject(GameObject* _toDelete);




};
