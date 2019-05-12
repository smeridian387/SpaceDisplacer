// Project Includes
#include "Player.h"
#include "Framework/AssetManager.h"
#include "MovingObject.h"

//constants
#define SPEED 500.0f

Player::Player()
	:MovingObject()
	, m_hull(100)
{
	m_text.setFont(AssetManager::GetFont("fonts/ethnocentric.ttf"));
	m_text.setPosition(210.0f, 670.0f);
	m_sprite.setTexture(AssetManager::GetTexture("graphics/ThunderChildC.png"));
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_sprite.setScale(sf::Vector2f(0.1f, 0.1f));
}

void Player::SetHullIntegrity(int _int)
{
	m_hull = m_hull + _int;
}

void Player::Update(sf::Time _frameTime)
{
	// First, assume no keys are pressed
	m_velocity.x = 0.0f;
	m_velocity.y = 0.0f;

	// Use the keyboard function to check 
	// which keys are currently held down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&& GetPosition().y > 30)
	{
		m_velocity.y = -SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && GetPosition().x > 220)
	{
		m_velocity.x = -SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && GetPosition().y < 685)
	{
		m_velocity.y = SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && GetPosition().x < 1060)
	{
		m_velocity.x = SPEED;
	}
	m_text.setString(std::to_string(m_hull));

	// Call the update function manually on 
	// the parent class
	// This will actually move the character
	MovingObject::Update(_frameTime);
}

void Player::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_text);
	_target.draw(m_sprite);
}

sf::Vector2f Player::GetPlayerPos()
{
	sf::Vector2f pos = GetPosition();
	return pos;

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