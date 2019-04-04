#pragma once

#include "Framework/GameObject.h"

class SpaceDisplacer
{

public:

	SpaceDisplacer();

	void Update(sf::Time _frameTime);
	bool SDActive(bool);



private:

	int m_temp;
	int m_SDcasing;
	bool m_SDactive;
	bool m_functional;



};
