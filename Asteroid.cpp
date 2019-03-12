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
}

void Asteroid::Update(sf::Time _frameTime)
{
	


}

