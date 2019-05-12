//includes
#include "Asteroid.h"
#include "asteroidBelt.h"

AsteroidBelt::AsteroidBelt()
	: m_NoOfAsteroidsInPlay()
	, m_difficulty(3)
	, asteroidBelt()
	, m_active(true)
	, m_SD(nullptr)
	, test()
{
	asteroidBelt;
	asteroidBelt.push_back(Asteroid());
	asteroidBelt.push_back(Asteroid());
	asteroidBelt.push_back(Asteroid());
	asteroidBelt.push_back(Asteroid());
}

void AsteroidBelt::SetGameTimer(int _gametime)
{
	m_timeSinceGameStart = _gametime;
}

void AsteroidBelt::Difficulty()
{
	//this function will determine the difficulty 
	//of the game at any given time 
	//so using the game time i will implement a quadratic 
	//that increases an integer (m_difficulty)
	

}

void AsteroidBelt::SetSpaceDisplacer(SpaceDisplacer* _SD)
{
	m_SD = _SD;
}

//void AsteroidBelt::SetTorpedo(Torpedo* _torpedo)
//{
//	m_torpedo = _torpedo;
//}
//
//void AsteroidBelt::SetPlayer(Player* _player)
//{
//	m_player = _player;
//}

int AsteroidBelt::GetAsteroidBeltSize()
{
	int i;
	i = asteroidBelt.size();
	return i;
}

sf::FloatRect AsteroidBelt::WhichAsteroid()
{
	return test;
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
		asteroidBelt[i].SetSpaceDisplacer(m_SD);
		asteroidBelt[i].Update(_frameTime);
		/*if (asteroidBelt[i].GetBounds().intersects(m_player->GetBounds()))
		{
			m_player->SetHullIntegrity(-20);
		}*/
	}

}

bool AsteroidBelt::IsActive()
{
	return m_active;
}
