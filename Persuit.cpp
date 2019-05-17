//includes
//#include "MovingObject.h"
//#include "Enemy.h"
#include "Persuit.h"
#include <stdlib.h>
#include <iostream>

Persuit::Persuit()
	: m_numberInPersuit()
	, m_timeSinceGameStart()
	, persuit()
	, Torpedos()
	, m_timer(true)
	, m_timer2(true)
	, m_active(true)
	, m_player(nullptr)
	, m_torpedo(nullptr)
	, m_asteroid(nullptr)
	, m_SD(nullptr)
	, m_preCurrentTime()
	, m_preCurrentTime1()
{
	persuit;
	persuit.push_back(Enemy());
	persuit.push_back(Enemy());
	persuit.push_back(Enemy());
	persuit.push_back(Enemy());
	persuit.push_back(Enemy());
	Torpedos;
	for (int i = 0; i < 12; ++i)
	{
		Torpedos.push_back(Torpedo());
	}
}

void Persuit::SetGameTimer(int _gametime)
{
	m_timeSinceGameStart = _gametime;
}

void Persuit::SetPlayer(Player* _player)
{
	m_player = _player;
}

void Persuit::SetAsteroid(Asteroid* _asteroid)
{
	m_asteroid = _asteroid;
}

void Persuit::SetTorpedo(Torpedo* _Torpedo)
{
	m_torpedo = _Torpedo;
}

void Persuit::SetSpaceDisplacer(SpaceDisplacer* _SD)
{
	m_SD = _SD;
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
	for (int i = 0; i < Torpedos.size(); i++)
	{
		Torpedos[i].Draw(_target);
	}
	if (m_timeSinceGameStart > 5)
	{
		persuit[2].Draw(_target);
	}
	if (m_timeSinceGameStart > 10)
	{
		persuit[4].Draw(_target);
	}
	if (m_timeSinceGameStart > 20)
	{
		persuit[0].Draw(_target);
	}
}

void Persuit::Update(sf::Time _frameTime)
{
	/*for (int i = 0; i < Torpedos.size(); i++)
	{
		if (Torpedos[i].GetBounds().intersects(m_player->GetBounds()))
		{
			Torpedos[i].SetIsActive(false);
		}
	}*/
	//random number generator for iratic firing 
	//float random = std::rand() % 0 + 1;
	
	for (int i = 0; i < persuit.size(); i++)
	{
		persuit[i].Update(_frameTime);
		persuit[i].SetPlayer(m_player);
	}
	for (int i = 0; i < Torpedos.size(); i++)
	{
		Torpedos[i].SetPlayer(m_player);
		Torpedos[i].Update(_frameTime);
		bool m_SDactive = m_SD->SDActive();
		if (m_SDactive == true)
		{
			Torpedos[i].SetVelocitynull();
		}
		else
		{
			Torpedos[i].ResetVelocity();
		}
		
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		time_t time1;
		if (m_timer == true)
		{
			m_preCurrentTime = time(&time1);
			m_preCurrentTime1 = m_preCurrentTime;
			m_timer = false;

		}
		if (time(&time1) == m_preCurrentTime + 1)
		{
			if (m_timeSinceGameStart > 5)
			{
				for (int i = 0; i <= 3; ++i)
				{
					if (Torpedos[i].GetIsActive() == false)
					{
						Torpedos[i].initialize(persuit[2].GetPosition());
						break;
					}
				}

				/*if (Torpedos[0].GetIsActive() == false)
				{
					Torpedos[0].initialize(persuit[2].GetPosition());
				}
				else if (Torpedos[1].GetIsActive() == false)
				{
					Torpedos[1].initialize(persuit[2].GetPosition());
				}
				else if (Torpedos[2].GetIsActive() == false)
				{
					Torpedos[2].initialize(persuit[2].GetPosition());
				}
				else if (Torpedos[3].GetIsActive() == false)
				{
					Torpedos[3].initialize(persuit[2].GetPosition());
				}*/
			}
			if (m_timeSinceGameStart > 10)
			{
				//insert second enemy firing logic
				if (Torpedos[4].GetIsActive() == false)
				{
					Torpedos[4].initialize(persuit[4].GetPosition());
				}
				else if (Torpedos[5].GetIsActive() == false)
				{
					Torpedos[5].initialize(persuit[4].GetPosition());
				}
				else if (Torpedos[6].GetIsActive() == false)
				{
					Torpedos[6].initialize(persuit[4].GetPosition());
				}
				else if (Torpedos[7].GetIsActive() == false)
				{
					Torpedos[7].initialize(persuit[4].GetPosition());
				}
			}
			if (m_timeSinceGameStart > 20)
			{
				//insert second enemy firing logic
				if (Torpedos[8].GetIsActive() == false)
				{
					Torpedos[8].initialize(persuit[0].GetPosition());
				}
				else if (Torpedos[9].GetIsActive() == false)
				{
					Torpedos[9].initialize(persuit[0].GetPosition());
				}
				else if (Torpedos[10].GetIsActive() == false)
				{
					Torpedos[10].initialize(persuit[0].GetPosition());
				}
				else if (Torpedos[11].GetIsActive() == false)
				{
					Torpedos[11].initialize(persuit[0].GetPosition());
				}
			}
			m_timer = true;
		}
		m_preCurrentTime = m_preCurrentTime1;
	}
	
	time_t time1;
	if (m_timer2 == true)
	{
		m_preCurrentTime = time(&time1);
		m_timer2 = false;
	}
	if (time(&time1) == m_preCurrentTime + 1)
	{
		m_timer = true;
		m_timer2 = true;
	}

}

bool Persuit::IsActive()
{
	return m_active;
}
