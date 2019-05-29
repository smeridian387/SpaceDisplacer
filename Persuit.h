#pragma once

//prject includes
//#include "Enemy.h"
#include "MovingObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Torpedo.h"
#include "SpaceDisplacer.h"
#include "Framework/AssetManager.h"

class Persuit
{

public:

	Persuit();

	void SetPlayer(Player* _player);//main passes in a pointer to the player object
	void SetTorpedo(Torpedo* _Torpedo);//main passes a pointer to torpedo object
	void SetAsteroid(Asteroid*_Asteroid);//main passes a pointer to the asteroid object
	void SetGameTimer(int _gametime);//main passes the time since the game screen started
	void SetSpaceDisplacer(SpaceDisplacer* _SD);//main passes in a pointer to the space displacer object
	void Draw(sf::RenderTarget& _target);//main passes in the render target
	sf::Vector2f GetEnemyPos(int _whichenemy);//this function is for retreaving the position of an enemy. each enemy has a number, if you pass a number it will return the position of the enemy with that number
	int GetEnemyRot(int _whichenemy);//similar to the fuction above exept retruns that enemies rotation.
	void Update(sf::Time _frameTime);//main passes in the frameTime
	bool IsActive();//getter for weather or not the perisut is active

private:

	int m_timeSinceGameStart;
	bool m_active;
	bool m_freeze;
	Torpedo* m_torpedo;
	Player* m_player;
	Asteroid* m_asteroid;
	SpaceDisplacer* m_SD;
	std::vector< Enemy > persuit;
	std::vector<Torpedo> Torpedos;
	sf::Sound m_pew;
	//timer variables
	bool m_timer;
	bool m_timer2;
	int m_preCurrentTime;
	int m_preCurrentTime1;

};