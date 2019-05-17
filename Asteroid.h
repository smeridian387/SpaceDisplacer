#pragma once

#include "MovingObject.h"
#include "SpaceDisplacer.h"
#include "Player.h"

class Asteroid : public MovingObject
{

public:

	Asteroid();

	//overiding Methods
	void SetSpaceDisplacer(SpaceDisplacer* _SD);
	void SetPlayer(Player* _player);
	void SetGameTimer(int _timeSinceStart);
	void Update(sf::Time _frameTime);
	bool isInPlay();
	

private:

	SpaceDisplacer* m_SD;
	Player* m_player;
	bool m_timer;
	bool m_timer2;
	int m_preCurrentTime;
	int m_preCurrentTime2;
	sf::Vector2f m_approachSpeed;
	float m_approachSpeedY;
	int m_timeSinceGameStart;
	bool m_isInPlay;
	

};