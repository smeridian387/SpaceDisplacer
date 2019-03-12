#pragma once

#include "MovingObject.h"

class Asteroid : public MovingObject
{

public:

	Asteroid();

	//overiding Methods
	virtual void Update(sf::Time _frameTime);
	bool isInPlay();
	void Difficulty();
	

private:

	int m_aproachSpeed;
	bool m_isInPlay;
	sf::Vector2f m_velocity;
};