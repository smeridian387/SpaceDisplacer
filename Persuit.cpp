//includes
//#include "MovingObject.h"
//#include "Enemy.h"
#include "Persuit.h"
#include <stdlib.h>

Persuit::Persuit()
	: m_timeSinceGameStart()
	, persuit()
	, Torpedos()
	, m_timer(true)
	, m_timer2(true)
	, m_active(true)
	, m_freeze(false)
	, m_player(nullptr)
	, m_torpedo(nullptr)
	, m_asteroid(nullptr)
	, m_SD(nullptr)
	, m_preCurrentTime()
	, m_preCurrentTime1()
{
	m_pew.setBuffer(AssetManager::GetSoundBuffer("audio/pew.wav"));
	persuit;
	persuit.push_back(Enemy());
	persuit.push_back(Enemy());
	persuit.push_back(Enemy());
	Torpedos;
	for (int i = 0; i < 12; ++i)//for loop for increasing torpedo vector
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

sf::Vector2f Persuit::GetEnemyPos(int _whichenemy)
{
	sf::Vector2f m_enemyPos;
	if (_whichenemy == 0)
		m_enemyPos = persuit[0].GetPosition();
	if (_whichenemy == 1)
		m_enemyPos = persuit[1].GetPosition();
	if (_whichenemy == 2)
		m_enemyPos = persuit[2].GetPosition();
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
	return m_enemyRot;
}

void Persuit::Draw(sf::RenderTarget& _target)
{
	//in order from left to right so on screen looks like
	//  0  1  2  //
	persuit[0].SetPosition(240.0f, 760.0f);
	persuit[1].SetPosition(640.0f, 760.0f);
	persuit[2].SetPosition(1040.0f, 760.0f);
	for (int i = 0; i < Torpedos.size(); i++)//logic for increasing the difficulty
	{
		Torpedos[i].Draw(_target);
	}
	if (m_timeSinceGameStart > 5)
	{
		persuit[1].Draw(_target);
	}
	if (m_timeSinceGameStart > 10)
	{
		persuit[2].Draw(_target);
	}
	if (m_timeSinceGameStart > 20)
	{
		persuit[0].Draw(_target);
	}
}

void Persuit::Update(sf::Time _frameTime)
{
	
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
	//logic for enemy firing and bullet freezing
	if (m_SD->SDActive() == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			m_freeze = true;
		}
		else
		{
			m_freeze = false;
		}
			
	}
	else
	{
		m_freeze = false;
	}
	if (m_freeze ==false)
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
			if (m_timeSinceGameStart > 5)//start firing from the first enemy after 5 seconds
			{
				for (int i = 0; i <= 3; ++i)
				{
					if (Torpedos[i].GetIsActive() == false)
					{
						m_pew.play();
						Torpedos[i].initialize(persuit[1].GetPosition());
						break;
					}
				}
			}
			if (m_timeSinceGameStart > 15)//start firing from the second enemy after 15 seconds
			{

				if (Torpedos[4].GetIsActive() == false)
				{
					Torpedos[4].initialize(persuit[2].GetPosition());
				}
				else if (Torpedos[5].GetIsActive() == false)
				{
					Torpedos[5].initialize(persuit[2].GetPosition());
				}
				else if (Torpedos[6].GetIsActive() == false)
				{
					Torpedos[6].initialize(persuit[2].GetPosition());
				}
				else if (Torpedos[7].GetIsActive() == false)
				{
					Torpedos[7].initialize(persuit[2].GetPosition());
				}
			}
			if (m_timeSinceGameStart > 30)//start firing from the third enemy after 30 seconds
			{
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
	
	time_t time1;//seconf clock to fix the first if it breakes
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
