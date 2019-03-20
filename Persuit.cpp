//includes
#include "Enemy.h"
#include "Persuit.h"

Persuit::Persuit()
	: m_numberInPersuit()
	, persuit()
	, m_active(true)
{
	persuit;
	persuit.push_back(Enemy());

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
		persuit[i].Update(_frameTime);

	}

}

bool Persuit::IsActive()
{
	return m_active;
}
