//includes
#include "MovingObject.h"
#include "Asteroid.h"
#include "asteroidBelt.h"

AsteroidBelt::AsteroidBelt()
	: m_NoOfAsteroidsInPlay()
	, m_difficulty(3)
	, asteroidBelt()
	, m_active(true)
{
	asteroidBelt;
	asteroidBelt.push_back(Asteroid());
	asteroidBelt.push_back(Asteroid());
	asteroidBelt.push_back(Asteroid());
}

void AsteroidBelt::Difficulty()
{
	//this function will determine the difficulty 
	//of the game at any given time 
	//so using the game time i will implement a quadratic 
	//that increases an integer (m_difficulty)
	

}

void AsteroidBelt::Draw(sf::RenderTarget& _target)
{
		for (int i = 0; i < asteroidBelt.size(); i++)
		{
			asteroidBelt[i].Draw(_target);

		}
}

void AsteroidBelt::Update(sf::Time _frameTime) 
{
	for (int i = 0; i < asteroidBelt.size(); i++)
	{
		asteroidBelt[i].Update(_frameTime);

	}

}

bool AsteroidBelt::IsActive()
{
	return m_active;
}
