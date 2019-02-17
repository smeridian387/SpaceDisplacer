// Project Includes
#include "Player.h"
#include "Framework/AssetManager.h"

Player::Player()
	:GameObject()
	,m_move(0,0)
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/defiant.png"));


}

void Player::Input(sf::Event _gameEvent)
{
	// Read the input from the keyboard and convert it
	// to a direction to move in (and then move)

	// Was the event a key press?
	if (_gameEvent.type == sf::Event::KeyPressed)
	{
		// Yes it was a key press!

		// What key was pressed?
		if (_gameEvent.key.code == sf::Keyboard::W)
		{
			// It was W!
			// Move up
			m_move = sf::Vector2i(0, -1);
		}
		else if (_gameEvent.key.code == sf::Keyboard::A)
		{
			// It was A!
			// Move left
			m_move = sf::Vector2i(-1, 0);
		}
		else if (_gameEvent.key.code == sf::Keyboard::S)
		{
			// It was S!
			// Move down
			m_move = sf::Vector2i(0, 1);
		}
		else if (_gameEvent.key.code == sf::Keyboard::D)
		{
			// It was D!
			// Move right
			m_move = sf::Vector2i(1, 0);
		}
		else if (_gameEvent.key.code == sf::Keyboard::Space)
		{
			// It was Space!
			// Activate Space Displacer
		}
	}
}

void Player::Update(sf::Time _frameTime)
{
	
}