#pragma once

#include "AsteroidBelt.h"

class Asteroid : public AsteroidBelt
{

public:

	Asteroid();

	//overiding Methods
	bool isInPlay();
	void Difficulty();
	

private:

	int m_aproachSpeed;
	bool m_isInPlay;
	sf::Vector2f m_velocity;
};