//project includes
#include "Asteroid.h"
#include "Framework/AssetManager.h"


Asteroid::Asteroid()
	:MovingObject()
	, m_isInPlay(true)
	, m_timer(true)
	, m_preCurrentTime()
	, m_SD(nullptr)
	, m_player(nullptr)
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

void Asteroid::Update(sf::Time _frameTime)
{
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
		sf::Vector2f move = sf::Vector2f(0, 0.1);
		bool m_SDactive = m_SD->SDActive();
		if (m_SDactive == false)
		{
			SetPosition(GetPosition() + move);
			float rotation = 0.15f;
			m_sprite.setRotation(m_sprite.getRotation() + rotation);
		}
	}

	time_t time1;
	if (m_timer == true)
	{
		m_preCurrentTime = time(&time1);
		if (m_sprite.getGlobalBounds().intersects(m_player->GetBounds()))
		{
			m_player->SetHullIntegrity(-20);
		}
		m_timer = false;
	}
	if (time(&time1) == m_preCurrentTime + 1)
	{
		m_timer = true;
		
	}
}

bool Asteroid::isInPlay()
{
	
	return true;

}

void Asteroid::Difficulty()
{


}


