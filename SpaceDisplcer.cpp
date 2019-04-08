#include "SpaceDisplacer.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <time.h>

SpaceDisplacer::SpaceDisplacer()
	:m_temp(0)
	, m_SDcasing(100)
	, m_SDactive(false)
	, m_SDfunctional(true)
	, m_timer(true)
	, m_preCurrentTime()
{


}

void SpaceDisplacer::Update(sf::Time _frameTime)
{
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
			m_temp = m_temp++;
				m_timer = true;
			std::cout << m_temp << std::endl;
		}
	}
	else
	{
		m_timer = true;
	}

	m_SDactive = false;
	
}