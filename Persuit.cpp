//includes
//#include "MovingObject.h"
#include "Enemy.h"
#include "Persuit.h"

Persuit::Persuit()
	: m_numberInPersuit()
	, persuit()
	, m_timer(true)
	, m_timer2(true)
	, m_active(true)
	, m_player(nullptr)
{
	persuit;
	persuit.push_back(Enemy());
	persuit.push_back(Enemy());
	persuit.push_back(Enemy());
	persuit.push_back(Enemy());
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

sf::Vector2f Persuit::GetEnemyPos(int _whichenemy)
{
	sf::Vector2f m_enemyPos;
	if (_whichenemy == 0)
		m_enemyPos = persuit[0].GetPosition();
	if (_whichenemy == 1)
		m_enemyPos = persuit[1].GetPosition();
	if (_whichenemy == 2)
		m_enemyPos = persuit[2].GetPosition();
	if (_whichenemy == 3)
		m_enemyPos = persuit[3].GetPosition();
	if (_whichenemy == 4)
		m_enemyPos = persuit[4].GetPosition();
	return m_enemyPos;
}

int Persuit::GetEnemyRot(int _whichenemy)
{
	int m_enemyRot =0;
	if (_whichenemy == 0)
		m_enemyRot = persuit[0].GetRotation();
	if (_whichenemy == 1)
		m_enemyRot = persuit[1].GetRotation();
	if (_whichenemy == 2)
		m_enemyRot = persuit[2].GetRotation();
	if (_whichenemy == 3)
		m_enemyRot = persuit[3].GetRotation();
	if (_whichenemy == 4)
		m_enemyRot = persuit[4].GetRotation();
	return m_enemyRot;
}

void Persuit::Draw(sf::RenderTarget& _target)
{
	//in order from left to right so on screen looks like
	//  0  1  2  3  4  //
	persuit[0].SetPosition(240.0f, 700.0f);
	persuit[1].SetPosition(440.0f, 700.0f);
	persuit[2].SetPosition(640.0f, 700.0f);
	persuit[3].SetPosition(840.0f, 700.0f);
	persuit[4].SetPosition(1040.0f, 700.0f);
	for(int i = 0; i < persuit.size(); i++)
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
