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

//void Asteroid::Draw(sf::RenderTarget& _target)
//{
//	/*for (int i = 0; i < m_numberOfAsteroids; ++i)
//	{
//		_target.draw(m_sprite);
//
//
//
//	}*/
//
//
//}

void Asteroid::Update(sf::Time _frameTime)
{
	


}

void Asteroid::NumberOfAsteroids(int)
{


}