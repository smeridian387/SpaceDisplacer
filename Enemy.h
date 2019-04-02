#pragma once

#include "MovingObject.h"

class Enemy : public MovingObject
{

public:

	Enemy();

	void Update(sf::Time _frameTime);
	bool isInPlay();
	//void SetPersuit(Persuit* _persuit);

private:

	bool m_isInPlay;
	//Persuit* m_persuit;

};