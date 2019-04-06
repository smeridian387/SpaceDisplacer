#include "Torpedo.h"
#include "Framework/AssetManager.h"

//constants
#define SPEED 500.0f

Torpedo::Torpedo()
	:m_isInPlay(true)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/photons.png"));
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
}

void Torpedo::SetPosition(sf::Vector2f _spawnpos)
{
	m_sprite.setPosition(_spawnpos);
}

void Torpedo::SetRotation(float _rotation)
{
	m_sprite.setRotation(_rotation);
}

void Torpedo::Update(sf::Time _frameTime)
{
	m_velocity.x = m_velocity.x + 0.5f;
	m_velocity.y = m_velocity.y - 0.5f;
	/*if (GetPosition().y > 30)
		m_active = false;
	if (GetPosition().x > 220)
		m_active = false;*/
	/*if (GetPosition().x < 1060)
		m_active = false;*/
}

bool Torpedo::GetIsActive()
{
	return m_active;
}
