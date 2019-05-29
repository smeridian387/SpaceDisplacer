#include "Torpedo.h"
#include "Framework/AssetManager.h"
#include <cmath>

//constants
#define SPEED 10.0f
# define M_PI           3.14159265358979323846  /* pi */

Torpedo::Torpedo()
	: m_isActive(false)
	, m_player(nullptr)
	, m_direction()
	, m_bulletSpeed()
	, ini(true)
	, m_standardVelocity()
{
	m_hit.setBuffer(AssetManager::GetSoundBuffer("audio/hit.wav"));

	m_sprite.setTexture(AssetManager::GetTexture("graphics/photons.png"));
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
	m_sprite.setPosition(-10.0f, 10.0f);
}

void Torpedo::SetPlayer(Player* _player)
{
	m_player = _player;
}

void Torpedo::ResetVelocity()
{
	m_velocity = m_standardVelocity;
}

void Torpedo::initialize(sf::Vector2f _enemyposition)
{
	m_isActive = true;
	sf::Vector2f enemyPos(_enemyposition);
	sf::Vector2f distance = m_player->GetPosition() - enemyPos;

	float m_torpedoRotation = ((float)atan2(distance.y, distance.x)) * 180.0f / M_PI + 90.0f;
	float magnitude = sqrt(distance.x*distance.x + distance.y*distance.y);

	sf::Vector2f distanceUnitVector = distance / magnitude;
	m_standardVelocity = (distanceUnitVector) * 600.0f;
	m_velocity = (distanceUnitVector) * 600.0f;
	SetPosition(enemyPos);
	m_sprite.setRotation(m_torpedoRotation);
}

void Torpedo::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}

void Torpedo::Update(sf::Time _frameTime)
{
	MovingObject::Update(_frameTime);
	//setting bounds for game screen
	if (GetPosition().x < 200)
	{
		m_isActive = false;
		m_sprite.setPosition(500, -1000);
	}
	if (GetPosition().x > 1080)
	{
		m_isActive = false;
		m_sprite.setPosition(500, -1000);
	}
	if (GetPosition().y < 0)
	{
		m_isActive = false;
		m_sprite.setPosition(500, -1000);
	}
	//if the torpedo collides with the player 
	//torpedo is teleported to the abyss to despawn
	//reducies player health
	//plays sound effect
	if (m_sprite.getGlobalBounds().intersects(m_player->GetBounds()))
	{
		m_sprite.setPosition(500,-1000);
		m_player->SetHullIntegrity(-20);
		m_hit.play();
	}
}

void Torpedo::SetVelocitynull()
{
	m_velocity = sf::Vector2f(0.0f, 0.0f);
}

void Torpedo::SetIsActive(bool _IsActive)
{
	m_isActive = _IsActive;
}

bool Torpedo::GetIsActive()
{
	return m_isActive;
}