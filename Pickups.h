#pragma once
#include "MovingObject.h"
#include "Player.h"
#include "Framework/AssetManager.h"
#include "SpaceDisplacer.h"

class PickUp : public MovingObject
{

public:

	PickUp();

	void SetPlayer(Player* _player);
	void SetSpaceDisplacer(SpaceDisplacer* _SD);
	void Update(sf::Time _frameTime);
	void Draw(sf::RenderTarget & _target);
	void SetGameTimer(int _timeSinceStart);

private:

	sf::Sound m_pickupsound;
	sf::Sprite m_spareParts;
	sf::Sprite m_liquidNitrogen;
	Player* m_player;
	SpaceDisplacer* m_SD;
	bool m_spawnSP;
	bool m_spawnLN;
	bool m_timer;
	int m_preCurrentTime;
	int m_timeSinceGameStart;
	int random;



};