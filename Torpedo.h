#pragma once

#include "MovingObject.h"
#include "Framework/AssetManager.h"
#include "Player.h"
#include "Asteroid.h"

class Torpedo : public MovingObject
{

public:

	Torpedo();

	void SetPlayer(Player* _player);//main passes in a pointer to the player object
	void SetVelocitynull();//setter for velocity freezing
	void ResetVelocity();//setter for reseting velocity
	void initialize(sf::Vector2f _enemyposition);//spawn at a given location
	void Draw(sf::RenderTarget& _target);//main passes in the render target
	void Update(sf::Time _frameTime);//main passes in the frameTime
	bool GetIsActive();//getter for wheather not the torpedo is onscreen
	void SetIsActive(bool _IsActive);//setter for wheather the torpedo to despawn
	

private:

	bool ini;
	bool m_isActive;
	sf::Vector2f m_standardVelocity;
	sf::Vector2f m_bulletSpeed;
	sf::Vector2f m_direction;
	Player* m_player;
	sf::Sound m_hit;
};
