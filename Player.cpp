// Project Includes
#include "Player.h"
#include "Framework/AssetManager.h"
#include "MovingObject.h"
#include <iostream>

//constants
#define SPEED 500.0f

Player::Player()
	:MovingObject()
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/defiant.png"));
	m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));

}

void Player::Update(sf::Time _frameTime)
{
	// First, assume no keys are pressed
	m_velocity.x = 0.0f;
	m_velocity.y = 0.0f;

	// Use the keyboard function to check 
	// which keys are currently held down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_velocity.y = -SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_velocity.x = -SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_velocity.y = SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_velocity.x = SPEED;
	}

	// Call the update function manually on 
	// the parent class
	// This will actually move the character
	MovingObject::Update(_frameTime);
}


sf::Vector2f Player::GetPlayerPos()
{
	sf::Vector2f pos = m_sprite.getPosition;
	return pos;

}

float Player::GetPlayerX()
{
	float x = GetPosition.X;


}

float Player::GetPlayerY()
{



}

//void Player::Collide(GameObject& _collider)
//{
	// Only do something if the thing
	// we touched was a wall

	// Dynamic cast the GameObjec ref
	// into a Wall pointer
	// if it succeeds, it was a wall
	//Wall* wallCollider = dynamic_cast<Wall*>(&_collider);

	// If it was a wall we hit, we need to more ourselves
	// outside the wall's bounds, aka back where we were
	//if (wallCollider != nullptr)
	//{
		// We did hit a wall!!!

		// Return to our previous position that we just
		// moved away from this frame
		//m_sprite.setPosition(m_previousPosition);

		// clumsy - results in "sticky" walls
		// But good enough for this game
	//}
//}