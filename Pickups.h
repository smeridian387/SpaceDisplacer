#pragma once
#include "MovingObject.h"
#include "Player.h"
#include "Framework/AssetManager.h"
#include "SpaceDisplacer.h"

class PickUp : public MovingObject
{

public:

	PickUp();

	void SetPlayer(Player* _player);//main passes in a pointer to the player object
	void SetSpaceDisplacer(SpaceDisplacer* _SD);//main passes in a pointer to the space displacer object
	void Update(sf::Time _frameTime);//main passes in the frameTime
	void Draw(sf::RenderTarget & _target);//main passes in the render target
	void SetGameTimer(int _timeSinceStart);//main passes in the time since the game screen stated

private:

	sf::Sound m_pickupsound;
	sf::Sprite m_spareParts;
	sf::Sprite m_liquidNitrogen;
	Player* m_player;
	SpaceDisplacer* m_SD;
	bool m_spawnSP;
	bool m_spawnLN;
	int m_timeSinceGameStart;
	int random;
	//timer variables
	bool m_timer;
	int m_preCurrentTime;


};