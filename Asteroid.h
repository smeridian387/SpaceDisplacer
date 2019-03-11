#pragma once

#include "MovingObject.h"

class Asteroid : public MovingObject
{

public:

	Asteroid();

	//overiding Methods
	/*void Draw(sf::RenderTarget& _target);*/
	virtual void Update(sf::Time _frameTime);
	//functions
	bool isInPlay();
	void NumberOfAsteroids(int);
	void Difficulty();
	

private:

	int m_aproachSpeed;
	bool m_isInPlay;
	sf::Vector2f m_velocity;
	int m_numberOfAsteroids;
};