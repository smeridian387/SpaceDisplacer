#pragma once

//project includes 
#include "MovingObject.h"
#include "SpaceDisplacer.h"
#include "Asteroid.h"

class AsteroidBelt
{

public:

	AsteroidBelt();

	//Functions
	void SetSpaceDisplacer(SpaceDisplacer* _SD);
	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	void Difficulty();
	void SetGameTimer(int _gametime);
	//std::vector< AsteroidBelt* > GetObjectAt(sf::Vector2i _targetPos); //donno if i need this
	bool IsActive();

private:

	SpaceDisplacer* m_SD;
	int m_NoOfAsteroidsInPlay;
	int m_timeSinceGameStart;
	std::vector< Asteroid > asteroidBelt;
	int m_difficulty;
	bool m_active;

};