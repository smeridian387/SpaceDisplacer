//project includes
#include "Asteroid.h"
#include "Framework/AssetManager.h"


Asteroid::Asteroid()
	:MovingObject()
	, m_isInPlay(true)
	, m_timer(true)
	, m_timer2(true)
	, m_preCurrentTime()
	, m_approachSpeed(0.0f,0.0f)
	, m_approachSpeedY(0.1f)
	, m_SD(nullptr)
	, m_player(nullptr)
	, m_timeSinceGameStart()
	, m_velocity(0.0f,0.0f)
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/asteroid.png"));
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	int randomsize = std::rand() % 20 + 5;
	m_sprite.setScale(sf::Vector2f(randomsize/10, randomsize/10));
	int random = std::rand() % (1030-220) + 220;
	int random2 = std::rand() % 360 + 40;
	m_sprite.setPosition(sf::Vector2f(random, -random2));
}

void Asteroid::SetSpaceDisplacer(SpaceDisplacer* _SD)
{
	m_SD = _SD;
}

void Asteroid::SetPlayer(Player* _player)
{
	m_player = _player;
}

void Asteroid::SetGameTimer(int _timeSinceStart)
{
	m_timeSinceGameStart = _timeSinceStart;
}

void Asteroid::Update(sf::Time _frameTime)
{
	//std::cout << m_timeSinceGameStart << std::endl;
	if (GetPosition().y > 750)
	{
		int randomx = std::rand() % (1030 - 220) + 220;
		int randomy = std::rand() % 360 + 40;
		int randomsize = std::rand() % 15 + 10;
		m_sprite.setScale(sf::Vector2f(randomsize / 10, randomsize / 10));
		SetPosition(randomx, -randomy);
	}
	else
	{
		time_t time1;
		if (m_timer == true)
		{
			m_preCurrentTime = m_timeSinceGameStart;
			m_timer = false;
		}
		if (m_timeSinceGameStart == m_preCurrentTime + 10)
		{
			m_approachSpeedY = m_approachSpeedY + 0.05f;
			m_timer = true;
		}
		bool m_SDactive = m_SD->SDActive();
		if (m_SDactive == false)
		{
			m_approachSpeed = sf::Vector2f(0.0f, m_approachSpeedY);
			SetPosition(GetPosition() + m_approachSpeed);
			float rotation = 0.15f;
			m_sprite.setRotation(m_sprite.getRotation() + rotation);
		}
		if (m_timer2 == true)
		{
			m_preCurrentTime = m_timeSinceGameStart;
			if (m_sprite.getGlobalBounds().intersects(m_player->GetBounds()))
			{
				m_player->SetHullIntegrity(-20);
			}
			m_timer2 = false;
		}
		if (m_timeSinceGameStart == m_preCurrentTime + 1)
		{
			m_timer2 = true;

		}
	}
}

bool Asteroid::isInPlay()
{
	
	return true;

}

void Asteroid::Difficulty()
{


}


