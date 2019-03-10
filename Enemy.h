#pragma once

#include "MovingObject.h"

class Enemy : public MovingObject
{

public:

	void Update(sf::Time _frameTime);




private:

	float m_roatation;


};