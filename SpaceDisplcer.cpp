#include "SpaceDisplacer.h"
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
	, m_timer3(true)
	, m_timer4(false)
	, m_overHeating()
	, m_preCurrentTime()
	, m_preCurrentTime2()
	, m_preCurrentTime3()
	, m_animation()
	, m_SDcolorchange(0)
	, m_warnRectIn(700.0f)
	, m_LNPickUp(0)
	, m_idleSD(m_animation.CreateAnimation("idle"))
	, m_mainmenuActive()
{
	m_SDtempText.setFont(AssetManager::GetFont("fonts/ethnocentric.ttf"));
	m_SDtempText.setPosition(110.0f, 670.0f);

	m_SDcasingText.setFont(AssetManager::GetFont("fonts/ethnocentric.ttf"));
	m_SDcasingText.setPosition(70.0f, 190.0f);

	m_animation.SetSprite(m_sprite);

	m_warningRect.setTexture(AssetManager::GetTexture("graphics/WarningRect.png"));
	m_warningRect.setOrigin(m_warningRect.getTextureRect().width / 2, m_warningRect.getTextureRect().height / 2);

	m_warningRect.setScale(sf::Vector2f(0.2f, 0.3f));
	m_warningRect.setPosition(45.0f, 700.0f);

	m_lights.setTexture(AssetManager::GetTexture("graphics/light.png"));
	m_lights.setPosition(640.0f,20.0f);
	m_lights.setScale(sf::Vector2f(0.659f, 0.659f));
	m_lights.setOrigin(m_lights.getTextureRect().width / 2, m_lights.getTextureRect().height / 2);

	m_lightFilter.setTexture(AssetManager::GetTexture("graphics/lightfliter.png"));

	for (int i = 0; i < 15; ++i)//for loop for loading space displacer animation
	{
		m_idleSD.AddFrame((AssetManager::GetTexture("graphics/idleSD/crystalballV001effect-loop00" + std::to_string(i) +".png")));
	}
	m_idleSD.SetLoop(true);
	m_sprite.setPosition(69.0f, 91.0f);
	m_animation.Play("idle");
}

void SpaceDisplacer::IsMainMenuActive(bool _mainmenu)
{
	m_mainmenuActive = _mainmenu;
}

void SpaceDisplacer::Draw(sf::RenderTarget& _target)
{
	if (m_mainmenuActive == false)
	{
		if (m_SDcasing > 0)
		{
			_target.draw(m_sprite);
			_target.draw(m_warningRect);
		}
	}
	_target.draw(m_SDcasingText);
	_target.draw(m_SDtempText);
	if (m_SDfunctional == true)
	{
		if (m_overHeating == true)
		{
				_target.draw(m_lightFilter);
				_target.draw(m_lights);
		}
	}
	
}

void SpaceDisplacer::SetSDTemp(int _newTemp)
{
	m_temp = m_temp + _newTemp;
}

void SpaceDisplacer::LNWarningMove()
{
	m_LNPickUp = 151.84;
	m_warningRect.setPosition(m_warningRect.getPosition().x, m_warningRect.getPosition().y + 151.84);
}

void SpaceDisplacer::Update(sf::Time _frameTime)
{

	if (m_temp < 0)//temperature cap
	{
		m_temp = 0;
	}
	if (m_temp == 0)
	{
		m_warningRect.setPosition(45.0f, 700.0f);
	}
	if (m_warningRect.getPosition().y < 415.0F)
	{
		m_warningRect.setPosition(45.0f, 415.0f);
	}
	m_animation.Update(_frameTime);//plays spacedisplacer animation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&m_SDcasing >0)//activates the space displacer which increases temp over time
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
	if (m_temp > 0 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space))//if the space disaplcer is not active cool down
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
			if (m_temp < 150)
			{
				m_warningRect.setPosition(45.0f, m_warningRect.getPosition().y + 9.49f);
			}
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
	m_LNPickUp = 0;
	
	if (m_temp > 150)
	{
		m_overHeating = true;
		time_t time3;
		if (m_timer3 == true)
		{
			m_overHeating = true;
			m_preCurrentTime = time(&time3);
			m_timer3 = false;
		}
		if (time(&time3) == m_preCurrentTime + 1)
		{
			m_overHeating = false;
			m_timer4 = true;
		}
		time_t time2;
		if (m_timer4 == true)
		{
			m_preCurrentTime2 = time(&time2);
			m_timer4 = false;
		}
		if (time(&time2) == m_preCurrentTime2 + 1)
		{
			m_timer3 = true;
			m_timer4 = true;
		}
	}
	else
	{
		m_overHeating = false;
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

