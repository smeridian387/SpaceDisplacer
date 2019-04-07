#include "Torpedo.h"
#include "Framework/AssetManager.h"

//constants
#define SPEED 10.0f

Torpedo::Torpedo()
	:m_isInPlay(false)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/photons.png"));
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
}

void Torpedo::SetPersuit(Persuit* _persuit)
{
	m_persuit = _persuit;
}

void Torpedo::Draw(sf::RenderTarget& _target)
{
	
	_target.draw(m_sprite);
}

void Torpedo::Update(sf::Time _frameTime)
{
	if (m_isInPlay == false)
	{
		SetPosition(m_persuit->GetEnemyPos(2));
	}
	sf::Vector2f move = sf::Vector2f(0, 0.1);
	SetPosition(GetPosition() + move);
	/*if (GetPosition().y < 30)
		m_isInPlay = false;
	if (GetPosition().x < 220)
		m_isInPlay = false;
	if (GetPosition().x > 1060)
		m_isInPlay = false;*/
}

bool Torpedo::GetIsActive()
{
	return m_active;
}
