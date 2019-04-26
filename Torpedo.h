#pragma once

#include "MovingObject.h"
#include "Player.h"

class Torpedo : public MovingObject
{

public:

	Torpedo();

	void SetPlayer(Player* _player);
	void initialize();
	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	bool GetIsActive();
	

private:

	bool ini;
	sf::Vector2f m_bulletSpeed;
	sf::Vector2f m_direction;
	bool m_isInPlay;
	Player* m_player;
};
