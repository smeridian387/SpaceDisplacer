#pragma once

#include "MovingObject.h"
#include "Player.h"

class Torpedo : public MovingObject
{

public:

	Torpedo();

	void SetPlayer(Player* _player);
	void initialize(sf::Vector2f _enemyposition);
	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	bool GetIsActive();
	void SetIsActive(bool _IsActive);
	

private:

	bool ini;
	bool m_isActive;
	sf::Vector2f m_bulletSpeed;
	sf::Vector2f m_direction;
	Player* m_player;
};
