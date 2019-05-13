#pragma once

#include "MovingObject.h"
#include "Framework/AssetManager.h"
#include "Player.h"
#include "AsteroidBelt.h"
#include "Asteroid.h"

class Torpedo : public MovingObject
{

public:

	Torpedo();

	void SetPlayer(Player* _player);
	void SetVelocitynull();
	void ResetVelocity();
	void initialize(sf::Vector2f _enemyposition);
	void Draw(sf::RenderTarget& _target);
	void Update(sf::Time _frameTime);
	bool GetIsActive();
	void SetIsActive(bool _IsActive);
	

private:

	bool ini;
	bool m_isActive;
	sf::Vector2f m_standardVelocity;
	sf::Vector2f m_bulletSpeed;
	sf::Vector2f m_direction;
	Player* m_player;
	sf::Sound m_hit;
};
