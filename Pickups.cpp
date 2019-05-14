#include "Framework/AssetManager.h"
#include "MovingObject.h"
#include "Pickups.h"

PickUp::PickUp()
	: MovingObject()
	, m_player(nullptr)
	, m_spawnLN(false)
	, m_spawnSP(true)
	, m_timer(true)
	, m_spawnSPlock(false)
	, m_preCurrentTime()
	, m_timeSinceGameStart()
{
	m_spareParts.setTexture(AssetManager::GetTexture("graphics/SparePartsCrate.png"));
	m_spareParts.setOrigin(m_spareParts.getTextureRect().width / 2, m_spareParts.getTextureRect().height / 2);
	m_spareParts.setScale(sf::Vector2f(0.5f, 0.5f));
	m_liquidNitrogen.setTexture(AssetManager::GetTexture("graphics/LiquidNitrogenCanaster.png"));
	m_liquidNitrogen.setOrigin(m_liquidNitrogen.getTextureRect().width / 2, m_liquidNitrogen.getTextureRect().height / 2);
	m_liquidNitrogen.setScale(sf::Vector2f(0.5f, 0.5f));
	int random = std::rand() % (1030 - 220) + 220;
	int random2 = std::rand() % 360 + 40;
	m_spareParts.setPosition(sf::Vector2f(random, -random2));
	
}

void PickUp::SetPlayer(Player* _player)
{
	m_player = _player;
}

void PickUp::SetGameTimer(int _gametime)
{
	m_timeSinceGameStart = _gametime;
}

void PickUp::Draw(sf::RenderTarget&_target)
{
	if (m_spawnLN == true)
	{
		_target.draw(m_liquidNitrogen);
	}
	if (m_spawnSP == true)
	{
		_target.draw(m_spareParts);
	}
}

void PickUp::Update(sf::Time _frameTime)
{
	MovingObject::Update(_frameTime);
	m_spareParts.setPosition(400.0f, 400.0f);
	if (m_spawnSP == true)
	{
		if (m_spawnSPlock == false)
		{
			int random = std::rand() % (1030 - 220) + 220;
			int random2 = std::rand() % 360 + 40;
			m_spareParts.setPosition(sf::Vector2f(random, -random2));
			m_spawnSPlock = true;
		}
		if (m_spareParts.getPosition().y > 750)
		{
			int randomx = std::rand() % (1030 - 220) + 220;
			int randomy = std::rand() % 360 + 40;
			int randomsize = std::rand() % 15 + 10;
			m_spareParts.setPosition(randomx, -randomy);
		}
		else
		{
			sf::Vector2f move(0.0f, 0.2);
			m_spareParts.setPosition(m_spareParts.getPosition() + move);
			float rotation = 0.15f;
			m_spareParts.setRotation(m_spareParts.getRotation() + rotation);
		}
	}
	if (m_spawnLN == true)
	{
		if (m_liquidNitrogen.getPosition().y > 750)
		{
			int randomx = std::rand() % (1030 - 220) + 220;
			int randomy = std::rand() % 360 + 40;
			int randomsize = std::rand() % 15 + 10;
			m_liquidNitrogen.setPosition(randomx, -randomy);
		}
		else
		{
			sf::Vector2f move(0.0f, 0.2);
			m_liquidNitrogen.setPosition(m_liquidNitrogen.getPosition() + move);
			float rotation = 0.15f;
			m_liquidNitrogen.setRotation(m_liquidNitrogen.getRotation() + rotation);
			if (m_liquidNitrogen.getGlobalBounds().intersects(m_player->GetBounds()))
			{
				m_spawnSP = false;
			}
		}
	}
	
	if (m_timer == true)
	{
		m_preCurrentTime = m_timeSinceGameStart;
		m_timer = false;
	}
	if (m_timeSinceGameStart == m_preCurrentTime + 5)
	{
		int random = std::rand() % (1030 - 220) + 220;
		if (random < 1000)
		{
			m_spawnSP = true;
			m_spawnSPlock = false;
		}
		m_timer = true;
	}


}

