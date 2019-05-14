#pragma once
#include "MovingObject.h"
#include "Player.h"
#include "Framework/AssetManager.h"

class PickUp : public MovingObject
{

public:

	PickUp();

	void SetPlayer(Player* _player);
	void Update(sf::Time _frameTime);
	void Draw(sf::RenderTarget & _target);
	void SetGameTimer(int _timeSinceStart);

private:

	sf::Sprite m_spareParts;
	sf::Sprite m_liquidNitrogen;
	Player* m_player;
	bool m_spawnSP;
	bool m_spawnLN;
	bool m_timer;
	int m_preCurrentTime;
	int m_timeSinceGameStart;
	bool m_spawnSPlock;



};