#include "SpaceDisplacer.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <time.h>
#include "Framework/TextObject.h"
#include "Framework/AssetManager.h"

SpaceDisplacer::SpaceDisplacer()
	:m_temp(0)
	, m_active(true)
	, m_SDcasing(100)
	, m_SDactive(false)
	, m_SDfunctional(true)
	, m_timer(true)
	, m_timer2(true)
	, m_preCurrentTime()
	, m_sprite()
	, m_animation()
	, m_SDcolorchange(0)
	, m_idleSD(m_animation.CreateAnimation("idle"))
{
	m_text.setFont(AssetManager::GetFont("fonts/ethnocentric.ttf"));
	m_text.setPosition(110.0f, 670.0f);
	m_animation.SetSprite(m_sprite);
	//Animation& m_idleSD = m_animation.CreateAnimation("idle");
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop000.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop001.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop002.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop003.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop004.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop005.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop006.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop007.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop008.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop009.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop010.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop011.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop012.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop013.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop014.png")));
	m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop015.png")));
	m_idleSD.SetLoop(true);
	m_sprite.setPosition(69.0f, 91.0f);
	m_animation.Play("idle");
}

void SpaceDisplacer::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_text);
	_target.draw(m_sprite);
}



void SpaceDisplacer::Update(sf::Time _frameTime)
{
	m_animation.Update(_frameTime);//plays spacedisplacer animation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		time_t time1;
		if (m_timer == true)
		{
			m_preCurrentTime = time(&time1);
			m_timer = false;
		}
		if (time(&time1) == m_preCurrentTime + 1)
		{
			m_temp = m_temp + 25;
				m_timer = true;
			std::cout << m_temp << std::endl;
		}
		m_idleSD.SetPlayBackSpeed(25.0f);
		m_SDcolorchange = m_temp;
		if (m_temp >= 199)
		{
			m_SDcolorchange = 199;
		}
		m_sprite.setColor(sf::Color(200, (200-m_SDcolorchange), (200-m_SDcolorchange), 255));
		m_SDactive = true;
	}
	else
	{
		m_timer = true;
		m_idleSD.SetPlayBackSpeed(15.0f);
		m_SDactive = false;
		
	}
	if (m_temp > 0 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		time_t time1;
		if (m_timer2 == true)
		{
			m_preCurrentTime = time(&time1);
			m_timer2 = false;
		}
		if (time(&time1) == m_preCurrentTime + 1)
		{
			if (m_temp == 5)
			{
				m_temp = m_temp - 5;
			}
			else 
			{
				m_temp = m_temp - 10;
			}
			m_timer2 = true;
			std::cout << m_temp << std::endl;
		}
		m_SDcolorchange = m_temp;
		if (m_temp >= 199)
		{
			m_SDcolorchange = 199;
		}
		m_sprite.setColor(sf::Color(200, (200 - m_SDcolorchange), (200 - m_SDcolorchange), 255));
	}
	else
	{
		m_timer2 = true;
	}
	//m_SDactive = false;
	m_text.setString(std::to_string(m_temp) + "°");
}

bool SpaceDisplacer::SDActive()
{
	return m_SDactive;
}

bool SpaceDisplacer::IsActive()
{
	return m_active;
}

