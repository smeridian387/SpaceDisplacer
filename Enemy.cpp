#include "Enemy.h"
#include "Framework/AssetManager.h"
#include <cmath>
#include <math.h>
#include "Persuit.h"

# define M_PI           3.14159265358979323846  /* pi */

Enemy::Enemy()
	: m_isInPlay(true)
	, m_player(nullptr)
	, m_enemyRotation(0.0f)
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/enemy.png"));
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));

}

int Enemy::GetRotation()
{
	return m_sprite.getRotation();
}

void Enemy::SetPlayer(Player* _player)
{
	m_player = _player;
}

void Enemy::Update(sf::Time _frameTime)
{
	if (m_player != nullptr)
	{
		float playerposx = m_player->GetPlayerPos().x - m_sprite.getPosition().x;
		float playerposy = m_player->GetPlayerPos().y - m_sprite.getPosition().y;
		float m_enemyRotation = ((float)atan2(playerposy, playerposx) + M_PI / 2) * 180.0f / M_PI;
		m_sprite.setRotation(m_enemyRotation);
	}
}

bool Enemy::isInPlay()
{
	return true;
}

