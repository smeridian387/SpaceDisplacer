#pragma once

//prject includes
//#include "Enemy.h"
#include "MovingObject.h"
#include "Player.h"
#include "Enemy.h"

class Persuit
{

public:

	Persuit();

	void SetPlayer(Player* _player);
	void Draw(sf::RenderTarget& _target);
	virtual sf::Vector2f Getplayerpos();
	sf::Vector2f GetEnemyPos(int _whichenemy);
	int GetEnemyRot(int _whichenemy);
	void Update(sf::Time _frameTime);
	void Difficulty();
	bool IsActive();

private:

	int m_numberInPersuit;
	bool m_isInPlay;
	bool m_active;
	Player* m_player;
	std::vector< Enemy > persuit;

};