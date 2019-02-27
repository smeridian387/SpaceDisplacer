#pragma once

#include "MovingObject.h"

class Asteroid : public MovingObject
{

public:

	Asteroid();

	//overiding Methods
	virtual void Update(sf::Time _frameTime);
	// other fuctions i need
	//function to determine asteroid sawn. would this be tetermined in update?
	void NumberOfAsteroids();
	

private:

	sf::Vector2i m_aproachSpeed;

};