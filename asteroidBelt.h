#pragma once

//project includes 
#include "Asteroid.h"

class AsteroidBelt
{

public:

	AsteroidBelt();

	//Functions
	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	void Difficulty();
	//std::vector< AsteroidBelt* > GetObjectAt(sf::Vector2i _targetPos); //donno if i need this
	bool IsActive();

private:

	int m_NoOfAsteroidsInPlay;
	std::vector< Asteroid > asteroidBelt;
	int m_difficulty;
	bool m_active;

};