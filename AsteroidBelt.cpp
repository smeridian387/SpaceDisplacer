//includes
#include "MovingObject.h"
#include "Asteroid.h"

AsteroidBelt::AsteroidBelt()
	:MovingObject()
	, m_NoOfAsteroidsInPlay()
	, m_difficulty()
	, m_isInPlay(true)
	, asteroidBelt()
{
	asteroidBelt.push_back({ 1,2 });
}

void AsteroidBelt::Difficulty()
{
	//this function will determine the difficulty 
	//of the game at any given time 
	//so using the game time i will implement a quadratic 
	//that increases an integer (m_difficulty)
	/*m_difficulty = 2;
	int* m_diff = m_difficulty;*/
	

}

void AsteroidBelt::Draw(sf::RenderTarget& _target)
{

	asteroidBelt[0].size() * m_difficulty;

	for (int i = 0; i < asteroidBelt.size();)
	{


	}


}
