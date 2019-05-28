#pragma once

//project includes 
#include "SpaceDisplacer.h"
#include "Asteroid.h"
#include "Torpedo.h"
#include "Player.h"
#include "Framework/AssetManager.h"


class AsteroidBelt
{

public:

	AsteroidBelt();

	//Functions
	void SetSpaceDisplacer(SpaceDisplacer* _SD);//main passes in a pointer to the space displacer object
	void SetPlayer(Player* _player);//main passes in a pointer to the player object
	void Draw(sf::RenderTarget& _target);//main passes in the render target
	void Update(sf::Time _frameTime);//main passes in the frameTime
	void SetGameTimer(int _gametime);//main passes in the time since the game screen stated
	bool IsActive();

private:

	SpaceDisplacer* m_SD;
	sf::Sound m_hit;
	Player* m_player;
	int m_NoOfAsteroidsInPlay;
	int m_timeSinceGameStart;
	std::vector< Asteroid > asteroidBelt;
	int m_difficulty;
	bool m_active;
	bool m_timer;
	bool m_timer2;
	int m_preCurrentTime;
	sf::FloatRect test;

};