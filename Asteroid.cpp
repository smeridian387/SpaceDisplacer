//project includes
#include "Asteroid.h"
#include "Framework/AssetManager.h"


Asteroid::Asteroid()
	:MovingObject()
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/asteroid.png"));
	m_sprite.setScale(sf::Vector2f(1.0f, 1.0f));

}

void Asteroid::Update(sf::Time _frameTime)
{
	// First, assume no keys are pressed
	m_aproachSpeed = 10;
	m_velocity.x = 0;
	m_velocity.y = m_aproachSpeed;

}

void Asteroid::NumberOfAsteroids(int)
{


}