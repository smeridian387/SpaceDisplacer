#pragma once

//prject includes
//#include "Enemy.h"
#include "MovingObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Torpedo.h"

class Persuit
{

public:

	Persuit();

	void SetPlayer(Player* _player);
	void SetTorpedo(Torpedo* _Torpedo);
	void Draw(sf::RenderTarget& _target);
	virtual sf::Vector2f Getplayerpos();
	sf::Vector2f GetEnemyPos(int _whichenemy);
	int GetEnemyRot(int _whichenemy);
	void Update(sf::Time _frameTime);
	void Difficulty();
	bool IsActive();

private:

	int m_numberInPersuit;
	bool m_timer;
	bool m_timer2;
	int m_preCurrentTime;
	bool m_isInPlay;
	bool m_active;
	Torpedo* m_torpedo;
	Player* m_player;
	std::vector< Enemy > persuit;

};