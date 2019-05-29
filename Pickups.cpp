#include "Framework/AssetManager.h"
#include "MovingObject.h"
#include "Pickups.h"

PickUp::PickUp()
	: MovingObject()
	, m_player(nullptr)
	, m_SD(nullptr)
	, m_spawnLN(false)
	, m_spawnSP(false)
	, m_timer(true)
	, m_preCurrentTime()
	, m_timeSinceGameStart()
	, random()
{
	m_pickupsound.setBuffer(AssetManager::GetSoundBuffer("audio/pickup.wav"));
	m_spareParts.setTexture(AssetManager::GetTexture("graphics/SparePartsCrate.png"));
	m_spareParts.setOrigin(m_spareParts.getTextureRect().width / 2, m_spareParts.getTextureRect().height / 2);
	m_spareParts.setScale(sf::Vector2f(0.5f, 0.5f));
	m_liquidNitrogen.setTexture(AssetManager::GetTexture("graphics/LiquidNitrogenCanaster.png"));
	m_liquidNitrogen.setOrigin(m_liquidNitrogen.getTextureRect().width / 2, m_liquidNitrogen.getTextureRect().height / 2);
	m_liquidNitrogen.setScale(sf::Vector2f(0.5f, 0.5f));
	int random = std::rand() % (1030 - 220) + 220;
	int random2 = std::rand() % 360 + 40;
	m_spareParts.setPosition(sf::Vector2f(random, -random2));
	int random3 = std::rand() % (1030 - 220) + 220;
	int random4 = std::rand() % 360 + 40;
	m_liquidNitrogen.setPosition(sf::Vector2f(random3, -random4));
	
}

void PickUp::SetPlayer(Player* _player)
{
	m_player = _player;
}

void PickUp::SetSpaceDisplacer(SpaceDisplacer* _SD)
{
	m_SD = _SD;
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
	if (m_spawnSP == true)
	{
		if (m_spareParts.getPosition().y > 760)//if the pickup leaves the bottom of the screen wrap to the top and set self to false
		{
			int randomx = std::rand() % (1030 - 220) + 220;
			int randomy = std::rand() % 360 + 40;
			m_spareParts.setPosition(randomx, -randomy);
			m_spawnSP = false;
		}
		else
		{
			bool m_SDactive = m_SD->SDActive();
			if (m_SDactive == false)//if the space displacer is activated set velocity and rotation to zero
			{
				sf::Vector2f move(0.0f, 250.0f);//set SP velocity
				m_spareParts.setPosition(m_spareParts.getPosition() + move * _frameTime.asSeconds());
				float rotation = 120.0f;
				m_spareParts.setRotation(m_spareParts.getRotation() + rotation * _frameTime.asSeconds());
			}
			if (m_spareParts.getGlobalBounds().intersects(m_player->GetBounds()))//if the SP collides with the player increase players health and remove itself
			{
				m_player->SetHullIntegrity(50);
				int randomx = std::rand() % (1030 - 220) + 220;
				int randomy = std::rand() % 360 + 40;
				m_spareParts.setPosition(randomx, -randomy);
				m_spawnSP = false;
				m_timer = false;
				m_pickupsound.play();
			}
		}
	}
	if (m_spawnLN == true)
	{
		if (m_liquidNitrogen.getPosition().y > 750)//if the pickup leaves the bottom of the screen wrap to the top and set self to false
		{
			int randomx = std::rand() % (1030 - 220) + 220;
			int randomy = std::rand() % 360 + 40;
			m_liquidNitrogen.setPosition(randomx, -randomy);
			m_spawnLN = false;
		}
		else
		{
			bool m_SDactive = m_SD->SDActive();
			if (m_SDactive == false)//if the space displacer is activated set velocity and rotation to zero
			{
				sf::Vector2f move(0.0f, 250.0f);
				m_liquidNitrogen.setPosition(m_liquidNitrogen.getPosition() + move * _frameTime.asSeconds());
				float rotation = 120.0f;
				m_liquidNitrogen.setRotation(m_liquidNitrogen.getRotation() + rotation * _frameTime.asSeconds());
			}
			if (m_liquidNitrogen.getGlobalBounds().intersects(m_player->GetBounds()))
			{
				m_SD->SetSDTemp(-80);
				m_SD->LNWarningMove();
				int randomx = std::rand() % (1030 - 220) + 220;
				int randomy = std::rand() % 360 + 40;
				m_liquidNitrogen.setPosition(randomx, -randomy);
				m_spawnLN = false;
				m_timer = false;
				m_pickupsound.play();
			}
		}
	}
	if (m_timer == true)
	{
		m_preCurrentTime = m_timeSinceGameStart;
		m_timer = false;
	}
	//spawning logic for both pickups
	if (m_timeSinceGameStart == m_preCurrentTime + 5)//generates a random number every five seconds
	{
		int random = std::rand() % 100;//generates a random number for LN
		if (random < 20)//if the random number is less than this spawn pickup
		{
			m_spawnLN = true;
		}
		int random2 = std::rand() % 100;//generates a random number for SP
		if (random2 < 20)//if the random number is less than this spawn pickup
		{
			m_spawnSP = true;
		}
		m_timer = true;
	}
	
}

