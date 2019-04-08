#pragma once

#include "MovingObject.h"
#include "SpaceDisplacer.h"

class Asteroid : public MovingObject
{

public:

	Asteroid();

	//overiding Methods
	void SetSpaceDisplacer(SpaceDisplacer* _SD);
	void Update(sf::Time _frameTime);
	bool isInPlay();
	void Difficulty();
	bool IsActive();
	

private:

	int m_aproachSpeed;
	bool m_isInPlay;
	sf::Vector2f m_velocity;
	SpaceDisplacer* m_SD;

};