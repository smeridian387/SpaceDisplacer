#include "Enemy.h"
#include "Framework/AssetManager.h"
#include <cmath>
#include <math.h>
#include <iostream>
#include "Persuit.h"
Enemy::Enemy()
	: m_isInPlay(true)
	//, m_persuit (nullptr)
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/enemy.png"));
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_sprite.setPosition(500, 500);
	m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
	//m_sprite.setRotation(180);
}

//void Enemy::SetPlayer(Player* _player)
//{
//	m_player = _player;
//}

//void Enemy::SetPersuit(Persuit* _persuit)
//{
//	m_persuit = _persuit;
//}

void Enemy::Update(sf::Time _frameTime)
{
	//float playerposx = Persuit::Getplayerpos;
	//float playerposy = Getplayerpos().y;

	//float enemyRotation = ((float)atan2(playerposy, playerposx) + 3.14159265358979323846f / 2);
		

	m_sprite.setRotation(m_sprite.getRotation() + 1);
	std::cout << m_sprite.getRotation() << std::endl;


}

bool Enemy::isInPlay()
{
	return true;
}

