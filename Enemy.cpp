#include "Enemy.h"
#include "Framework/AssetManager.h"
#include <cmath>
#include <math.h>
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
	float* playerposx;
	float* playerposy;


	float enemyRotation = (float)atan2(*playerposy, *playerposx) + 3.14159265358979323846f / 2;

	m_sprite.setRotation(m_sprite.getRotation() + enemyRotation);
}

bool Enemy::isInPlay()
{
	return true;
}