#pragma once

//project includes 
#include "MovingObject.h"
#include "SpaceDisplacer.h"
#include "Asteroid.h"
#include "Torpedo.h"
#include "Player.h"


class AsteroidBelt
{

public:

	AsteroidBelt();

	//Functions
	void SetSpaceDisplacer(SpaceDisplacer* _SD);
	void SetPlayer(Player* _player);
	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	void Difficulty();
	sf::FloatRect WhichAsteroid();
	void SetGameTimer(int _gametime);
	int GetAsteroidBeltSize();
	//std::vector< AsteroidBelt* > GetObjectAt(sf::Vector2i _targetPos); //donno if i need this
	bool IsActive();

private:

	SpaceDisplacer* m_SD;
	Player* m_player;
	int m_NoOfAsteroidsInPlay;
	int m_timeSinceGameStart;
	std::vector< Asteroid > asteroidBelt;
	int m_difficulty;
	bool m_active;
	sf::FloatRect test;

};