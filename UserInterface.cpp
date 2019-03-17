#include "UserInterface.h"
#include "Framework/AssetManager.h"


UserInterface::UserInterface()
{

	m_sprite.setTexture(AssetManager::GetTexture("graphics/UI.png"));
	m_sprite.setPosition(sf::Vector2f(0, 0));
}