//project includes
#include "Asteroid.h"
#include "Framework/AssetManager.h"

//constants
#define SPEED 500.0f

Asteroid::Asteroid()
	:MovingObject()
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/asteroid.png"));
	m_sprite.setScale(sf::Vector2f(1.0f, 1.0f));

}

void Asteroid::Update(sf::Time _frameTime)
{
	// First, assume no keys are pressed
	m_velocity.x = 0;
	m_velocity.y = SPEED;

}


