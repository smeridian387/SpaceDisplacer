#pragma once

#include "MovingObject.h"
#include "Persuit.h"

class Torpedo : public MovingObject
{

public:

	Torpedo();

	void SetPersuit(Persuit* _persuit);
	//void initialize();
	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	bool GetIsActive();

private:

	sf::Vector3f velocity;
	bool m_isInPlay;
	Persuit* m_persuit;
};
