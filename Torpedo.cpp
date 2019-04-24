#include "Torpedo.h"
#include "Framework/AssetManager.h"

//constants
#define SPEED 10.0f
# define M_PI           3.14159265358979323846  /* pi */

Torpedo::Torpedo()
	:m_isInPlay(false)
	, m_direction()
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
	sf::Vector2f m_enemyPos(640.0f, 700.0f);
	m_direction = m_enemyPos - m_player->GetPosition();

	float playerposx = m_player->GetPlayerPos().x - m_sprite.getPosition().x;
	float playerposy = m_player->GetPlayerPos().y - m_sprite.getPosition().y;
	float m_torpedoRotation = ((float)atan2(playerposy, playerposx) + M_PI / 2) * 180.0f / M_PI;
	m_sprite.setRotation(m_torpedoRotation);
}

void Torpedo::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}

void Torpedo::Update(sf::Time _frameTime)
{
	
	
}

bool Torpedo::GetIsActive()
{
	return m_active;
}
