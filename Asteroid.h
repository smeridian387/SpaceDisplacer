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
	void Update(sf::Time _frameTime);
	bool isInPlay();
	void Difficulty();
	

private:

	SpaceDisplacer* m_SD;
	Player* m_player;
	bool m_timer;
	int m_preCurrentTime;
	int m_aproachSpeed;
	bool m_isInPlay;
	sf::Vector2f m_velocity;
	

};