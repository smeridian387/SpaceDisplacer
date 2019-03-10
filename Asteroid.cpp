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

void Asteroid::SetPosition(sf::Vector2f _position)
{
	int random = std::rand() % 1260;
	_position.x = random;
	_position.y = 250;


}

void Asteroid::Update(sf::Time _frameTime)
{
	


}

void Asteroid::NumberOfAsteroids(int)
{


}