#pragma once

//prject includes
//#include "Enemy.h"
#include "MovingObject.h"
#include "Player.h"
#include "Torpedo.h"

class Persuit
{

public:

	Persuit();

	void SetPlayer(Player* _player);
	void SetTorpedo(Torpedo* _torpedo);
	void Draw(sf::RenderTarget& _target);
	virtual sf::Vector2f Getplayerpos();
	void Update(sf::Time _frameTime);
	void Difficulty();
	bool IsActive();

private:

	int m_numberInPersuit;
	std::vector< Enemy > persuit;
	bool m_isInPlay;
	bool m_active;
	Player* m_player;
	Torpedo* m_torpedo;

};