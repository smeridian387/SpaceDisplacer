#pragma once

#include "MovingObject.h"
#include "Player.h"

class Enemy : public MovingObject
{

public:

	Enemy();

	void Update(sf::Time _frameTime);
	bool isInPlay();
	//void SetPersuit(Persuit* _persuit);
	void SetPlayer(Player* _player);
private:

	bool m_isInPlay;
	//Persuit* m_persuit;
	Player* m_player;
};