#pragma once

#include "MovingObject.h"
#include "Persuit.h"
#include "Torpedo.h"

class EnemyFire
{

public:

	EnemyFire();

	void Update(sf::Time _frameTime);
	void SetPersuit(Persuit* _persuit);
	void SetTorpedo(Torpedo* _torpedo);

private:

	Torpedo* m_torpedo;
	Persuit* m_persuit;

};