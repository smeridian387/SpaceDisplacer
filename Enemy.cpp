#include "Enemy.h"
#include "Framework/AssetManager.h"

Enemy::Enemy()
	: m_isInPlay(true)
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/enemy.png"));
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_sprite.setPosition(500, 500);
	m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
}

void Enemy::Update(sf::Time _frameTime)
{



}

bool Enemy::isInPlay()
{
	return true;
}