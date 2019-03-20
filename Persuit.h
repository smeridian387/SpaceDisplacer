#pragma once

//prject includes
#include "Enemy.h"

class Persuit
{

public:

	Persuit();

	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	void Difficulty();
	bool IsActive();

private:

	int m_numberInPersuit;
	std::vector<Enemy> persuit;
	bool m_isInPlay;
	bool m_active;

};