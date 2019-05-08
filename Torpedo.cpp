#include "Torpedo.h"
#include "Framework/AssetManager.h"
#include <iostream>
#include <cmath>

//constants
#define SPEED 10.0f
# define M_PI           3.14159265358979323846  /* pi */

Torpedo::Torpedo()
	:m_isInPlay(false)
	, m_direction()
	, m_bulletSpeed()
	, ini(true)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/photons.png"));
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
}

void Torpedo::SetPlayer(Player* _player)
{
	m_player = _player;
}

void Torpedo::initialize()
{
	//placeholder 
	sf::Vector2f enemyPos(640.0f, 700.0f);
	//----------
	sf::Vector2f distance = m_player->GetPosition() - enemyPos;
	float m_torpedoRotation = ((float)atan2(distance.y, distance.x)) * 180.0f / M_PI + 90.0f;
	float magnitude = sqrt(distance.x*distance.x + distance.y*distance.y);
	sf::Vector2f distanceUnitVector = distance / magnitude;
	m_velocity = (distanceUnitVector) * 20.0f;
	SetPosition(enemyPos);
	
	m_sprite.setRotation(m_torpedoRotation);
}

void Torpedo::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}

void Torpedo::Update(sf::Time _frameTime)
{
	if (GetPosition().x < 220)
	{
		//delete self
	}
	if (GetPosition().x > 1060)
	{
		//delete self
	}
	if (GetPosition().y < 30)
	{
		//delete self
	}
	
	
	//sf::Vector2f m_x = m_player->GetPosition() - m_sprite.getPosition();
	//sf::Vector2f distance = sf::Vector2f(((m_player->GetPosition().x - m_sprite.getPosition().x) * (m_player->GetPosition().x - m_sprite.getPosition().x)),((m_player->GetPosition().y - m_sprite.getPosition().y) * (m_player->GetPosition().y - m_sprite.getPosition().y)));
	//distance = sf::Vector2f(sqrt(distance.x), sqrt(distance.y));
	//m_bulletSpeed = sf::Vector2f(0.0f, -0.10f);
	//sf::Vector2f m_temp = sf::Vector2f( m_bulletSpeed.x * m_direction.x, m_bulletSpeed.y * m_direction.y);
	//float offset = distance * m_bulletSpeed;
	//SetPosition( GetPosition() + (distance * m_bulletSpeed));
	MovingObject::Update(_frameTime);
}

bool Torpedo::GetIsActive()
{
	return m_active;
}
