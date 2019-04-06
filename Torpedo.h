#pragma once

#include "MovingObject.h"

class Torpedo : public MovingObject
{

public:

	Torpedo();

	void SetPosition(sf::Vector2f _spawnpos);
	void SetRotation(float _rotation);
	void Update(sf::Time _frameTime);
	bool GetIsActive();

private:

	bool m_isInPlay;

};
