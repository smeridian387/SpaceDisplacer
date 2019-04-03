//includes
#include "MovingObject.h"
#include "Enemy.h"
#include "Persuit.h"

Persuit::Persuit()
	: m_numberInPersuit()
	, persuit()
	, m_active(true)
	, m_player(nullptr)
{
	persuit;
	persuit.push_back(Enemy());

}

void Persuit::SetPlayer(Player* _player)
{
	m_player = _player;
}

sf::Vector2f Persuit::Getplayerpos()
{
	sf::Vector2f playerpos = m_player->GetPosition();
		return playerpos;
}

void Persuit::Draw(sf::RenderTarget& _target)
{
	for (int i = 0; i < persuit.size(); i++)
	{
		persuit[i].Draw(_target);

	}
}

void Persuit::Update(sf::Time _frameTime)
{
	for (int i = 0; i < persuit.size(); i++)
	{
		persuit[i].SetPlayer(m_player);
		persuit[i].Update(_frameTime);

	}

}

bool Persuit::IsActive()
{
	return m_active;
}
