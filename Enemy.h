#pragma once

#include "MovingObject.h"

class Enemy : public MovingObject
{

public:

	Enemy();

	void Update(sf::Time _frameTime);
	bool isInPlay();


private:

	bool m_isInPlay;


};