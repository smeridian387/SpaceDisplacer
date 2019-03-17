#include <iostream>

//project includes
#include "Asteroid.h"
#include "Framework/AssetManager.h"


Asteroid::Asteroid()
	:MovingObject()
	, m_isInPlay(true)
	, m_velocity(0.0f,0.0f)
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/asteroid.png"));
	m_sprite.setScale(sf::Vector2f(1.0f, 1.0f));

	int random = std::rand() % (1080-200) + 200;
	int random2 = std::rand() % -20 + -60;
	m_sprite.setPosition(sf::Vector2f(random, random2));
}

void Asteroid::Update(sf::Time _frameTime)
{
	if (GetPosition().y > 750)
	{
		float random = std::rand() % (1080 - 200) + 200;
		int random2 = std::rand() % -20 + -60;
		SetPosition(random, random2);

	}
	else
	{
		sf::Vector2f move = sf::Vector2f(0, 0.1);
		SetPosition(GetPosition() + move);
	}
}

bool Asteroid::isInPlay()
{
	
	return true;

}

void Asteroid::Difficulty()
{


}


