#pragma once

#include "MovingObject.h"
#include "SpaceDisplacer.h"
#include "Player.h"

class Asteroid : public MovingObject
{

public:

	Asteroid();

	//overiding Methods
	void SetSpaceDisplacer(SpaceDisplacer* _SD);//main passes in a pointer to the space displacer object
	void SetPlayer(Player* _player);//main passes in a pointer to the player object
	void SetGameTimer(int _timeSinceStart);//main passes in the time since the game screen stated
	void Update(sf::Time _frameTime);//main passes in the frameTime
	

private:

	SpaceDisplacer* m_SD;
	Player* m_player;
	sf::Vector2f m_approachSpeed;
	float m_approachSpeedY;
	int m_timeSinceGameStart;
	//timer variables
	bool m_timer;
	bool m_timer2;
	int m_preCurrentTime;
	int m_preCurrentTime2;
	

};