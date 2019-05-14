//includes
#include "Asteroid.h"
#include "asteroidBelt.h"
#include "Framework/AssetManager.h"
#include <iostream>

AsteroidBelt::AsteroidBelt()
	: m_NoOfAsteroidsInPlay()
	, m_difficulty(3)
	, asteroidBelt()
	, m_preCurrentTime()
	, m_active(true)
	, m_timer(true)
	, m_timer2(true)
	, m_SD(nullptr)
	, m_player(nullptr)
	, test()
{
	asteroidBelt;
	for (int i = 0; i < 9; ++i)
	{
		asteroidBelt.push_back(Asteroid());
	}
	m_hit.setBuffer(AssetManager::GetSoundBuffer("audio/roblox_oof.wav"));
}

void AsteroidBelt::SetGameTimer(int _gametime)
{
	m_timeSinceGameStart = _gametime;
}

void AsteroidBelt::SetSpaceDisplacer(SpaceDisplacer* _SD)
{
	m_SD = _SD;
}

void AsteroidBelt::SetPlayer(Player* _player)
{
	m_player = _player;
}

int AsteroidBelt::GetAsteroidBeltSize()
{
	int i;
	i = asteroidBelt.size();
	return i;
}

sf::FloatRect AsteroidBelt::WhichAsteroid()
{
	return test;
}

void AsteroidBelt::Draw(sf::RenderTarget& _target)
{
	for (int i = 0; i < asteroidBelt.size(); i++)
	{
		asteroidBelt[i].Draw(_target);
	}
}

void AsteroidBelt::Update(sf::Time _frameTime) 
{
		asteroidBelt[0].SetSpaceDisplacer(m_SD);
		asteroidBelt[0].SetPlayer(m_player);
		asteroidBelt[0].SetGameTimer(m_timeSinceGameStart);
		asteroidBelt[0].Update(_frameTime);
		asteroidBelt[1].SetSpaceDisplacer(m_SD);
		asteroidBelt[1].SetPlayer(m_player);
		asteroidBelt[1].SetGameTimer(m_timeSinceGameStart);
		asteroidBelt[1].Update(_frameTime);
		asteroidBelt[2].SetSpaceDisplacer(m_SD);
		asteroidBelt[2].SetPlayer(m_player);
		asteroidBelt[2].SetGameTimer(m_timeSinceGameStart);
		asteroidBelt[2].Update(_frameTime);
		asteroidBelt[3].SetSpaceDisplacer(m_SD);
		asteroidBelt[3].SetPlayer(m_player);
		asteroidBelt[3].SetGameTimer(m_timeSinceGameStart);
		asteroidBelt[3].Update(_frameTime);
		if (m_timeSinceGameStart > 10)
		{
			asteroidBelt[4].SetSpaceDisplacer(m_SD);
			asteroidBelt[4].SetPlayer(m_player);
			asteroidBelt[4].SetGameTimer(m_timeSinceGameStart);
			asteroidBelt[4].Update(_frameTime);
		}
		if (m_timeSinceGameStart > 15)
		{
			asteroidBelt[5].SetSpaceDisplacer(m_SD);
			asteroidBelt[5].SetPlayer(m_player);
			asteroidBelt[5].SetGameTimer(m_timeSinceGameStart);
			asteroidBelt[5].Update(_frameTime);
		}
		if (m_timeSinceGameStart > 20)
		{
			asteroidBelt[6].SetSpaceDisplacer(m_SD);
			asteroidBelt[6].SetPlayer(m_player);
			asteroidBelt[6].SetGameTimer(m_timeSinceGameStart);
			asteroidBelt[6].Update(_frameTime);
		}	
		if (m_timeSinceGameStart > 25)
		{
			asteroidBelt[7].SetSpaceDisplacer(m_SD);
			asteroidBelt[7].SetPlayer(m_player);
			asteroidBelt[7].SetGameTimer(m_timeSinceGameStart);
			asteroidBelt[7].Update(_frameTime);
		}
		if (m_timeSinceGameStart > 30)
		{
			asteroidBelt[8].SetSpaceDisplacer(m_SD);
			asteroidBelt[8].SetPlayer(m_player);
			asteroidBelt[8].SetGameTimer(m_timeSinceGameStart);
			asteroidBelt[8].Update(_frameTime);
		}
		for (int i = 0; i < asteroidBelt.size(); i++)
		{
			if (asteroidBelt[i].GetBounds().intersects(m_player->GetBounds()))
			{
				if (m_timer == true)
				{
					m_player->SetHullIntegrity(-20);
					//m_hit.play();
					m_preCurrentTime = m_timeSinceGameStart;
					m_timer = false;
				}
				if (m_timeSinceGameStart == m_preCurrentTime + 1)
				{
					m_timer = true;
				}
			}
			if (m_timer2 == true)
			{
				m_preCurrentTime = m_timeSinceGameStart;
				m_timer2 = false;
			}
			if (m_timeSinceGameStart == m_preCurrentTime + 1)
			{
				m_timer2 = true;
				m_timer = true;
			}
		}
	std::cout << m_timer << std::endl;
}

bool AsteroidBelt::IsActive()
{
	return m_active;
}
