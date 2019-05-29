#pragma once

#include "Framework/SpriteObject.h"
#include "Player.h"

class Enemy : public SpriteObject
{

public:

	Enemy();

	void Update(sf::Time _frameTime);//main passes frameTime
	int GetRotation();//getter for enemy rotation
	bool isInPlay();//getter for wheather enemy is in play
	void SetPlayer(Player* _player);//main passes a pointer to player

private:

	bool m_isInPlay;
	Player* m_player;
	float m_enemyRotation;
};