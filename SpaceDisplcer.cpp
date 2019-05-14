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
	, m_warnRectIn(700.0f)
	, m_idleSD(m_animation.CreateAnimation("idle"))
{
	m_SDtempText.setFont(AssetManager::GetFont("fonts/ethnocentric.ttf"));
	m_SDtempText.setPosition(110.0f, 670.0f);
	m_SDcasingText.setFont(AssetManager::GetFont("fonts/ethnocentric.ttf"));
	m_SDcasingText.setPosition(70.0f, 190.0f);
	m_animation.SetSprite(m_sprite);
	m_warningRect.setTexture(AssetManager::GetTexture("graphics/WarningRect.png"));
	m_warningRect.setOrigin(m_warningRect.getTextureRect().width / 2, m_warningRect.getTextureRect().height / 2);
	m_warningRect.setScale(sf::Vector2f(0.2f, 0.3f));
	//m_warningRect.setPosition(45.0f, 700.0f);//bottom position
	m_warningRect.setPosition(45.0f, 700.0f);//top position
	for (int i = 0; i < 15; ++i)
	{
		m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop00" + std::to_string(i) +".png")));
	}
	m_idleSD.SetLoop(true);
	m_sprite.setPosition(69.0f, 91.0f);
	m_animation.Play("idle");
}

void SpaceDisplacer::Draw(sf::RenderTarget& _target)
{
	
	if (m_SDcasing > 0)
	{
		_target.draw(m_sprite);
		_target.draw(m_warningRect);
	}
	_target.draw(m_SDcasingText);
	_target.draw(m_SDtempText);
}

void SpaceDisplacer::Update(sf::Time _frameTime)
{
	m_animation.Update(_frameTime);//plays spacedisplacer animation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&m_SDcasing >0)
	{
		
		time_t time1;
		if (m_timer == true)
		{
			m_preCurrentTime = time(&time1);
			m_timer = false;
		}
		if (time(&time1) == m_preCurrentTime + 1)
		{
			m_temp = m_temp + 40;
			m_warningRect.setPosition(45.0f,m_warningRect.getPosition().y - 76.01f);
			if (m_temp > 150)
			{
				m_SDcasing = m_SDcasing - 10;
			}
			m_timer = true;
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
			if (m_temp > 150)
			{
				m_SDcasing = m_SDcasing - 10;
			}
			m_warningRect.setPosition(45.0f, m_warningRect.getPosition().y + 9.49f);
			if (m_temp == 5)
			{
				m_temp = m_temp - 5;
			}
			else 
			{
				m_temp = m_temp - 5;
			}
			m_timer2 = true;
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
	if (m_SDcasing <= 0)
	{
		m_SDcasingText.setString("NA");
		m_SDtempText.setString("NA");
	}
	else
	{
		m_SDtempText.setString(std::to_string(m_temp) + "°");
		m_SDcasingText.setString(std::to_string(m_SDcasing));
	}
}

bool SpaceDisplacer::SDActive()
{
	return m_SDactive;
}

bool SpaceDisplacer::IsActive()
{
	return m_active;
}

