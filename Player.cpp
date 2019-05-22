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
	m_text.setPosition(1100.0f, 670.0f);
	m_sprite.setTexture(AssetManager::GetTexture("graphics/tempusBankLeft/tempus1.png"));
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
	m_sprite.setScale(sf::Vector2f(0.09f, 0.09f));


	Animation& playerBankLeft(m_animationSystem.CreateAnimation("Left"));
	Animation& playerBankRight(m_animationSystem.CreateAnimation("Right"));
	Animation& playerBankIdle(m_animationSystem.CreateAnimation("Idle"));

	m_animationSystem.SetSprite(m_sprite);
	//m_animationSystem.SetSprite(m_bankRight);
	//load sprite for bankleft
	for (int i = 1; i < 28; ++i)
	{
		if (i != 15)
			playerBankLeft.AddFrame((AssetManager::GetTexture("graphics/tempusBankLeft/tempus" + std::to_string(i) + ".png")));
	}
	//load sprites for bankright
	for (int i = 1; i < 28; ++i)
	{
		if (i != 15)
			playerBankRight.AddFrame((AssetManager::GetTexture("graphics/tempusBankRight/tempusR" + std::to_string(i) + ".png")));
	}

	playerBankIdle.AddFrame((AssetManager::GetTexture("graphics/tempusIdle.png")));

	//m_animationSystem.SetSprite(m_sprite);
	playerBankRight.SetPlayBackSpeed(80.0f);
	playerBankLeft.SetPlayBackSpeed(80.0f);
	m_animationSystem.Play("Idle");
}

void Player::SetHullIntegrity(int _int)
{
	m_hull = m_hull + _int;
}

int Player::GetHullIntergity()
{
	return m_hull;
}

void Player::Update(sf::Time _frameTime)
{
	m_animationSystem.Update(_frameTime);

	if (m_hull > 100)
	{
		m_hull = 100;
	}
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
		m_animationSystem.Play("Left");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && GetPosition().y < 685)
	{
		m_velocity.y = SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && GetPosition().x < 1060)
	{
		m_velocity.x = SPEED;
		m_animationSystem.Play("Right");
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_animationSystem.Play("Idle");
	}
	m_text.setString(std::to_string(m_hull)+ "%");
	//m_animationSystem.Play("Left");
	// Call the update function manually on 
	// the parent class
	// This will actually move the character
	MovingObject::Update(_frameTime);
}

void Player::Draw(sf::RenderTarget& _target)
{
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//{
		//_target.draw(m_bankLeft);
	//}
	//else
	//{
		_target.draw(m_sprite);
	//}
	_target.draw(m_text);
	
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