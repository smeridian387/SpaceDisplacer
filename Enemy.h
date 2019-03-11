#pragma once

#include "MovingObject.h"

class Enemy : public MovingObject
{

public:

	void Update(sf::Time _frameTime);
	void target(float);
	bool isInPlay();


private:

	float m_rotation;


};